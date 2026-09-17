#include "w25qxx.h"

/* SPI Mode0 */
void MySpi_SyncTransmit(void)
{
	uint8 ret = E_NOT_OK;
	uint32 T_Timeout = 50000;
	volatile Spi_SeqResultType Spi_TransmitStatus = SPI_SEQ_FAILED;

	/* 同步传输接口，数据发送/接收完成函数返回，使程序进入阻塞状态 */
	ret = Spi_SyncTransmit(SpiConf_SpiSequence_SpiSequence_QSPI4_9183QK);

	do
	{
		Spi_TransmitStatus = Spi_GetSequenceResult(SpiConf_SpiSequence_SpiSequence_QSPI4_9183QK);

	}while (SPI_SEQ_OK != Spi_TransmitStatus && 0 < T_Timeout--);
}

#if 0
uint8 MySPI_ReadWriteByte(uint8 ByteSend)
{
	uint8 pRxData[1];
	uint8 pTxData[1];

	pTxData[0]= ByteSend;

	Spi_SetupEB(SpiConf_SpiChannel_SpiChannel_QSPI4_TLE9183QK, pTxData, pRxData, 0x01U);
	MySpi_SyncTransmit();
	return pRxData[0];
}

uint16 W25QXX_TYPE = W25Q128; // Default is W25Q128
// 4KB per sector
// 16 sectors per block
// W25Q128
// Capacity 16MB bytes, total 256 blocks, 4096 sectors

// Function: SPI1 bus read/write one byte
// Parameter: byte to write, return value: byte read
uint8 SPI1_ReadWriteByte(uint8 TxData)
{
    uint8 RxData; // Variable to receive data
    RxData = MySPI_ReadWriteByte(TxData);
    return RxData;
}


void W25QXX_CS(uint8 a) // Software chip select control function (0 for low level, other values for high level)
{
	if(a==0)
	{
		Dio_WriteChannel(DioConf_DioChannel_DioChannel_GD_ENA1_P00_0, STD_LOW);
	}
	else
	{
		Dio_WriteChannel(DioConf_DioChannel_DioChannel_GD_ENA1_P00_0, STD_HIGH);
	}
}


// Initialize SPI FLASH I/O pins
uint8 W25QXX_Init(void)
{
    uint8 temp;
    W25QXX_CS(1); // 0: chip select enable, 1: chip select disable
    W25QXX_TYPE = W25QXX_ReadID(); // Read FLASH ID
    if (W25QXX_TYPE == W25Q256) // Only set 4-byte address mode for W25Q256
    {
        temp = W25QXX_Read_SR(3); // Read status register 3, check address mode
        if ((temp & 0x01) == 0) // If it is in 3-byte address mode, switch to 4-byte address mode
        {
            W25QXX_CS(0);
            SPI1_ReadWriteByte(W25X_Enable4ByteAddr); // Send command to enter 4-byte address mode
            W25QXX_CS(1);
        }
    }
    if (W25QXX_TYPE == W25Q256 || W25QXX_TYPE == W25Q128 || W25QXX_TYPE == W25Q64
        || W25QXX_TYPE == W25Q32 || W25QXX_TYPE == W25Q16 || W25QXX_TYPE == W25Q80)
    {
        return 0; // If the read ID matches one in the existing model list, chip identification successful!
    }
    else
        return 1;
}

// Read the status register of W25QXX. W25QXX has three status registers in total.
// Status Register 1:
// BIT7  6   5   4   3   2   1   0
// SPR   RV  TB BP2 BP1 BP0 WEL BUSY
// SPR: default 0, status register protection bit, used with WP
// TB, BP2, BP1, BP0: FLASH area write protection setting
// WEL: write enable latch
// BUSY: busy flag (1: busy, 0: idle)
// Default: 0x00
// Status Register 2:
// BIT7  6   5   4   3   2   1   0
// SUS   CMP LB3 LB2 LB1 (R) QE  SRP1
// Status Register 3:
// BIT7      6    5    4   3   2   1   0
// HOLD/RST  DRV1 DRV0 (R) (R) WPS (R) (R)
// regno: status register number, range: 1~3
// Return value: status register value
uint8 W25QXX_Read_SR(uint8 regno)
{
    uint8 byte = 0, command = 0;
    switch (regno)
    {
    case 1:
        command = W25X_ReadStatusReg1; // Read status register 1 command
        break;
    case 2:
        command = W25X_ReadStatusReg2; // Read status register 2 command
        break;
    case 3:
        command = W25X_ReadStatusReg3; // Read status register 3 command
        break;
    default:
        command = W25X_ReadStatusReg1; // Default read status register 1 command
        break;
    }
    W25QXX_CS(0); // 0: chip select enable, 1: chip select disable
    SPI1_ReadWriteByte(command); // Send read status register command, one byte
    byte = SPI1_ReadWriteByte(0xFF); // Read one byte
    W25QXX_CS(1);
    return byte;
}

