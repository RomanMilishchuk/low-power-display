/******************************************************************************
* File Name: cy_eink_psoc_encapsulation.c
*
* Version: 1.10
*
* Description: This file contains functions that encapsulate PSoC Component APIs
*              or Peripheral Driver Library APIs.
*
* Hardware Dependency: CY8CKIT-028-EPD E-INK Display Shield
*
*******************************************************************************
* Copyright (2019), Cypress Semiconductor Corporation. All rights reserved.
*******************************************************************************
* This software, including source code, documentation and related materials
* (“Software”), is owned by Cypress Semiconductor Corporation or one of its
* subsidiaries (“Cypress”) and is protected by and subject to worldwide patent
* protection (United States and foreign), United States copyright laws and
* international treaty provisions. Therefore, you may use this Software only
* as provided in the license agreement accompanying the software package from
* which you obtained this Software (“EULA”).
*
* If no EULA applies, Cypress hereby grants you a personal, non-exclusive,
* non-transferable license to copy, modify, and compile the Software source
* code solely for use in connection with Cypress’s integrated circuit products.
* Any reproduction, modification, translation, compilation, or representation
* of this Software except as specified above is prohibited without the express
* written permission of Cypress.
*
* Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. Cypress
* reserves the right to make changes to the Software without notice. Cypress
* does not assume any liability arising out of the application or use of the
* Software or any product or circuit described in the Software. Cypress does
* not authorize its products for use in any products where a malfunction or
* failure of the Cypress product may reasonably be expected to result in
* significant property damage, injury or death (“High Risk Product”). By
* including Cypress’s product in a High Risk Product, the manufacturer of such
* system or application assumes all risk of such use and in doing so agrees to
* indemnify Cypress against all liability.
********************************************************************************/
/******************************************************************************
* This file contains functions that encapsulate PSoC Component APIs or Peripheral
* Driver Library APIs. Functions defined in this file are used by the 
* cy_eink_hardware_driver.c.
*
* For the details of the E-INK display and library functions, see the code  
* example document of CE218133 - PSoC 6 MCU E-INK Display with CapSense
*
* For the details of E-INK display control and communication protocols, see the
* driver document available at the following location:
* http://www.pervasivedisplays.com/products/271
*******************************************************************************/

/* Header file includes */
#include "cy_eink_psoc_interface.h"

/* Define SPI interface to communicate with the EInk driver */
cyhal_spi_t	SPI;

static uint32_t timerCount;

/*******************************************************************************
* Function Name: void CY_EINK_InitDriver(uint8_t value)
********************************************************************************
*
* Summary:
* Configure the GPIOs required to interface with the display
*
* Parameters:
*  None
*
* Return:
*  None
*
* Side Effects:
*  None
*******************************************************************************/
void CY_EINK_InitDriver(void)
{
	cyhal_gpio_init(EINK_DISPCS, CYHAL_GPIO_DIR_OUTPUT, CYHAL_GPIO_DRIVE_STRONG, 0);
	cyhal_gpio_init(EINK_DISPRST, CYHAL_GPIO_DIR_OUTPUT, CYHAL_GPIO_DRIVE_STRONG, 0);
	cyhal_gpio_init(EINK_DISPBUSY, CYHAL_GPIO_DIR_INPUT, CYHAL_GPIO_DRIVE_NONE, 0);
	cyhal_gpio_init(EINK_DISCHARGE, CYHAL_GPIO_DIR_OUTPUT, CYHAL_GPIO_DRIVE_STRONG, 0);
	cyhal_gpio_init(EINK_DISPEN, CYHAL_GPIO_DIR_OUTPUT, CYHAL_GPIO_DRIVE_STRONG, 0);
	cyhal_gpio_init(EINK_BORDER, CYHAL_GPIO_DIR_OUTPUT, CYHAL_GPIO_DRIVE_STRONG, 0);
	cyhal_gpio_init(EINK_DISPIOEN, CYHAL_GPIO_DIR_OUTPUT, CYHAL_GPIO_DRIVE_STRONG, 0);
}

/*******************************************************************************
* Function Name: void Cy_EINK_TimerInit(void)
********************************************************************************
*
* Summary:
*  This function clears and initializes the E-INK Timer
*
* Parameters:
*  None
*
* Return:
*  None
*
* Side Effects:
*  None
*******************************************************************************/
void Cy_EINK_TimerInit(void)
{   
	timerCount = xTaskGetTickCount();
}

/*******************************************************************************
* Function Name: uint32_t Cy_EINK_GetTimeTick(void)
********************************************************************************
*
* Summary:
*  This function returns the value of current time tick of E-INK Timer.
*
* Parameters:
*  None
*
* Return:
*  uint32_t : current value of time tick
*
* Side Effects:
*  None
*******************************************************************************/
uint32_t Cy_EINK_GetTimeTick(void)
{
    /* Return the current value of time tick */
	return(xTaskGetTickCount()-timerCount);
}

