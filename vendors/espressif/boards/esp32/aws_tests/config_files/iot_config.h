/*
 * Copyright (C) 2018 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

/* This file contains configuration settings for the demos. */

#ifndef IOT_CONFIG_H_
#define IOT_CONFIG_H_

/* Standard include. */
#include <stdbool.h>

/**
 *  ESP log header file include to override with ESP logging.
 *  Un-comment to enable ESP logging override
 */
//#include "esp_log.h"


/* Platform thread stack size and priority. */
#define IOT_THREAD_DEFAULT_STACK_SIZE    5000
#define IOT_THREAD_DEFAULT_PRIORITY      5

/* Provide additional serializer initialization functions. */
extern bool IotBleMqtt_InitSerialize( void );
extern void IotBleMqtt_CleanupSerialize( void );
#define _IotMqtt_InitSerializeAdditional IotBleMqtt_InitSerialize
#define _IotMqtt_CleanupSerializeAdditional IotBleMqtt_CleanupSerialize

/* Network type configuration for this board. */
#define DEFAULT_NETWORK    AWSIOT_NETWORK_TYPE_WIFI
#define BLE_SUPPORTED      ( 1 )
#define WIFI_SUPPORTED     ( 1 )

#define IOT_LOG_LEVEL_GLOBAL                    IOT_LOG_INFO
#define IOT_LOG_LEVEL_DEMO                      IOT_LOG_INFO
#define IOT_LOG_LEVEL_PLATFORM                  IOT_LOG_NONE
#define IOT_LOG_LEVEL_NETWORK                   IOT_LOG_INFO
#define IOT_LOG_LEVEL_TASKPOOL                  IOT_LOG_NONE
#define IOT_LOG_LEVEL_MQTT                      IOT_LOG_INFO
#define AWS_IOT_LOG_LEVEL_SHADOW                IOT_LOG_INFO
#define AWS_IOT_LOG_LEVEL_DEFENDER              IOT_LOG_INFO

/**
 * Override  FreeRTOS IotLog macro to above macros.
 * Un-comment the macro to enable ESP logging override.
 */
/**
#define IotLog( messageLevel, pLogConfig, format, ... )                                                      \
    do {                                                                                                     \
       if( ( messageLevel > 0 ) && ( messageLevel <= LIBRARY_LOG_LEVEL ) )                                   \
       {                                                                                                     \
           if( messageLevel == IOT_LOG_INFO )       { ESP_LOGI( LIBRARY_LOG_NAME, format, ##__VA_ARGS__ ); } \
           else if( messageLevel == IOT_LOG_DEBUG ) { ESP_LOGD( LIBRARY_LOG_NAME, format, ##__VA_ARGS__ ); } \
           else if( messageLevel == IOT_LOG_WARN )  { ESP_LOGW( LIBRARY_LOG_NAME, format, ##__VA_ARGS__ ); } \
           else if( messageLevel == IOT_LOG_ERROR ) { ESP_LOGE( LIBRARY_LOG_NAME, format, ##__VA_ARGS__ ); } \
       }                                                                                                     \
    } while(0);
*/


/* Include the common configuration file for FreeRTOS. */
#include "iot_config_common.h"

#endif /* ifndef IOT_CONFIG_H_ */
