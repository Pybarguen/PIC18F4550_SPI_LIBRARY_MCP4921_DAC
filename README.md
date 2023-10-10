# PIC18F4550_SPI_LIBRARY_MCP4921_DAC

This project generate a 9Hz senoidal wave using MCP4921 DAC and PIC18f4550 
for using the library please follow the steps

## SPI PIC18F4550 LIBRARY

Features

**Spi_init()** : This function start the SPI interface in th PIC18F4550 

RC7 = 0;//Pin SDO

RB0 = 1;//Pin SDI

RB1 = 0;//Pin SCK

You can change the select slave pin. change the line 

#define CCS PORTBbits.RB2 // PIN for slave select

--------------------------------------------------------------------------------

**Spi_mode(enum SPI_MODES data)** this funciont select the operation of the SPI interface

**Parameters  Enum SPI_MODES:**

CPOL_0_CPHA_0 SPI MODE 0 0

CPOL_0_CPHA_1 SPI MODE 0 1

CPOL_1_CPHA_0 SPI MODE 1 0

CPOL_1_CPHA_1 SPI MODE 1 1

--------------------------------------------------------------------------------

**Spi_clock_mode(enum Spi_master_clock_modes data)** this function set the SCK frequency 

**Parameters Enum Spi_master_clock_modes:**

SPI_MASTER_CLOCK_DIV_4 SCK = FOSC/4

SPI_MASTER_CLOCK_DIV_16 SCK = FOSC/16

SPI_MASTER_CLOCK_DIV_64 SCK = FOSC/64

SPI_MASTER_CLOCK_DI_TMR2_2 = FOSC/TRM2_2

--------------------------------------------------------------------------------

**write_byte_spi(int dato)** this function write data of the SPI bus

in this example we used MCP4921 and just 8bits of the DAC

 the first byte inside the funciont is  the Control Byte for MCP4921
  SSPBUF = 0x30;
  
 the second byte inside the funciont is  the 8byte data for generate 8bit senoidal signal

 You can change the function for operate another device different of the MCP4921
  