/**
  ******************************************************************************
  * @file           : enc28j60.h
  * @brief          : ENC28J60 driver interface
  * @author         : MicroTechnics (microtechnics.ru)
  ******************************************************************************
  */
#ifndef ENC28J60_H
#define ENC28J60_H
/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"
/* Declarations and definitions ----------------------------------------------*/

#define ENC28J60_CS_PORT						GPIOA
#define ENC28J60_CS_PIN							GPIO_PIN_4

#define ENC28J60_RESET_PORT					GPIOA
#define ENC28J60_RESET_PIN					GPIO_PIN_3

#define MAC_ADDRESS_BYTES_SIZE			6

#define ENC28J60_SPI_TIMEOUT				10

#define ENC28J60_REG_TYPE_OFFSET 		7
#define ENC28J60_REG_BANK_OFFSET 		5
#define ENC28J60_OP_CODE_OFFSET			5

#define ENC28J60_RESET_COMMAND_ARG  0x1F
	
#define ENC28J60_ETHERNET_REG_BIT 	(ETHERNET_REG << ENC28J60_REG_TYPE_OFFSET)
#define ENC28J60_MAC_MII_REG_BIT		(MAC_MII_REG << ENC28J60_REG_TYPE_OFFSET)
	
#define ENC28J60_COMMON_REGS_ADDR   0x1B	
	
#define ENC28J60_REG_TYPE_MASK 			0x80
#define ENC28J60_REG_BANK_MASK			0x60
#define	ENC28J60_REG_ADDR_MASK			0x1F
	
#define ENC28J60_BANK_0_BITS 				(BANK_0 << ENC28J60_REG_BANK_OFFSET)
#define ENC28J60_BANK_1_BITS 				(BANK_ << ENC28J60_REG_BANK_OFFSET)
#define	ENC28J60_BANK_2_BITS 				(BANK_2 << ENC28J60_REG_BANK_OFFSET)
#define	ENC28J60_BANK_3_BITS 				(BANK_3 << ENC28J60_REG_BANK_OFFSET)
	
//ENC28J0 Common control registers	
	
#define EIE													(0x1B | ENC28J60_BANK_0_BITS | ENC28J60_ETHERNET_REG_BIT)

#define EIR_PKTIF_BIT               (1 << 6)
#define EIR_DMAIF_BIT               (1 << 5)
#define EIR_LINKIF_BIT              (1 << 4)
#define EIR_TXIF_BIT                (1 << 3)
#define EIR_TXERIF_BIT              (1 << 1)
#define EIR_RXERIF_BIT              (1 << 0)

#define EIR													(0x1C | ENC28J60_BANK_0_BITS | ENC28J60_ETHERNET_REG_BIT)
#define ESTAT												(0x1D | ENC28J60_BANK_0_BITS | ENC28J60_ETHERNET_REG_BIT)
#define ECON2												(0x1E | ENC28J60_BANK_0_BITS | ENC28J60_ETHERNET_REG_BIT)

#define ECON2_AUTOINC_BIT           (1 << 7)
#define ECON2_PKTDEC_BIT            (1 << 6)
#define ECON2_PWRSV_BIT             (1 << 5)
#define ECON2_VRPS_BIT              (1 << 3)

#define ECON1												(0x1F | ENC28J60_BANK_0_BITS | ENC28J60_ETHERNET_REG_BIT)

#define ECON1_TXRST_BIT            	(1 << 7)
#define ECON1_RXRST_BIT            	(1 << 6)
#define ECON1_DMAST_BIT            	(1 << 5)
#define ECON1_CSUMEN_BIT           	(1 << 4)
#define ECON1_TXRTS_BIT            	(1 << 3)
#define ECON1_RXEN_BIT             	(1 << 2)
#define ECON1_BSEL1_BIT            	(1 << 1)
#define ECON1_BSEL0_BIT            	(1 << 0)
	
//ENC28J0 Bank_0 control registers	
	
#define ERDPTL											(0x00 | ENC28J60_BANK_0_BITS | ENC28J60_ETHERNET_REG_BIT)
#define ERDPTH											(0x01 | ENC28J60_BANK_0_BITS | ENC28J60_ETHERNET_REG_BIT)
	
