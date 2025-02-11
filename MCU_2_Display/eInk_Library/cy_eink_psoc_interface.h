/******************************************************************************
* File Name: cy_eink_psoc_interface.h
*
* Version: 1.10
*
* Description: This file contains function declarations and macro definitions
*              provided by the cy_eink_psoc_interface.c file.
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
* This file contains function declarations and macro definitions provided by the
* cy_eink_psoc_interface.c file.
*
* For the details of the E-INK display and library functions, see the code  
* example document of CE218133 - PSoC 6 MCU E-INK Display with CapSense
*
* For the details of E-INK display control and communication protocols, see the
* driver document available at the following location:
* http://www.pervasivedisplays.com/products/271
*******************************************************************************/

/* Include Guard */
#ifndef CY_EINK_INTERFACE_H
#define CY_EINK_INTERFACE_H

/* Header file includes */
#include "cycfg.h"
#include "cyhal.h"
#include "cybsp.h"
#include "FreeRTOS.h"
#include "task.h"

#define EINK_MOSI		CYBSP_D11
#define EINK_MISO     	CYBSP_D12
#define EINK_SCLK 		CYBSP_D13
#define EINK_DISPCS		CYBSP_D10	/* SPI CS output pin */
#define EINK_DISPRST	CYBSP_D2	/* Display reset output pin */
#define EINK_DISPBUSY	CYBSP_D3	/* Display busy input pin */
#define EINK_DISCHARGE	CYBSP_D5	/* Display discharge output pin */
#define EINK_DISPEN		CYBSP_D4	/* Display enable output pin */
#define EINK_BORDER		CYBSP_D6	/* Display border output pin */
#define EINK_DISPIOEN	CYBSP_D7	/* Display IO Enable output pin */

/* Macros used for byte level operations */
#define CY_EINK_BYTE_SIZE      (uint8_t)(0x08u)
#define CY_EINK_SINGLE_BYTE    (uint8_t)(0x01u)

/* Definitions of pin sates */
#define CY_EINK_PIN_LOW        (uint8_t)(0x00u)
#define CY_EINK_PIN_HIGH       (uint8_t)(0x01u)

/* Push the chip select pin to logic HIGH */
#define CY_EINK_CsHigh         cyhal_gpio_write(EINK_DISPCS, CY_EINK_PIN_HIGH)

/* Pull the chip select pin to logic LOW */
#define CY_EINK_CsLow          cyhal_gpio_write(EINK_DISPCS, CY_EINK_PIN_LOW)

/* Push the reset pin to logic HIGH */
#define CY_EINK_RstHigh        cyhal_gpio_write(EINK_DISPRST, CY_EINK_PIN_HIGH)

/* Pull the reset pin to logic LOW */
#define CY_EINK_RstLow         cyhal_gpio_write(EINK_DISPRST, CY_EINK_PIN_LOW)

/* Push the discharge pin to logic HIGH */
#define CY_EINK_DischargeHigh  cyhal_gpio_write(EINK_DISCHARGE, CY_EINK_PIN_HIGH)

/* Pull the discharge pin to logic LOW */
#define CY_EINK_DischargeLow   cyhal_gpio_write(EINK_DISCHARGE, CY_EINK_PIN_LOW)

/* Turn on the display by pushing the display enable pin to logic HIGH */
#define CY_EINK_TurnOnVcc      cyhal_gpio_write(EINK_DISPEN, CY_EINK_PIN_HIGH)

/* Turn off the display by pulling the display enable pin to logic LOW */
#define CY_EINK_TurnOffVcc     cyhal_gpio_write(EINK_DISPEN, CY_EINK_PIN_LOW)

/* Push the border pin to logic HIGH */
#define CY_EINK_BorderHigh     cyhal_gpio_write(EINK_BORDER, CY_EINK_PIN_HIGH)

/* Pull the border  pin to logic LOW */
#define CY_EINK_BorderLow      cyhal_gpio_write(EINK_BORDER, CY_EINK_PIN_LOW)

/* Pull the Enable I/O pin to logic LOW */
#define CY_EINK_EnableIO       cyhal_gpio_write(EINK_DISPIOEN, CY_EINK_PIN_LOW)

/* Push the Enable I/O pin to logic HIGH */
#define CY_EINK_DisableIO      cyhal_gpio_write(EINK_DISPIOEN, CY_EINK_PIN_HIGH)

/* Firmware delay in mS */
#define CY_EINK_Delay          vTaskDelay

/* Firmware delay of 10uS (Reserved for future use) */
#define CY_EINK_Wait10uS

/* Functions used for E-INK display timing */
void        Cy_EINK_TimerInit(void);
void        Cy_EINK_TimerStop(void);
uint32_t    Cy_EINK_GetTimeTick(void);

/* Functions used for E-INK driver communication */
void 		CY_EINK_InitDriver(void);
void        Cy_EINK_InitSPI(void);
void        Cy_EINK_AttachSPI(void);
void        Cy_EINK_DetachSPI(void);
void        Cy_EINK_WriteSPI(uint8_t data);
uint8_t     Cy_EINK_ReadSPI(void);
uint8_t     Cy_EINK_WriteReadSPI(uint8_t data);
bool        Cy_EINK_IsBusy(void);

#endif /* CY_EINK_INTERFACE_H */  
/* [] END OF FILE */
