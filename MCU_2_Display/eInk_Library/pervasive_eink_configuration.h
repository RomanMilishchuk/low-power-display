/*******************************************************************************
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
/*******************************************************************************
* This file contains the definitions of register indexes and hardware parameters
* of the pervasive 2.7" E-INK display. It is not recommended to change any 
* definitions in this file as it may cause undesirable operation of the 
* associated hardware.
*
* For the details of E-INK display hardware and driver interface, see the 
* documents available at the following location:
* http://www.pervasivedisplays.com/products/271
*******************************************************************************/

/* Include Guard */
#ifndef PERVASIVE_EINK_CONFIGURATION_H
#define PERVASIVE_EINK_CONFIGURATION_H

/* Definitions of refresh time scaling factors for full update and partial update.
   This is a speed-contrast trade-off: Selecting a higher scaling factor increases
   the contrast as well as the refresh time */
#define PV_EINK_SCALING_FULL                (uint8_t)(0x01u)
#define PV_EINK_SCALING_PARTIAL             (uint8_t)(0x01u)    
    
/* Display driver addresses and commands. Do not modify these values */
#define PV_EINK_DRIVER_ID_COMMAND_INDEX     (uint8_t)(0x72u)
#define PV_EINK_DRIVER_ID_COMMAND_DATA      (uint8_t)(0x00u)
#define PV_EINK_DRIVER_ID_MASK              (uint8_t)(0x0fu)
#define PV_EINK_DRIVER_ID_CHECK             (uint8_t)(0x02u)
#define PV_EINK_DISABLE_OE_COMMAND_INDEX    (uint8_t)(0x02u)
#define PV_EINK_DISABLE_OE_COMMAND_DATA     (uint8_t)(0x40u)
#define PV_EINK_TEST_BREAKAGE_COMMAND_INDEX (uint8_t)(0x0Fu)
#define PV_EINK_TEST_BREAKAGE_COMMAND_DATA  (uint8_t)(0x00u)
#define PV_EINK_TEST_BREAKAGE_MASK          (uint8_t)(0x80u)
#define PV_EINK_TEST_BREAKAGE_CHECK         (uint8_t)(0x80u)
#define PV_EINK_PWR_SAVING_COMMAND_INDEX    (uint8_t)(0x0Bu)
#define PV_EINK_PWR1_SAVING_COMMAND_DATA    (uint8_t)(0x02u)
#define PV_EINK_CHANNEL_SEL_COMMAND_INDEX   (uint8_t)(0x01u)
#define PV_EINK_OSC_SETTING_COMMAND_INDEX   (uint8_t)(0x07u)
#define PV_EINK_OSC_SETTING_COMMAND_DATA    (uint8_t)(0xD1u)
#define PV_EINK_PWR1_SETTING_COMMAND_INDEX  (uint8_t)(0x08u)
#define PV_EINK_PWR1_SETTING_COMMAND_DATA   (uint8_t)(0x02u)
#define PV_EINK_VCOM1_LEVEL_COMMAND_INDEX   (uint8_t)(0x09u)
#define PV_EINK_VCOM1_LEVEL_COMMAND_DATA    (uint8_t)(0xC2u)
#define PV_EINK_PWR2_SETTING_COMMAND_INDEX  (uint8_t)(0x04u)
#define PV_EINK_PWR2_SETTING_COMMAND_DATA   (uint8_t)(0x03u)
#define PV_EINK_LATCH_ON_COMMAND_INDEX      (uint8_t)(0x03u)
#define PV_EINK_LATCH_ON_COMMAND_DATA       (uint8_t)(0x01u)
#define PV_EINK_LATCH_OFF_COMMAND_INDEX     (uint8_t)(0x03u)
#define PV_EINK_LATCH_OFF_COMMAND_DATA      (uint8_t)(0x00u)
#define PV_EINK_VGH_VDH_ON_COMMAND_INDEX    (uint8_t)(0x05u)
#define PV_EINK_VGH_VDH_ON_COMMAND_DATA     (uint8_t)(0x01u)
#define PV_EINK_VGL_VDL_ON_COMMAND_INDEX    (uint8_t)(0x05u)
#define PV_EINK_VGL_VDL_ON_COMMAND_DATA     (uint8_t)(0x03u)
#define PV_EINK_VCOM_DRIVE_ON_COMMAND_INDEX (uint8_t)(0x05u)
#define PV_EINK_VCOM_DRIVE_ON_COMMAND_DATA  (uint8_t)(0x0Fu)
#define PV_EINK_DC_LEVEL_READ_COMMAND_INDEX (uint8_t)(0x0Fu)
#define PV_EINK_DC_LEVEL_READ_COMMAND_DATA  (uint8_t)(0x00u)
#define PV_EINK_DC_LEVEL_MASK               (uint8_t)(0x40u)
#define PV_EINK_DC_LEVEL_CHECK              (uint8_t)(0x00u)
#define PV_EINK_PIXEL_DATA_COMMAND_INDEX    (uint8_t)(0x0Au)
#define PV_EINK_ENABLE_OE_COMMAND_INDEX     (uint8_t)(0x02u)
#define PV_EINK_ENABLE_OE_COMMAND_DATA      (uint8_t)(0x07u)
#define PV_EINK_VCOM2_LEVEL_COMMAND_INDEX   (uint8_t)(0x09u)
#define PV_EINK_VCOM2_LEVEL_COMMAND_DATA    (uint8_t)(0xD2u)
#define PV_EINK_PWR2_SAVING_COMMAND_DATA    (uint8_t)(0x00u)
#define PV_EINK_DISCH_SPI_COMMAND_INDEX     (uint8_t)(0x04u)
#define PV_EINK_DISCH_SPI_COMMAND_DATA      (uint8_t)(0x80u)
#define PV_EINK_CH_PUMP_OFF_COMMAND_INDEX   (uint8_t)(0x05u)
#define PV_EINK_CH_PUMP_OFF_COMMAND_DATA    (uint8_t)(0x00u)
#define PV_EINK_OSC_OFF_COMMAND_INDEX       (uint8_t)(0x07u)
#define PV_EINK_OSC_OFF_COMMAND_DATA        (uint8_t)(0x01u)
#define PV_EINK_VOLTAGE_LEVEL               (uint8_t)(0x00u)

