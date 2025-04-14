#include "common.h"
#include <memory.h>
#include "usart.h"

uint8_t tx_buffer[LD2410X_MAX_FRAME_LEN] = {0};
uint8_t rx_buffer[LD2410X_MAX_FRAME_LEN] = {0};

LD2410X_INTF_RET_TYPE ld2410x_read(uint8_t *buffer, uint8_t buff_len, void *intf_desc)
{
    (void)intf_desc;
    HAL_UART_Receive(&huart3, buffer, buff_len, 1000);
    memcpy(buffer, rx_buffer, buff_len);
    return 0;
}

LD2410X_INTF_RET_TYPE ld2410x_write(const uint8_t *buffer, uint8_t buff_len, void *intf_desc)
{
    (void)intf_desc;
    HAL_UART_Transmit(&huart3, buffer, buff_len, 1000);
    memcpy(tx_buffer, buffer, buff_len);
    return 0;
}
