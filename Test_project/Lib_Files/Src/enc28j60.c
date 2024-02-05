
/**
  ******************************************************************************
  * @file           : enc28j60.c
  * @brief          : ENC28J60 driver
  * @author         : MicroTechnics (microtechnics.ru)
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "enc28j60.h"
#include "spi.h"

uint8_t macAddr[MAC_ADDRESS_BYTES_SIZE] = {0x00, 0x17, 0x22, 0xED, 0xA5, 0x01};
static ENC28J60_RegBank curBank = BANK_0;

/*----------------------------------------------------------------------------*/
void ENC28J60_Init()
{
  HAL_GPIO_WritePin(ENC28J60_RESET_PORT, ENC28J60_RESET_PIN, GPIO_PIN_SET);
  HAL_Delay(50);
  HAL_GPIO_WritePin(ENC28J60_RESET_PORT, ENC28J60_RESET_PIN, GPIO_PIN_SET);
  HAL_Delay(50);
	
	SystemReset();
	
	ReadControlReg(MISTAT);
	// Step 1 MACON1
	//WriteControlRegPair();
	// Step 9 MAADR
	// Step 9 MAADR
	// Step 9 MAADR
	// Step 9 MAADR
	// Step 9 MAADR
	// Step 9 MAADR
	// Step 9 MAADR
	// Step 9 MAADR
	// Step 9 MAADR
	WriteControlReg(MAADR1, macAddr[0]);
	WriteControlReg(MAADR2, macAddr[1]);
	WriteControlReg(MAADR3, macAddr[2]);
	WriteControlReg(MAADR4, macAddr[3]);
	WriteControlReg(MAADR5, macAddr[4]);
	WriteControlReg(MAADR6, macAddr[5]);

}
/*----------------------------------------------------------------------------*/
static uint16_t ReadControlRegPair(uint8_t Reg)
{
	return (uint16_t) ReadControlReg(Reg) | ((uint16_t) ReadControlReg(Reg + 1) << 8);
}
/*----------------------------------------------------------------------------*/
static void WriteControlRegPair(uint8_t Reg, uint16_t Data)
{
	WriteControlReg(Reg, Data);
	WriteControlReg(Reg + 1, Data >> 8);
}
/*----------------------------------------------------------------------------*/
static uint8_t ReadControlReg(uint8_t Reg)
{
	uint8_t Data = 0;
	ENC28J60_RegType RegType = GetRegType(Reg);
	uint8_t RegAddr = GetRegAddr(Reg);
	
	CheckBank(Reg);
	
	CS_LOW();
	WriteCommand(READ_CONTROL_REG, RegAddr);

	if(RegType == MAC_MII_REG)
	{
		ReadByte();
	}
	
	Data = ReadByte();
	CS_HIGH();
	
	return Data;
}
/*----------------------------------------------------------------------------*/
static void WriteControlReg(uint8_t Reg, uint8_t Data)
{
	uint8_t RegAddr = GetRegAddr(Reg);
	CheckBank(Reg);
	
	CS_LOW();
	WriteCommand(WRITE_CONTROL_REG, RegAddr);
	WriteByte(Data);
	CS_HIGH();
}
/*----------------------------------------------------------------------------*/
static void CheckBank(uint8_t Reg)
{
	uint8_t RegAddr = GetRegAddr(Reg);
	if (RegAddr < ENC28J60_COMMON_REGS_ADDR)
	{
		ENC28J60_RegBank RegBank = GetRegBank(Reg);
		
		if (RegBank != curBank)
		{
			uint8_t ECON1Addr = GetRegAddr(ECON1);
		
			CS_LOW();
			WriteCommand(BIT_FIELD_CLEAR, ECON1Addr);
			WriteByte(ECON1_BSEL1_BIT | ECON1_BSEL0_BIT);
			CS_HIGH();
			
			CS_LOW();
			WriteCommand(BIT_FIELD_SET, ECON1Addr);
			WriteByte(RegBank);
			CS_HIGH();
			
			curBank = RegBank;
		}
	}
}
/*----------------------------------------------------------------------------*/
static void SystemReset()
{
	CS_LOW();
	WriteCommand(SYSTEM_RESET, ENC28J60_RESET_COMMAND_ARG);
	CS_HIGH();
	
	curBank = BANK_0;
}
/*----------------------------------------------------------------------------*/
static void WriteCommand(ENC28J60_RegCommand Command, uint8_t RegAddr)
{
	uint8_t data = 0;
  data = (Command << ENC28J60_OP_CODE_OFFSET) | RegAddr;
	WriteByte(data);
}
/*----------------------------------------------------------------------------*/
static ENC28J60_RegType GetRegType(uint8_t Reg)
{
	return  (ENC28J60_RegType)((Reg & ENC28J60_REG_TYPE_MASK) >> ENC28J60_REG_TYPE_OFFSET);
}
/*----------------------------------------------------------------------------*/
static ENC28J60_RegBank GetRegBank(uint8_t Reg)
{
	return  (ENC28J60_RegBank)((Reg & ENC28J60_REG_BANK_MASK) >> ENC28J60_REG_BANK_OFFSET);
}
/*----------------------------------------------------------------------------*/
static uint8_t GetRegAddr(uint8_t Reg)
{
	return  Reg & ENC28J60_REG_ADDR_MASK;
}
/*----------------------------------------------------------------------------*/
static uint8_t ReadByte()
{
	uint8_t TxData = 0;
	uint8_t RxData = 0;
	HAL_SPI_TransmitReceive(&hspi1, &TxData, &RxData, 1, ENC28J60_SPI_TIMEOUT);
	return RxData;
}
/*----------------------------------------------------------------------------*/
static void WriteByte(uint8_t TxData)
{
	HAL_SPI_Transmit(&hspi1, &TxData, 1, ENC28J60_SPI_TIMEOUT);
}
/*----------------------------------------------------------------------------*/
static void CS_LOW()
{
	HAL_GPIO_WritePin(ENC28J60_CS_PORT, ENC28J60_CS_PIN, GPIO_PIN_RESET);
}
/*----------------------------------------------------------------------------*/
static void CS_HIGH()
{
	HAL_GPIO_WritePin(ENC28J60_CS_PORT, ENC28J60_CS_PIN, GPIO_PIN_SET);
}
/*----------------------------------------------------------------------------*/
