#include <avr\io.h>

void UART_init(unsigned int baud);
void UART_TRANSMIT( unsigned char data );
unsigned char UART_RECIEVE( void );
void UART_SendStr( char* data );