#define EWRPTL											(0x02 | ENC28J60_BANK_0_BITS | ENC28J60_ETHERNET_REG_BIT)
#define EWRPTH											(0x03 | ENC28J60_BANK_0_BITS | ENC28J60_ETHERNET_REG_BIT)
	
#define ETXSTL											(0x04 | ENC28J60_BANK_0_BITS | ENC28J60_ETHERNET_REG_BIT)
#define ETXSTH											(0x05 | ENC28J60_BANK_0_BITS | ENC28J60_ETHERNET_REG_BIT)
	
#define ETXNDL											(0x06 | ENC28J60_BANK_0_BITS | ENC28J60_ETHERNET_REG_BIT)
#define ETXNDH											(0x07 | ENC28J60_BANK_0_BITS | ENC28J60_ETHERNET_REG_BIT)
	
#define ERXSTL											(0x08 | ENC28J60_BANK_0_BITS | ENC28J60_ETHERNET_REG_BIT)
#define ERXSTH											(0x09 | ENC28J60_BANK_0_BITS | ENC28J60_ETHERNET_REG_BIT)
	
#define ERXNDL											(0x0A | ENC28J60_BANK_0_BITS | ENC28J60_ETHERNET_REG_BIT)
#define ERXNDH											(0x0B | ENC28J60_BANK_0_BITS | ENC28J60_ETHERNET_REG_BIT)
	
#define ERXRDPTL										(0x0C | ENC28J60_BANK_0_BITS | ENC28J60_ETHERNET_REG_BIT)
#define ERXRDPTH										(0x0D | ENC28J60_BANK_0_BITS | ENC28J60_ETHERNET_REG_BIT)
	
#define ERXWRPTL										(0x0E | ENC28J60_BANK_0_BITS | ENC28J60_ETHERNET_REG_BIT)
#define ERXWRPTH										(0x0F | ENC28J60_BANK_0_BITS | ENC28J60_ETHERNET_REG_BIT)
	
#define EDMASTL											(0x10 | ENC28J60_BANK_0_BITS | ENC28J60_ETHERNET_REG_BIT)
#define EDMASTH											(0x11 | ENC28J60_BANK_0_BITS | ENC28J60_ETHERNET_REG_BIT)
	
#define EDMANDL											(0x12 | ENC28J60_BANK_0_BITS | ENC28J60_ETHERNET_REG_BIT)
#define EDMANDH											(0x13 | ENC28J60_BANK_0_BITS | ENC28J60_ETHERNET_REG_BIT)
	
#define EDMDSTL											(0x14 | ENC28J60_BANK_0_BITS | ENC28J60_ETHERNET_REG_BIT)
#define EDMDSTH											(0x15 | ENC28J60_BANK_0_BITS | ENC28J60_ETHERNET_REG_BIT)
	
#define EDMACSL											(0x16 | ENC28J60_BANK_0_BITS | ENC28J60_ETHERNET_REG_BIT)
#define EDMACSH											(0x17 | ENC28J60_BANK_0_BITS | ENC28J60_ETHERNET_REG_BIT)
	
//ENC28J0 Bank_1 control registers	
	
#define EHT0												(0x00 | ENC28J60_BANK_1_BITS | ENC28J60_ETHERNET_REG_BIT)
#define EHT1												(0x01 | ENC28J60_BANK_1_BITS | ENC28J60_ETHERNET_REG_BIT)																						
#define EHT2												(0x02 | ENC28J60_BANK_1_BITS | ENC28J60_ETHERNET_REG_BIT)
#define EHT3												(0x03 | ENC28J60_BANK_1_BITS | ENC28J60_ETHERNET_REG_BIT)																									
#define EHT4												(0x04 | ENC28J60_BANK_1_BITS | ENC28J60_ETHERNET_REG_BIT)
#define EHT5												(0x05 | ENC28J60_BANK_1_BITS | ENC28J60_ETHERNET_REG_BIT)																											
#define EHT6												(0x06 | ENC28J60_BANK_1_BITS | ENC28J60_ETHERNET_REG_BIT)
#define EHT7												(0x07 | ENC28J60_BANK_1_BITS | ENC28J60_ETHERNET_REG_BIT)		
		
