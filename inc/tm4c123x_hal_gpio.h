
#ifndef __TM4C123x_HAL_GPIO_H
#define __TM4C123x_HAL_GPIO_H

#ifdef __cplusplus
  extern "C" {
#endif

typedef struct {
  uint32_t Pin;
  uint32_t Mode;
  uint32_t Pull;
  uint32_t Speed;
  uint32_t Alternative;

}GPIO_InitTypeDef;

void HAL_GPIO_Init();
void HAL_GPIO_Read();
void HAL_GPIO_Write();
void HAL_GPIO_TogglePin();