// Write W25QXX status register
void W25QXX_Write_SR(uint8 regno, uint8 sr)
{
    uint8 command = 0;
    switch (regno)
    {
    case 1:
        command = W25X_WriteStatusReg1; // Write status register 1 command
        break;
    case 2:
        command = W25X_WriteStatusReg2; // Write status register 2 command
        break;
    case 3:
        command = W25X_WriteStatusReg3; // Write status register 3 command
        break;
    default:
        command = W25X_WriteStatusReg1; // Default write status register 1
        break;
    }
    W25QXX_CS(0);
    SPI1_ReadWriteByte(command); // Send write status register command
    SPI1_ReadWriteByte(sr); // Write one byte
    W25QXX_CS(1);
}

// W25QXX write enable: set WEL bit
void W25QXX_Write_Enable(void)
{
    W25QXX_CS(0);
    SPI1_ReadWriteByte(W25X_WriteEnable); // Send write enable command
    W25QXX_CS(1);
}

// W25QXX write disable: clear WEL bit
void W25QXX_Write_Disable(void)
{
    W25QXX_CS(0);
    SPI1_ReadWriteByte(W25X_WriteDisable); // Send write disable command
    W25QXX_CS(1);
}

// Wait for idle
void W25QXX_Wait_Busy(void)
{
    while ((W25QXX_Read_SR(1) & 0x01) == 0x01); // Wait for BUSY bit to be 0
}

// Read chip ID
// High 8 bits are manufacturer code (not checked in this program)
// Low 8 bits are capacity
// 0xEF13 model: W25Q80
// 0xEF14 model: W25Q16
// 0xEF15 model: W25Q32
// 0xEF16 model: W25Q64
// 0xEF17 model: W25Q128 (Yangtao 2 development board uses 128 capacity chip)
// 0xEF18 model: W25Q256
uint16 W25QXX_ReadID(void)
{
    uint16 Temp = 0;
    W25QXX_CS(0);
    SPI1_ReadWriteByte(0x90); // Send read ID command
    SPI1_ReadWriteByte(0x00);
    SPI1_ReadWriteByte(0x00);
    SPI1_ReadWriteByte(0x00);
    // Data transmission is MSB first
    Temp |= SPI1_ReadWriteByte(0xFF) << 8; // Read high 8 bits
    Temp |= SPI1_ReadWriteByte(0xFF);      // Read low 8 bits
    W25QXX_CS(1);
    return Temp;
}

// Read SPI FLASH
// Read data of specified length starting from specified address
// pBuffer: data storage area
// ReadAddr: start read address (24-bit)
// NumByteToRead: number of bytes to read (max 65535)
void W25QXX_Read(uint8 *pBuffer, uint32 ReadAddr, uint16 NumByteToRead)
{
    uint16 i = 0;
    W25QXX_CS(0); // Enable chip select
    SPI1_ReadWriteByte(W25X_ReadData); // Send read command
    if (W25QXX_TYPE == W25Q256) // For W25Q256, address is 4 bytes, need to send the highest 8 bits
    {
        SPI1_ReadWriteByte((uint8)((ReadAddr) >> 24));
    }
    SPI1_ReadWriteByte((uint8)((ReadAddr) >> 16)); // Send high byte of 24-bit address
    SPI1_ReadWriteByte((uint8)((ReadAddr) >> 8));  // Send middle byte of 24-bit address
    SPI1_ReadWriteByte((uint8)ReadAddr);           // Send low byte of 24-bit address
    for (i = 0; i < NumByteToRead; i++)
    {
        pBuffer[i] = SPI1_ReadWriteByte(0xFF); // Read data in a loop
    }
    W25QXX_CS(1); // Disable chip select
}

// Write less than 256 bytes of data within one page (0~65535)
// Write up to 256 bytes of data at the specified address
// pBuffer: data storage area
// WriteAddr: start write address (24-bit)
// NumByteToWrite: number of bytes to write (max 256), should not exceed the remaining bytes of this page
void W25QXX_Write_Page(uint8 *pBuffer, uint32 WriteAddr, uint16 NumByteToWrite)
{
    uint16 i = 0;
    W25QXX_Write_Enable(); // Write enable
    W25QXX_CS(0);
    SPI1_ReadWriteByte(W25X_PageProgram); // Send page program command byte
    if (W25QXX_TYPE == W25Q256) // For W25Q256, address is 4 bytes (32-bit), need to send the highest 8 bits
    {
        // Send the highest 8 bits of address
        SPI1_ReadWriteByte((uint8)((WriteAddr) >> 24));
    }
    SPI1_ReadWriteByte((uint8)((WriteAddr) >> 16)); // Send high 8 bits of 24-bit address
    SPI1_ReadWriteByte((uint8)((WriteAddr) >> 8));  // Send middle 8 bits of 24-bit address
    SPI1_ReadWriteByte((uint8)WriteAddr);           // Send low 8 bits of 24-bit address
    for (i = 0; i < NumByteToWrite; i++)
    {
        SPI1_ReadWriteByte(pBuffer[i]); // Write data in a loop
    }
    W25QXX_CS(1);
    W25QXX_Wait_Busy(); // Wait for write to complete
}

