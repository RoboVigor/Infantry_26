/**
 * @file Driver_Remote.h
 * @brief 遥控器驱动
 */

#ifndef __Driver_Remote_H
#define __Driver_Remote_H

#include "stm32f4xx.h"
#include "vegmath.h"
#include "macro.h"

#ifdef CONTROLLED_BY_DBUS
// DBUS接收数据帧长度
#define REMOTE_LENGTH 18     // DBUS数据帧长
#define REMOTE_BACK_LENGTH 1 // 增加一个字节保持稳定

#define REMOTE_USART USART1
#define REMOTE_USART_RX USART1_Rx
#define REMOTE_USART_TX USART1_Tx

#define USART_INIT_PARAMS                                                                                                                                      \
    USART1, RCC_AHB1Periph_GPIOB, GPIO_AF_USART1, GPIO_PinSource7, GPIO_PinSource7, GPIO_Pin_7, GPIOB, RCC_APB2, RCC_APB2Periph_USART1, USART_Mode_Rx,         \
        USART1_IRQn, 8, REMOTE_BAUD_RATE, USART_IT_IDLE

#define REMOTE_RCC_AHB1Periph_DMA RCC_AHB1Periph_DMA2
#define REMOTE_DMA_STREAM DMA2_Stream2
#define REMOTE_DMA_CHANNEL DMA_Channel_4

#else
// VT13图传接收数据帧长度
#define REMOTE_LENGTH 21     // DBUS数据帧长
#define REMOTE_BACK_LENGTH 1 // 增加一个字节保持稳定

#define REMOTE_USART UART7
#define REMOTE_USART_RX UART7_Rx
#define REMOTE_USART_TX UART7_Tx

#define USART_INIT_PARAMS                                                                                                                                      \
    UART7, RCC_AHB1Periph_GPIOE, GPIO_AF_UART7, GPIO_PinSource8, GPIO_PinSource7, GPIO_Pin_7, GPIOE, RCC_APB1, RCC_APB1Periph_UART7, USART_Mode_Rx,            \
        UART7_IRQn, 8, REMOTE_BAUD_RATE, USART_IT_IDLE

#define REMOTE_RCC_AHB1Periph_DMA RCC_AHB1Periph_DMA1
#define REMOTE_DMA_STREAM DMA1_Stream3
#define REMOTE_DMA_CHANNEL DMA_Channel_5

#endif

// 所有按键对应位
#define KEY_V 0x4000
#define KEY_C 0x2000
#define KEY_X 0x1000
#define KEY_Z 0x0800
#define KEY_G 0x0400
#define KEY_F 0x0200
#define KEY_R 0x0100
#define KEY_E 0x0080
#define KEY_Q 0x0040
#define KEY_CTRL 0x0020
#define KEY_SHIFT 0x0010
#define KEY_D 0x0008
#define KEY_A 0x0004
#define KEY_S 0x0002
#define KEY_W 0x0001

enum DBusState { RemoteIdle, RemoteWorking };
typedef enum { OFF, ON } ButtonState;

typedef struct {
    ButtonState state;
    ButtonState laststate;
    ButtonState isPressed;
} Button_Type;

// 遥控解码数据存储结构体
typedef struct {
#ifdef CONTROLLED_BY_DBUS
    // 遥控解码数据存储结构体
    union {
        struct {
            int16_t rx, ry, lx, ly;
        };
        struct {
            int16_t ch1, ch2, ch3, ch4;
        };
    };

    enum DBusState state;

    uint8_t switchLeft; // 3 value
    uint8_t switchRight;

#else
    // VT13图传解码数据存储结构体
    union {
        struct {
            int16_t rx, ry, ly, lx;
        };
        struct {
            int16_t ch1, ch2, ch3, ch4;
        };
    };

    enum DBusState state;

    uint8_t     gearSwitch; // 3 value
    Button_Type buttonPause;
    Button_Type buttonLeft;
    Button_Type buttonRight;
    int16_t     dial; // 11位
    uint8_t     trigger;

#endif
} Remote_Type;

typedef struct {
    int16_t x;
    int16_t y;
    int16_t z;

    uint8_t pressLeft;
    uint8_t pressRight;
} Mouse_Type;

/**********************************************************************************
 * 键盘通道:15   14   13   12   11   10   9   8   7   6     5     4   3   2   1
 *          V    C    X	   Z    G    F    R   E   Q  CTRL  SHIFT  D   A   S   W
 ************************************************************************************/

typedef struct {
    union {
        struct {
            unsigned int W : 1;
            unsigned int S : 1;
            unsigned int A : 1;
            unsigned int D : 1;
            unsigned int Shift : 1;
            unsigned int Ctrl : 1;
            unsigned int Q : 1;
            unsigned int E : 1;
            unsigned int R : 1;
            unsigned int F : 1;
            unsigned int G : 1;
            unsigned int Z : 1;
            unsigned int X : 1;
            unsigned int C : 1;
            unsigned int V : 1;
        };
        struct {
            uint16_t keyCode;
        };
    };
    uint16_t keyDisabledCounter[15];
    uint16_t keyDisabledCode;
    uint16_t seq;

    enum DBusState state;
} Keyboard_Type;

void Remote_Init(Remote_Type *remote, Keyboard_Type *kb, Mouse_Type *mouse);

/**
 * @brief 遥控器解码
 *
 * @param remoteData
 */

void Remote_Update(Remote_Type *remote, Keyboard_Type *kb, Mouse_Type *mouse, uint8_t RemoteBuffer[]);

/**
 * @brief 暂时禁用某键
 *
 * @param kb
 * @param key 宏定义KEY_X
 * @param duration 禁用时间 (ms)
 */
void Key_Disable(Keyboard_Type *kb, uint16_t key, uint16_t duration);

#endif