/* Definitions of black and white pixel data bytes */ 
#define PV_EINK_BLACK_PIXEL_BYTE            (uint8_t)(0x00u)
#define PV_EINK_WHITE_PIXEL_BYTE            (uint8_t)(0xFFu)
    
/* Definitions for driving stage parameters to generate odd and even data bytes */
#define PV_EINK_BLACK0                      (uint8_t)(0x03u)
#define PV_EINK_BLACK1                      (uint8_t)(0x0Cu)
#define PV_EINK_BLACK2                      (uint8_t)(0x30u)
#define PV_EINK_BLACK3                      (uint8_t)(0xC0u)
#define PV_EINK_WHITE0                      (uint8_t)(0x02u)
#define PV_EINK_WHITE1                      (uint8_t)(0x08u)
#define PV_EINK_WHITE2                      (uint8_t)(0x20u)
#define PV_EINK_WHITE3                      (uint8_t)(0x80u)
#define PV_EINK_NOTHING0                    (uint8_t)(0x01u)
#define PV_EINK_NOTHING1                    (uint8_t)(0x04u)
#define PV_EINK_NOTHING2                    (uint8_t)(0x10u)
#define PV_EINK_NOTHING3                    (uint8_t)(0x40u)
#define PV_EINK_NOTHING                     (uint8_t)(0x55u)
#define PV_EINK_NOTHINGT                    (uint8_t)(0x00u)

/* Definitions of masks used to generate even and odd data bytes */
#define PV_EINK_ODD_MASK_A                  (uint8_t)(0x40u)
#define PV_EINK_ODD_MASK_B                  (uint8_t)(0x10u)
#define PV_EINK_ODD_MASK_C                  (uint8_t)(0x04u)
#define PV_EINK_ODD_MASK_D                  (uint8_t)(0x01u)
#define PV_EINK_EVEN_MASK_A                 (uint8_t)(0x80u)
#define PV_EINK_EVEN_MASK_B                 (uint8_t)(0x20u)
#define PV_EINK_EVEN_MASK_C                 (uint8_t)(0x08u)
#define PV_EINK_EVEN_MASK_D                 (uint8_t)(0x02u)

/* Macros for black, white and border data bytes */
#define PV_EINK_ALL_BLACK                   (uint8_t)(0xFFu)
#define PV_EINK_ALL_WHITE                   (uint8_t)(0xAAu)
#define PV_EINK_BORDER_BYTE_B               (uint8_t)(0xFFu)
#define PV_EINK_BORDER_BYTE_W               (uint8_t)(0xAAu)

