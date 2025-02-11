/*******************************************************************************
* \file cy_ble_stack_gatt_server.h
* \version 3.20
*
* \brief
*  This file contains declarations of public BLE APIs of Generic Attribute Profile - Server Role.
*  Also specifies the defines, constants, and data structures required for the APIs.
* 
* Related Document:
*  BLE Standard Spec - CoreV5.0, CSS, CSAs, ESR05, ESR06
* 
********************************************************************************
* \copyright
* Copyright 2017-2019, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#ifndef CY_BLE__STACK_GATT_SERVER_H_
#define CY_BLE__STACK_GATT_SERVER_H_


/***************************************
* Common BLE Stack includes
***************************************/

#include "cy_ble_stack_gatt.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/***************************************
* GATT Server Constants
***************************************/
/**
 \addtogroup group_ble_common_api_gatt_definitions
 @{
*/

/***************************************
** Exported structures
***************************************/
/** Notification parameter */
typedef cy_stc_ble_gatt_write_param_t  cy_stc_ble_gatts_handle_value_ntf_t;

/** Indication parameter */
typedef cy_stc_ble_gatt_write_param_t  cy_stc_ble_gatts_handle_value_ind_t;

/* --------------------------Structures corresponding to events-------------------- */

/** Prepare write request parameter received from Client */
typedef struct
{
    /** Base address of the queue containing the data. Queue is of type 
       cy_stc_ble_gatt_handle_value_offset_param_t. 
       Each baseAddr[currentPrepWriteReqCount-1].handleValuePair.value.val
       provides the current data and baseAddr[0].handleValuePair.value.val
       provides the base address of the data buffer where the full value will be stored.
       The application can calculate the total length based on each each array element;
       i.e., total length of current request = baseAddr[0].handleValuePair.value.len+
       ....+baseAddr[currentPrepWriteReqCount-1].handleValuePair.value.len
    */
    cy_stc_ble_gatt_handle_value_offset_param_t         * baseAddr;    

    /** Connection handle */
    cy_stc_ble_conn_handle_t                        connHandle;             

    /** Current count of prepare requests from remote. This parameter can be used 
       to access the data from 'baseAddr[]'. Array index will range from 0 to 
       currentPrepWriteReqCount - 1 */    
    uint8_t                                         currentPrepWriteReqCount;

    /** The application provides GATT error code for the procedure. 
        This is an output parameter. */
    uint8_t                                         gattErrorCode;    

}cy_stc_ble_gatts_prep_write_req_param_t;

/** Execute Write result */
typedef struct
{
    /** Base address of the queue where data is queued. Queue is of type 
       cy_stc_ble_gatt_handle_value_offset_param_t. 
       baseAddr[0].handleValuePair.value.val
       provides the base address of the total data stored in the prepare write
       queue internally by the Stack. 
       The application can calculate the total length based on each each array element;
       i.e., total length = baseAddr[0].handleValuePair.value.len+
       ....+baseAddr[prepWriteReqCount-1].handleValuePair.value.len
    */    
    cy_stc_ble_gatt_handle_value_offset_param_t     *baseAddr;

    /** Connection handle */
    cy_stc_ble_conn_handle_t                        connHandle; 

    /** Attribute Handle at which the error occurred. This is an o/p param.  */
    cy_ble_gatt_db_attr_handle_t                    attrHandle;     

    /** Total count of prepare requests from remote. This parameter can be used 
       to access the data from 'baseAddr[]'. The array index will range from 0 to 
       prepWriteReqCount - 1. */    
    uint8_t                                         prepWriteReqCount;

    /** Execute write flag received from remote */
    uint8_t                                         execWriteFlag;

    
    /** The application-provided GATT error code for the procedure. This is an o/p param. */
    uint8_t                                         gattErrorCode;

}cy_stc_ble_gatts_exec_write_req_t;

/** Write command request parameter received from Client */
typedef cy_stc_ble_gatt_write_param_t  cy_stc_ble_gatts_write_cmd_req_param_t;

/** Signed Write command request parameter received from Client */
typedef cy_stc_ble_gatt_write_param_t  cy_stc_ble_gatts_signed_write_cmd_req_param_t;

/** Event parameters for characteristic read value access
 * event generated by the BLE Stack upon an access of Characteristic value
 * read for the characteristic definition that  
 * CY_BLE_GATT_DB_ATTR_CHAR_VAL_RD_EVENT property set.
 **/
typedef struct
{
    /** Connection handle */
    cy_stc_ble_conn_handle_t             connHandle;

    /** Attribute Handle*/
    cy_ble_gatt_db_attr_handle_t     attrHandle;

    /** Output Parameter: Profile/Service specific error code,
         * profile or application need to change this 
         * to service specific error based on service/profile
         * requirements. */
    cy_en_ble_gatt_err_code_t           gattErrorCode;

}cy_stc_ble_gatts_char_val_read_req_t;
/** @} */

