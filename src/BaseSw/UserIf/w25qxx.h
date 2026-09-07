#ifndef __W25Q128_W25QXX_H__
#define __W25Q128_W25QXX_H__

#include "Spi.h"
#include "Delay.h"
#include "Port.h"
#include "Dio.h"


// FLASH_CS chip select pin definition
#define W25Q128_CS_GPIO_Port GPIOA
#define W25Q128_CS_Pin GPIO_PIN_4

// 25 series FLASH chip manufacturer and capacity code (manufacturer code EF)
#define W25Q80    0XEF13
#define W25Q16    0XEF14
#define W25Q32    0XEF15
#define W25Q64    0XEF16
#define W25Q128   0XEF17
#define W25Q256   0XEF18

#define EX_FLASH_ADD 0x000000 // W25Q128 address is 24-bit wide
extern uint16 W25QXX_TYPE; // Define W25QXX chip model

// Command table
#define W25X_WriteEnable             0x06
#define W25X_WriteDisable            0x04
#define W25X_ReadStatusReg1          0x05
#define W25X_ReadStatusReg2          0x35
#define W25X_ReadStatusReg3          0x15
#define W25X_WriteStatusReg1         0x01
#define W25X_WriteStatusReg2         0x31
#define W25X_WriteStatusReg3         0x11
#define W25X_ReadData                0x03
#define W25X_FastReadData            0x0B
#define W25X_FastReadDual            0x3B
#define W25X_PageProgram             0x02
#define W25X_BlockErase              0xD8
#define W25X_SectorErase             0x20
#define W25X_ChipErase               0xC7
#define W25X_PowerDown               0xB9
#define W25X_ReleasePowerDown        0xAB
#define W25X_DeviceID                0xAB
#define W25X_ManufactDeviceID        0x90
#define W25X_JedecDeviceID           0x9F
#define W25X_Enable4ByteAddr         0xB7
#define W25X_Exit4ByteAddr           0xE9

void MySpi_SyncTransmit(void);
uint8 MySPI_ReadWriteByte(uint8 ByteSend);
uint8 SPI1_ReadWriteByte(uint8 TxData); // SPI1 bus low-level read/write
void W25QXX_CS(uint8 a); // W25QXX chip select pin control
uint8 W25QXX_Init(void); // Initialize W25QXX function
uint8 W25QXX_Read_SR(uint8 regno); // Read status register
void W25QXX_Write_SR(uint8 regno, uint8 sr); // Write status register
void W25QXX_Write_Enable(void); // Write enable
void W25QXX_Write_Disable(void); // Write protect / write disable
void W25QXX_Wait_Busy(void); // Wait for idle
uint16 W25QXX_ReadID(void); // Read Flash ID
void W25QXX_Read(uint8 *pBuffer, uint32 ReadAddr, uint16 NumByteToRead); // Read Flash
void W25QXX_Write_Page(uint8 *pBuffer, uint32 WriteAddr, uint16 NumByteToWrite); // Page write
void W25QXX_Write_NoCheck(uint8 *pBuffer, uint32 WriteAddr, uint16 NumByteToWrite); // Unchecked write to SPI FLASH
void W25QXX_Erase_Sector(uint32 Sec_Addr); // Sector erase
void W25QXX_Write(uint8 *pBuffer, uint32 WriteAddr, uint16 NumByteToWrite); // Write to Flash
void W25QXX_Erase_Chip(void); // Chip erase
void W25QXX_PowerDown(void); // Enter power-down mode
void W25QXX_WAKEUP(void); // Wake up
uint32 W25QXX_ReadJEDECID(void);


void Spi_DemoFunction_SW_CS(void);/* Software GPIO CS */
void Spi_DemoFunction_HW_CS(void);/* Hardware Peripheral CS */
//void Spi_Asynchronous_DemoFunction(void);/* 异步通信(使用DMA，非阻塞)，异步类型为中断模式 */

#endif