// Unchecked write to SPI FLASH
// Must ensure that all data in the target address range is 0xFF, otherwise writing to non-0xFF locations will fail!
// Has automatic page crossing capability
// Write data of specified length starting from specified address, but ensure address does not overflow!
// pBuffer: data storage area
// WriteAddr: start write address (24-bit)
// NumByteToWrite: number of bytes to write (max 65535)
// CHECK OK
void W25QXX_Write_NoCheck(uint8 *pBuffer, uint32 WriteAddr, uint16 NumByteToWrite)
{
    uint16 PageRemain;
    PageRemain = 256 - WriteAddr % 256; // Remaining bytes in the current page
    if (NumByteToWrite <= PageRemain)
    {
        PageRemain = NumByteToWrite; // Not more than 256 bytes
    }
    while (1)
    {
        W25QXX_Write_Page(pBuffer, WriteAddr, PageRemain);
        if (NumByteToWrite == PageRemain)
        {
            // When the amount to write fits within the remaining bytes of the current page
            break;
        }
        else // When the amount to write exceeds the remaining bytes of the current page
        {
            pBuffer += PageRemain;
            WriteAddr += PageRemain;
            NumByteToWrite = NumByteToWrite - PageRemain; // Subtract the already written bytes
            if (NumByteToWrite > 256) // If remaining bytes to write > 256
            {
                PageRemain = 256; // Write 256 bytes in the next page
            }
            else // If remaining bytes to write <= 256
            {
                PageRemain = NumByteToWrite;
            }
        }
    }
}

// Write to SPI FLASH
// Write data of specified length starting from specified address
// This function includes erase operation!
// pBuffer: data storage area
// WriteAddr: start write address (24-bit)
// NumByteToWrite: number of bytes to write (max 65535)
uint8 W25QXX_BUFFER[4096];
void W25QXX_Write(uint8 *pBuffer, uint32 WriteAddr, uint16 NumByteToWrite)
{
    // One sector has 4096 bytes
    uint32 secpos; // Sector address (0~4095)
    uint16 secoff; // Offset within sector
    uint16 sec_remain; // Remaining space in sector
    uint16 i = 0;
    uint8 *W25QXX_BUF;
    W25QXX_BUF = W25QXX_BUFFER; // Pointer points to array
    secpos = WriteAddr / 4096; // Get sector address: 0 is the first sector
    secoff = WriteAddr % 4096; // Offset within sector
    sec_remain = 4096 - secoff; // Get remaining space in sector
    // printf("Addr: %X, Num: %X\r\n",WriteAddr,NumByteToWrite); // For testing
    if (NumByteToWrite <= sec_remain) // If bytes to write <= remaining space in current sector
    {
        sec_remain = NumByteToWrite;
    }
    while (1)
    {
        W25QXX_Read(W25QXX_BUF, secpos * 4096, 4096); // Read the entire sector content
        for (i = 0; i < sec_remain; i++) // Verify data
        {
            if (W25QXX_BUF[secoff + i] != 0xFF)
            {
                break; // Need to erase
            }
        }
        if (i < sec_remain) // Need to erase
        {
            W25QXX_Erase_Sector(secpos); // Erase this sector
            for (i = 0; i < sec_remain; i++) // Copy
            {
                W25QXX_BUF[i + secoff] = pBuffer[i];
            }
            W25QXX_Write_NoCheck(W25QXX_BUF, secpos * 4096, 4096); // Write the entire sector
        }
        else // No need to erase
        {
            W25QXX_Write_NoCheck(pBuffer, WriteAddr, sec_remain); // Directly write to the remaining space of the sector
        }
        if (NumByteToWrite == sec_remain) // If written exactly the remaining space
            break; // Write completed
        else // Write not yet completed
        {
            secpos++; // Move to next sector
            secoff = 0; // Offset reset to 0
            pBuffer += sec_remain; // Move pointer
            WriteAddr += sec_remain; // Move write address
            NumByteToWrite -= sec_remain; // Decrease remaining bytes
            if (NumByteToWrite > 4096)
            {
                sec_remain = 4096; // Still cannot finish writing the next sector
            }
            else // Can finish writing the next sector
            {
                sec_remain = NumByteToWrite;
            }
        }
    }
}