/***************************************
** Exported APIs
***************************************/
/**
 \addtogroup group_ble_common_api_gatt_server_functions
 @{
*/    
/** \cond IGNORE */
/******************************************************************************
* Function Name: Cy_BLE_GATTS_Notification
***************************************************************************//**
* 
*  This function is used by GATT Server application to send a Handle Value Notification PDU 
*  to the peer GATT Client. This function should be called when the application has an 
*  updated value of a characteristic that is configured for Notification. 
*  This is a non-blocking function.
* 
*  If the peer GATT Client is a PSoC 6 device, Notification PDU results in 
*  CY_BLE_EVT_GATTC_HANDLE_VALUE_NTF event at the GATT Client's end.
* 
*  Refer to Bluetooth 5.0 core specification, Volume 3, Part G, section 4.10 for
*  more details on notifications.
*  
*  \param param: Pointer to a variable of type cy_stc_ble_gatts_handle_value_ntf_t.
*                   The following must be set:
*                   param->handleValPair
*                   param->connHandle  
* 
* \return
*  cy_en_ble_api_result_t : Return value indicates whether the function succeeded or
*  failed. Following are the possible error codes.
* 
*  Error codes                           | Description
*  ------------                          | -----------
*   CY_BLE_SUCCESS                       | On successful operation.
*   CY_BLE_ERROR_INVALID_PARAMETER       | If 'param' is NULL, 'connHandle' is invalid or if 'param->handleValPair.value.len' value is greater than (Effective GATT MTU-3).
*   CY_BLE_ERROR_INVALID_OPERATION       | This operation is not permitted when the BLE Stack is busy. The application should wait for Stack free status indicated by 
*                                        | the CY_BLE_EVT_STACK_BUSY_STATUS event for calling this function again.
*   CY_BLE_ERROR_MEMORY_ALLOCATION_FAILED| Memory allocation failed.
*
*
*
******************************************************************************/
cy_en_ble_api_result_t Cy_BLE_GATTS_Notification
(
    cy_stc_ble_gatts_handle_value_ntf_t * param
);


/******************************************************************************
* Function Name: Cy_BLE_GATTS_Indication
***************************************************************************//**
* 
*  This function is used by GATT Server application to send Handle Value Indication PDU
*  to the peer GATT Client. This function should be called when the application has an
*  updated value of a characteristic that is configured for Indication.
*  This is a non-blocking function.
* 
*  If the peer GATT Client is a PSoC 6 device, Handle Value Indication PDU results in 
*  CY_BLE_EVT_GATTC_HANDLE_VALUE_IND event at the GATT Client's end.
*
*  The GATT Client sends a Handle Value Confirmation in response to a Handle
*  Value Indication. This confirmation PDU results in the 
*  CY_BLE_EVT_GATTS_HANDLE_VALUE_CNF event at GATT Server application.
*
*  Refer to Bluetooth 5.0 core specification, Volume 3, Part G, section 4.11 for
*  more details on Indications.
* 
*  \param param: Pointer to a variable of type cy_stc_ble_gatts_handle_value_ind_t.
*                   The following must be set:
*                   param->handleValPair
*                   param->connHandle  
* 
* \return
*  cy_en_ble_api_result_t : Return value indicates whether the function succeeded or
*  failed. Following are the possible error codes.
*
*  Error codes                           | Description
*  ------------                          | -----------
*   CY_BLE_SUCCESS                       | On successful operation.
*   CY_BLE_ERROR_INVALID_PARAMETER       | If 'param' is NULL or 'connHandle' is invalid or if 'param->handleValPair.value.len' value is greater than (Effective GATT MTU-3).
*   CY_BLE_ERROR_INVALID_OPERATION       | This operation is not permitted when the BLE Stack is busy. The application should wait for Stack free status indicated by 
*                                        | the CY_BLE_EVT_STACK_BUSY_STATUS event for calling this function again.
*   CY_BLE_ERROR_MEMORY_ALLOCATION_FAILED| Memory allocation failed.
*
*
******************************************************************************/
cy_en_ble_api_result_t Cy_BLE_GATTS_Indication
(
    cy_stc_ble_gatts_handle_value_ind_t * param
);