#define EPMM0												(0x08 | ENC28J60_BANK_1_BITS | ENC28J60_ETHERNET_REG_BIT)
#define EPMM1												(0x09 | ENC28J60_BANK_1_BITS | ENC28J60_ETHERNET_REG_BIT)																												
#define EPMM2												(0x0A | ENC28J60_BANK_1_BITS | ENC28J60_ETHERNET_REG_BIT)
#define EPMM3												(0x0B | ENC28J60_BANK_1_BITS | ENC28J60_ETHERNET_REG_BIT)																												
#define EPMM4												(0x0C | ENC28J60_BANK_1_BITS | ENC28J60_ETHERNET_REG_BIT)
#define EPMM5												(0x0D | ENC28J60_BANK_1_BITS | ENC28J60_ETHERNET_REG_BIT)																											
#define EPMM6												(0x0E | ENC28J60_BANK_1_BITS | ENC28J60_ETHERNET_REG_BIT)
#define EPMM7												(0x0F | ENC28J60_BANK_1_BITS | ENC28J60_ETHERNET_REG_BIT)	
	
#define EPMCSL											(0x10 | ENC28J60_BANK_1_BITS | ENC28J60_ETHERNET_REG_BIT)
#define EPMCSH											(0x11 | ENC28J60_BANK_1_BITS | ENC28J60_ETHERNET_REG_BIT)	
	
#define EPMOL												(0x14 | ENC28J60_BANK_1_BITS | ENC28J60_ETHERNET_REG_BIT)
#define EPMOH												(0x15 | ENC28J60_BANK_1_BITS | ENC28J60_ETHERNET_REG_BIT)	
	
#define ERXFCON											(0x18 | ENC28J60_BANK_1_BITS | ENC28J60_ETHERNET_REG_BIT)
#define EPKTCNT											(0x19 | ENC28J60_BANK_1_BITS | ENC28J60_ETHERNET_REG_BIT)																												
	
//ENC28J0 Bank_2 control registers	
	
#define MACON1											(0x00 | ENC28J60_BANK_2_BITS | ENC28J60_MAC_MII_REG_BIT)

#define MACON1_TXPAUS_BIT           (1 << 3)
#define MACON1_RXPAUS_BIT           (1 << 2)
#define MACON1_PASSALL_BIT          (1 << 1)
#define MACON1_MARXEN_BIT           (1 << 0)

#define MACON3											(0x02 | ENC28J60_BANK_2_BITS | ENC28J60_MAC_MII_REG_BIT)		

#define MACON3_PADCFG2_BIT          (1 << 7)
#define MACON3_PADCFG1_BIT          (1 << 6)
#define MACON3_PADCFG0_BIT          (1 << 5)
#define MACON3_TXCRCEN_BIT          (1 << 4)
#define MACON3_PHDRLEN_BIT          (1 << 3)
#define MACON3_HFRMEN_BIT           (1 << 2)
#define MACON3_FRMLNEN_BIT          (1 << 1)
#define MACON3_FULDPX_BIT           (1 << 0)

#define MACON4											(0x03 | ENC28J60_BANK_2_BITS | ENC28J60_MAC_MII_REG_BIT)
	
#define MABBIPG											(0x04 | ENC28J60_BANK_2_BITS | ENC28J60_MAC_MII_REG_BIT)	
	
#define MAIPGL											(0x06 | ENC28J60_BANK_2_BITS | ENC28J60_MAC_MII_REG_BIT)
#define MAIPGH											(0x07 | ENC28J60_BANK_2_BITS | ENC28J60_MAC_MII_REG_BIT)	
	
#define MACLON1											(0x08 | ENC28J60_BANK_2_BITS | ENC28J60_MAC_MII_REG_BIT)
#define MACLON2											(0x09 | ENC28J60_BANK_2_BITS | ENC28J60_MAC_MII_REG_BIT)		
		
#define MAMXFLL											(0x0A | ENC28J60_BANK_2_BITS | ENC28J60_MAC_MII_REG_BIT)
#define MAMXFLH											(0x0B | ENC28J60_BANK_2_BITS | ENC28J60_MAC_MII_REG_BIT)
	
#define MICMD												(0x12 | ENC28J60_BANK_2_BITS | ENC28J60_MAC_MII_REG_BIT)
	
#define MIREGADR										(0x14 | ENC28J60_BANK_2_BITS | ENC28J60_MAC_MII_REG_BIT)
	