// Erase a sector
// Sec_Addr: sector address, range (0~4095) based on actual capacity
// Minimum time to erase one sector: 150ms
// The address sent is the start address of the sector to be erased.
// Therefore, to erase the second sector, the start address of that sector needs to be sent.
void W25QXX_Erase_Sector(uint32 Sec_Addr)
{
    Sec_Addr *= 4096;
    W25QXX_Write_Enable(); // Write enable
    W25QXX_Wait_Busy(); // Wait for idle
    W25QXX_CS(0); // Pull chip select low
    SPI1_ReadWriteByte(W25X_SectorErase); // Send sector erase command
    // Send 24-bit address
    if (W25QXX_TYPE == W25Q256) // For W25Q256, address is 4 bytes, need to send the highest 8 bits
    {
        SPI1_ReadWriteByte((uint8)((Sec_Addr) >> 24));
    }
    SPI1_ReadWriteByte((uint8)((Sec_Addr) >> 16)); // Send high 8 bits of 24-bit address
    SPI1_ReadWriteByte((uint8)((Sec_Addr) >> 8));  // Send middle 8 bits of 24-bit address
    SPI1_ReadWriteByte((uint8)Sec_Addr);           // Send low 8 bits of 24-bit address
    W25QXX_CS(1); // Pull chip select high
    W25QXX_Wait_Busy(); // Wait for erase to complete
}

// Erase the entire chip
// Very long waiting time...
// Chip erase command erases all data in W25Q128 to 0xFF
void W25QXX_Erase_Chip(void)
{
    W25QXX_Write_Enable();
    W25QXX_Wait_Busy();
    W25QXX_CS(0);
    SPI1_ReadWriteByte(W25X_ChipErase); // Send chip erase command
    W25QXX_CS(1);
    W25QXX_Wait_Busy(); // Wait for chip erase to complete
}

// Enter power-down mode
void W25QXX_PowerDown(void)
{
    W25QXX_CS(0);
    SPI1_ReadWriteByte(W25X_PowerDown); // Send power-down command 0xB9
    W25QXX_CS(1);
    delay_us(3); // Wait for TPD
}

// Wake up
void W25QXX_WAKEUP(void)
{
    W25QXX_CS(0);
    SPI1_ReadWriteByte(W25X_ReleasePowerDown); // Send power-up command 0xAB
    W25QXX_CS(1);
    delay_us(3); // Wait for TRES1
}

// 读取 JEDEC ID (3字节)
// 返回值格式: 0xXXYYZZ
//   XX: Manufacturer ID (Winbond = 0xEF)
//   YY: Memory Type (W25Q128 = 0x40)
//   ZZ: Capacity (W25Q128 = 0x18)
uint32 W25QXX_ReadJEDECID(void)
{
    uint32 Temp = 0;

    W25QXX_CS(0);                              // 片选使能

    SPI1_ReadWriteByte(0x9F);                  // 发送 JEDEC ID 指令

    Temp |= (uint32)SPI1_ReadWriteByte(0xFF) << 16;  // Manufacturer ID
    Temp |= (uint32)SPI1_ReadWriteByte(0xFF) << 8;   // Memory Type
    Temp |= (uint32)SPI1_ReadWriteByte(0xFF);        // Capacity

    W25QXX_CS(1);                              // 片选禁用

    return Temp;
}

uint32 JEDECID_Array[10];
void Test_MultipleReads(void)
{
	uint8 i;
    for (i = 0; i < 10; i++)
    {
    	JEDECID_Array[i] = W25QXX_ReadJEDECID();
    }
    // 所有输出应该都是 0xEF4018
}

uint8 ArrayWrite[] = {0x11,0x22,0x33,0x44};
uint8 ArrayRead[4];
uint16 ID;
uint32 JEDECID;
void Spi_DemoFunction_SW_CS(void)
{
	/*Qspi init*/
	Spi_Init(&Spi_Config);

	/* After enabling the QSPI module, it is recommended to perform a dummy transfer
	 * to initialize the internal baud rate generator and shift register */
	W25QXX_CS(0);
	SPI1_ReadWriteByte(0xFF);
	W25QXX_CS(1);

	ID = W25QXX_ReadID();

	JEDECID = W25QXX_ReadJEDECID();

	Test_MultipleReads();

	W25QXX_Erase_Sector(0);
    delay_ms(200);

	W25QXX_Write(ArrayWrite,0,4);
	delay_ms(200);

	W25QXX_Read(ArrayRead,0,4);
}

#endif



uint8 dummyTx[1] = {0xAA};
uint8 dummyRx[1];


void Spi_DemoFunction_HW_CS(void)
{
	/*Qspi init*/
	Spi_Init(&Spi_Config);

	Spi_SetupEB(SpiConf_SpiSequence_SpiSequence_QSPI4_9183QK, dummyTx, dummyRx, 1);
	MySpi_SyncTransmit();

}