/******************************************************************************
* Function Name: Cy_BLE_GATTS_ErrorRsp
***************************************************************************//**
* 
*  This function is used by GATT Server application to send an Error Response PDU
*  to the peer GATT Client. This function should be called when the application has 
*  received a GATT Request, but this Request cannot be processed. The reason codes for the 
*  Error Response are defined in 'cy_en_ble_gatt_err_code_t'. This is a non-blocking function.
* 
*  \note:'Write Command' initiated by GATT Client does not generate an
*  'Error Response' from the GATT Server's end. 
*
*  If the peer GATT Client is a PSoC 6 device, the Error Response PDU results in 
*  CY_BLE_EVT_GATTC_ERROR_RSP event at GATT Client's end.
* 
*  Refer to the Bluetooth 5.0 core specification, Volume 3, Part F, section 3.4.1.1 for
*  more details on Error Response operation.
*  
*  \param param: Pointer to a variable of type cy_stc_ble_gatt_err_param_t.
*                     Where, the following needs to be set:
*                     param->opCode
*                     param->connHandle  
*                     param->attrHandle
*                     param->errorCode  
* 
* \return
*  cy_en_ble_api_result_t : Return value indicates whether the function succeeded or
*  failed. Following are the possible error codes.
*
*  Error codes                            | Description
*  ------------                           | -----------
*   CY_BLE_SUCCESS                        | On successful operation.
*   CY_BLE_ERROR_INVALID_PARAMETER        | If 'param' is NULL or 'connHandle' is invalid.
*   CY_BLE_ERROR_INVALID_OPERATION        | This operation is not permitted.
*   CY_BLE_ERROR_MEMORY_ALLOCATION_FAILED | Memory allocation failed.
* 
******************************************************************************/
cy_en_ble_api_result_t Cy_BLE_GATTS_ErrorRsp
(
    cy_stc_ble_gatt_err_param_t  * param
);


/******************************************************************************
* Function Name: Cy_BLE_GATTS_ExchangeMtuRsp
***************************************************************************//**
* 
*  This function is used by GATT Server application to send Exchange MTU Response PDU.
*  This function is used to send the maximum size of a packet that can be received by  
*  the Server (Server Rx MTU). This function should be called on receiving Exchange MTU Request
*  through CY_BLE_EVT_GATTS_XCNHG_MTU_REQ event.
*
*  The Server Rx MTU size should be greater than or 
*  equal to the default GATT MTU size (23 bytes). This is a non-blocking function.
*
*  The maximum size of packet between the Client and Server (ATT_MTU), is set 
*  to the minimum of Client Rx MTU and Server Rx MTU.
* 
*  If the peer GATT Client is a PSoC 6 device, the Exchange MTU Response PDU results in
*  CY_BLE_EVT_GATTC_XCHNG_MTU_RSP event at GATT Client's end.
* 
*  Refer to Bluetooth 5.0 core specification, Volume 3, Part G, section 4.3.1 for
*  more details on exchange of GATT MTU.
* 
*  \param param: parameter is of type CY_BLE_GATT_XCHG_MTU_REQ_PARAM_T.
*   param->mtu: Size of GATT MTU. Max GATT MTU supported by the BLE Stack is 512 Bytes.
* 
* \return
*  cy_en_ble_api_result_t : Return value indicates whether the function succeeded or
*  failed. Following are the possible error codes.
*
*  Error codes                           | Description
*  ------------                          | -----------
*   CY_BLE_SUCCESS                       | On successful operation.
*   CY_BLE_ERROR_INVALID_PARAMETER       | If 'param' is NULL or 'connHandle' is invalid or 'mtu' value is greater than that set on calling Cy_BLE_StackInit().
*   CY_BLE_ERROR_INVALID_OPERATION       | This operation is not permitted.
*   CY_BLE_ERROR_MEMORY_ALLOCATION_FAILED| Memory allocation failed.
* 
******************************************************************************/
cy_en_ble_api_result_t Cy_BLE_GATTS_ExchangeMtuRsp
(
    cy_stc_ble_gatt_xchg_mtu_param_t  * param
);

/** \endcond */
 
/******************************************************************************
* Function Name: Cy_BLE_GATTS_WriteRsp
***************************************************************************//**
* 
*  This function is used by GATT Server application to send a Write Response to a peer 
*  GATT Client. This function should be used after receiving Write Request through
*  CY_BLE_EVT_GATTS_WRITE_REQ event. This is a non-blocking function. 
* 
*  The Write Response must be sent after the attribute value is written or 
*  saved by the GATT Server. 
*  
*  If peer GATT Client is a PSoC 6 device, Write Response PDU results in 
*  CY_BLE_EVT_GATTC_WRITE_RSP event at the GATT Client's end.
* 
*  \param connHandle: Connection handle to identify the peer GATT entity, of type
             cy_stc_ble_conn_handle_t.
* 
* \return
*  cy_en_ble_api_result_t : Return value indicates whether the function succeeded or
*  failed. Following are the possible error codes.
*
*  Error codes                            | Description
*  ------------                           | -----------
*   CY_BLE_SUCCESS                        | On successful operation.
*   CY_BLE_ERROR_INVALID_PARAMETER        | If 'connHandle' is invalid.
*   CY_BLE_ERROR_INVALID_OPERATION        | This operation is not permitted.
*   CY_BLE_ERROR_MEMORY_ALLOCATION_FAILED | Memory allocation failed.
* 
******************************************************************************/
cy_en_ble_api_result_t Cy_BLE_GATTS_WriteRsp
(
    cy_stc_ble_conn_handle_t  connHandle
);

#ifdef __cplusplus
}
#endif /* __cplusplus */

/** @} */
#endif /*CY_BLE__STACK_GATT_SERVER_H_*/


 /*EOF*/