/* Header index, data and driver information */
#define PV_EINK_REG_INDEX_HEADER            (uint8_t)(0x70u)
#define PV_EINK_REG_DATA_READ               (uint8_t)(0x73u)
#define PV_EINK_REG_DATA_WRITE              (uint8_t)(0x72u)
#define PV_EINK_REG_DRIVER_ID               (uint8_t)(0x71u)

/* Definitions of various firmware delays used by E-INK driving stages */
#define PV_EINK_PWR_DELAY                   (uint16_t)(20)
#define PV_EINK_PIN_DELAY                   (uint16_t)(10)
#define PV_EINK_PWR_CTRL_DELAY              (uint16_t)(50)
#define PV_EINK_POSITIVE_V_DELAY            (uint16_t)(100)
#define PV_EINK_DUMMY_LINE_DELAY            (uint16_t)(30)
#define PV_EINK_BOARDER_DELAY               (uint16_t)(50)
#define PV_EINK_DETACH_DELAY                (uint16_t)(30)
#define PV_EINK_CS_OFF_DELAY                (uint16_t)(20)
#define PV_EINK_DISCHARGE_DELAY             (uint16_t)(150)
#define PV_EINK_DISCH_SPI_DELAY             (uint16_t)(50)
#define PV_EINK_PWR_OFF_DELAY               (uint16_t)(30)

/* Definitions of pixel data generating parameters */
#define PV_EINK_PIXEL_SIZE                  (uint8_t)(0x02u)
#define PV_EINK_CHANNEL_SEL_SIZE            (uint8_t)(0x08u)
#define PV_EINK_SCAN_TABLE_SIZE             (uint8_t)(0x04u)
#define PV_EINK_CHARGE_PUMP_MAX_WRITE       (uint8_t)(0x04u)
#define PV_EINK_MAX_PV_EINK_BUSY_TIME       (uint32_t)(0x00000004u)
#define PV_EINK_SCAN_TABLE_DATA             {0xC0u,0x30u,0x0Cu,0x03u}
#define PV_EINK_CHANNEL_SEL_DATA            {0x00u,0x00u,0x00u,0x7Fu,\
                                             0xFFu,0xFEu,0x00u,0x00u}

/* Definitions of 2.7" display parameters */
/* Width of E-INK in bytes = 264/8 */
#define PV_EINK_HORIZONTAL_SIZE             (uint16_t)(33)
/* Height of E-INK in bytes */
#define PV_EINK_VERTICAL_SIZE               (uint16_t)(176)
/* Data line size = Data + Scan + Dummy bytes =
   ((((264+176)*2)/8)+1) = 111 */
#define PV_EINK_DATA_LINE_SIZE              (uint8_t) (111)
/* The rest of frame time in a stage */
#define PV_EINK_FRAME_TIME_OFFSET           (uint16_t)(0)
/* Scan line size in bytes = 2*(176/8) = 44 */
#define PV_EINK_SCAN_LINE_SIZE              (uint8_t) (44)

/* Size of an image = (264*176)/8 bytes */
#define PV_EINK_IMAGE_SIZE                  (uint16_t)(5808)

/* Timing parameters used for temperature compensation of contrast */
#define PV_EINK_TEMP_SEL0                   (uint32_t)(1200)
#define PV_EINK_TEMP_SEL1                   (uint32_t)(900)
#define PV_EINK_TEMP_SEL2                   (uint32_t)(600)
#define PV_EINK_TEMP_SEL3                   (uint32_t)(330)
#define PV_EINK_TEMP_SEL4                   (uint32_t)(220)
#define PV_EINK_TEMP_SEL5                   (uint32_t)(180)
#define PV_EINK_TEMP_SEL6                   (uint32_t)(90)
#define PV_EINK_TEMP_SEL7                   (uint32_t)(60)

/* Definitions of temperature compensation stages */
#define PV_EINK_TEMP_DEG_M10                (int8_t)(-10)
#define PV_EINK_TEMP_DEG_M5                 (int8_t)(-05)
#define PV_EINK_TEMP_DEG_5                  (int8_t)(5)
#define PV_EINK_TEMP_DEG_10                 (int8_t)(10)
#define PV_EINK_TEMP_DEG_15                 (int8_t)(15)
#define PV_EINK_TEMP_DEG_20                 (int8_t)(20)
#define PV_EINK_TEMP_DEG_40                 (int8_t)(40)

/* Macros used for timings */
#define PV_EINK_MAX_ISR_TIME                (uint16_t)(1000)
#define PV_EINK_10_US                       (uint8_t) (10)

#endif  /* PERVASIVE_EINK_CONFIGURATION_H */
/* [] END OF FILE */
