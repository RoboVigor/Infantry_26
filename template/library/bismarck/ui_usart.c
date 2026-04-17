#include "ui_usart.h"
#include "Driver_Bridge.h"
#include "handle.h"



void ui_send_message(const uint8_t* message, int length) {
  uint32_t deviceID = Node_Judge.deviceID;
  DMA_Disable(USARTx_Tx);
  delay_ms(1);
  DMA_Set_Memory_Address(USARTx_Tx, (uint32_t)message);
  delay_ms(1);
  DMA_Enable(USARTx_Tx, length);
}