#define MIWRL												(0x16 | ENC28J60_BANK_2_BITS | ENC28J60_MAC_MII_REG_BIT)																												
#define MIWRH												(0x17 | ENC28J60_BANK_2_BITS | ENC28J60_MAC_MII_REG_BIT)
		
#define MIRDL												(0x18 | ENC28J60_BANK_2_BITS | ENC28J60_MAC_MII_REG_BIT)																											
#define MIRDH												(0x19 | ENC28J60_BANK_2_BITS | ENC28J60_MAC_MII_REG_BIT)
	
//ENC28J0 Bank_3 control registers	
	
#define MAADR5											(0x00 | ENC28J60_BANK_3_BITS | ENC28J60_MAC_MII_REG_BIT)
#define MAADR6											(0x01 | ENC28J60_BANK_3_BITS | ENC28J60_MAC_MII_REG_BIT)																						
#define MAADR3											(0x02 | ENC28J60_BANK_3_BITS | ENC28J60_MAC_MII_REG_BIT)
#define MAADR4											(0x03 | ENC28J60_BANK_3_BITS | ENC28J60_MAC_MII_REG_BIT)	
#define MAADR1											(0x04 | ENC28J60_BANK_3_BITS | ENC28J60_MAC_MII_REG_BIT)
#define MAADR2											(0x05 | ENC28J60_BANK_3_BITS | ENC28J60_MAC_MII_REG_BIT)	
	
#define EBSTSD											(0x06 | ENC28J60_BANK_3_BITS | ENC28J60_ETHERNET_REG_BIT)
#define EBSTCON											(0x07 | ENC28J60_BANK_3_BITS | ENC28J60_ETHERNET_REG_BIT)		
		
#define EBSTCSTL										(0x08 | ENC28J60_BANK_3_BITS | ENC28J60_ETHERNET_REG_BIT)
#define EBSTCSTH										(0x09 | ENC28J60_BANK_3_BITS | ENC28J60_ETHERNET_REG_BIT)
	
#define MISTAT											(0x0A | ENC28J60_BANK_3_BITS | ENC28J60_MAC_MII_REG_BIT)
	
#define EREVID											(0x12 | ENC28J60_BANK_3_BITS | ENC28J60_ETHERNET_REG_BIT)
	
#define ECOCON											(0x15 | ENC28J60_BANK_3_BITS | ENC28J60_ETHERNET_REG_BIT)																												
#define EFLOCON											(0x17 | ENC28J60_BANK_3_BITS | ENC28J60_ETHERNET_REG_BIT)
		
#define EPAUSL											(0x18 | ENC28J60_BANK_3_BITS | ENC28J60_ETHERNET_REG_BIT)																											
#define EPAUSH											(0x19 | ENC28J60_BANK_3_BITS | ENC28J60_ETHERNET_REG_BIT)

typedef enum
{
	ETHERNET_REG,
	MAC_MII_REG,
}ENC28J60_RegType;

typedef enum 
{
	BANK_0,
	BANK_1,
	BANK_2,
	BANK_3,
}ENC28J60_RegBank;

typedef enum 
{
	READ_CONTROL_REG,
	READ_BUFFER_MEM,
	WRITE_CONTROL_REG,
	WRITE_BUFFER_MEM,
	BIT_FIELD_SET,
	BIT_FIELD_CLEAR,
	SYSTEM_RESET,
}ENC28J60_RegCommand;

void ENC28J60_Init();
static uint16_t ReadControlRegPair(uint8_t Reg);
static void WriteControlRegPair(uint8_t Reg, uint16_t Data);
static uint8_t ReadControlReg(uint8_t Reg);
static void WriteControlReg(uint8_t Reg, uint8_t Data);
static void CheckBank(uint8_t Reg);
static void SystemReset();
static void WriteCommand(ENC28J60_RegCommand Command, uint8_t RegAddr);
static ENC28J60_RegType GetRegType(uint8_t Reg);
static ENC28J60_RegBank GetRegBank(uint8_t Reg);
static uint8_t GetRegAddr(uint8_t Reg);
static uint8_t ReadByte();
static void WriteByte(uint8_t TxData);
static void CS_LOW();
static void CS_HIGH();


#endif // #ifndef ENC28J60_H
