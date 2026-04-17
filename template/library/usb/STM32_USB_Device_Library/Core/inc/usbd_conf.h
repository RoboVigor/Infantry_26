/**
  ******************************************************************************
  * @file    usbd_conf_template.h
  * @author  MCD Application Team
  * @version V1.2.1
  * @date    30-June-2015
  * @brief   usb device configuration template file
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2015 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                      <http://www.st.com/SLA0044>
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __USBD_CONF__H__
#define __USBD_CONF__H__

/* Includes ------------------------------------------------------------------*/
#include "usb_conf.h"

/** @defgroup USB_CONF_Exported_Defines
  * @{
  */ 
#define USE_USB_OTG_FS  

#define USBD_CFG_MAX_NUM           1
#define USB_MAX_STR_DESC_SIZ       255 
#define USBD_EP0_MAX_PACKET_SIZE   64

#define USBD_ITF_MAX_NUM           1
#define USBD_SELF_POWERED
#define CDC_IN_EP                  0x81
#define CDC_OUT_EP                 0x01
#define CDC_CMD_EP                 0x82

#define CDC_DATA_MAX_PACKET_SIZE   64
#define CDC_CMD_PACKET_SZE        8

#define CDC_IN_FRAME_INTERVAL      100
#define APP_RX_DATA_SIZE           128   

#define APP_FOPS                   vcp_fops
/**
  * @}
  */ 


/** @defgroup USB_CONF_Exported_Types
  * @{
  */ 
/**
  * @}
  */ 


/** @defgroup USB_CONF_Exported_Macros
  * @{
  */ 
/**
  * @}
  */ 

/** @defgroup USB_CONF_Exported_Variables
  * @{
  */ 
/**
  * @}
  */ 

/** @defgroup USB_CONF_Exported_FunctionsPrototype
  * @{
  */ 
/**
  * @}
  */ 


#endif //__USBD_CONF__H__

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

