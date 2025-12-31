#include<stdio.h>

typdef enum {DRV_READY, DRV_BUSY, DRV_ERROR} drv_state_t;

typedef struct {
  void* instance;    // Which device (instance pointer)
  int baud;          // init config
  drv_state_t state; // Runtime State
  int last_error;    // Debug / Status
} UartHandle;

int UART_Init(UartHandle* h);
int UART_Write(UartHandle* h, const char* s);
void example(void);

int main(void) {
  example();
  return 0;
}

int UART_Init(UartHandle* h) {
  h -> state = DRV_READY;
  h -> last_error = 0;
  return 1;
}

int UART_Write(UartHandle* h, const char* s) {
  if (h -> state != DRV_READY) return 0;
  h -> state = DRV_BUSY;

  // Pretend we send bytes...
  while(*s) { s++; /* Send Bytes*/ }

  h -> state = DRV_READY;
  return 1;
}

void example(void) {
  UartHandle uart1 = { .instance = (void*)0x4000, .baud = 115200} ;
  UartHandle uart2 = { .instance = (void*)0x5000, .baud = 9600} ;

  UART_Init(&uart1);
  UART_Init(&uart2);

  UART_Write(&uart1, "fast\n");
  UART_Write(&uart1, "slow\n");

}