/*******************************************************************************
* Function Name: void Cy_EINK_TimerStop(void)
********************************************************************************
*
* Summary:
*  Stops the E-INK Timer.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Side Effects:
*  None
*******************************************************************************/
void Cy_EINK_TimerStop(void)
{

}

/*******************************************************************************
* Function Name: void Cy_EINK_InitSPI(void)
********************************************************************************
*
* Summary:
*  Initializes the SPI block that communicates with the E-INK display.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Side Effects:
*  None
*******************************************************************************/
void Cy_EINK_InitSPI(void)
{
    /* Start the SPI master */
	cyhal_spi_init(&SPI, EINK_MOSI, EINK_MISO, EINK_SCLK, NC, NULL, 8, CYHAL_SPI_MODE_00_MSB, false);
	cyhal_spi_set_frequency(&SPI, 20000000);

    /* Make the chip select HIGH */
    CY_EINK_CsHigh;
}

/*******************************************************************************
* Function Name: void Cy_EINK_AttachSPI(void)
********************************************************************************
*
* Summary:
*  Attaches the SPI master to the E-INK display driver.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Side Effects:
*  None
*******************************************************************************/
void Cy_EINK_AttachSPI(void)
{
    /* Make the chip select HIGH */
    CY_EINK_CsHigh;
}

/*******************************************************************************
* Function Name: void Cy_EINK_DetachSPI(void)
********************************************************************************
*
* Summary:
*  Detaches the SPI master from the E-INK display driver.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Side Effects:
*  None
*******************************************************************************/
void Cy_EINK_DetachSPI(void)
{
	CY_EINK_CsLow;
}

/*******************************************************************************
* Function Name: void Cy_EINK_WriteSPI(uint8_t data)
********************************************************************************
*
* Summary:
*  Send a byte of data to the E-INK display driver via SPI.
*
* Parameters:
*  uint8_t data : data byte that need to be transmitted
*
* Return:
*  None
*
* Side Effects:
*  None
*******************************************************************************/
void Cy_EINK_WriteSPI(uint8_t data)
{
    /* Send one byte of data */
    cyhal_spi_send(&SPI, data);
}

/*******************************************************************************
* Function Name: Cy_EINK_ReadSPI(void)
********************************************************************************
*
* Summary:
*  Read a byte of data from the E-INK display driver via SPI.
*
* Parameters:
*  None
*
* Return:
*  uint8_t : received data
*
* Side Effects:
*  None
*******************************************************************************/
uint8_t Cy_EINK_ReadSPI(void)
{
	uint32_t readData;
	cyhal_spi_recv(&SPI, &readData);
	return (uint8_t)readData;
}

/*******************************************************************************
* Function Name: uint8_t Cy_EINK_WriteReadSPI(uint8_t data)
********************************************************************************
*
* Summary:
*  Write a byte of data to the E-INK driver and read a return byte.
*
* Parameters:
*  uint8_t data : command that need to be transmitted
*
* Return:
*  uint8_t: received data byte
*
* Side Effects:
*  None
*******************************************************************************/
uint8_t Cy_EINK_WriteReadSPI(uint8_t data)
{
	uint32_t readData;
	cyhal_spi_send(&SPI, data);
	cyhal_spi_recv(&SPI, &readData);
	return (uint8_t)readData;
}

/*******************************************************************************
* Function Name: void Cy_EINK_WriteSPIBuffer(uint8_t* data, uint16 dataLength)
********************************************************************************
*
* Summary:
*  Send a multiple bytes of data to the E-INK display driver via SPI.
*
* Parameters:
*  uint8_t* data : pointer to the buffer that holds the data
*  uint16 dataLength : number of bytes to be transmitted
*
* Return:
*  int : Number of bytes written to SPI
*
* Side Effects:
*  None
*******************************************************************************/
int Cy_EINK_WriteSPIBuffer(uint8_t* data, uint16 dataLength)
{
    cyhal_spi_transfer(&SPI, (const uint8_t*)data, dataLength, NULL, 0, 0);
    return dataLength;
}

/*******************************************************************************
* Function Name: bool CY_EINK_IsBusy(void)
********************************************************************************
*
* Summary:
*  Check if the E-INK display is busy.
*
* Parameters:
*  None
*
* Return:
*  bool : True if the E-INK display is buy, False otherwise
*
* Side Effects:
*  None
*******************************************************************************/
bool Cy_EINK_IsBusy(void)
{
    /* Return the status of  pin */
    return cyhal_gpio_read(EINK_DISPBUSY);
}

/* [] END OF FILE */
