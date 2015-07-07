/* to deal with UART we need to deal with 5 registers

UDR    data register 

UBRRH 		pin7		pin6		pin5		pin4		pin3		pin2		pin1		pin0
			URSEL														THE MOST BITS OF UBR VALUE
	    SELECT UBRR OR UCSRB
		
UBRRL			CONTAIN THE RESET BIT OF UBR VALUE

UCSRA		pin7		pin6				pin5		pin4		pin3		pin2		pin1		pin0
			RXC			TXC					UDRE		FE			DOR			PE			U2X			MPCM	
			RECIEVE						   TRANSMIT		FRAME		ENABLE		CHECK		BOUBLE			
			COMPLETE FLAG	  			   COMPLETE	    ERROR	   COLLISION	PARITY		BAUD RATE				

UCSRB		RXCIE		TXCIE				UDRIE		RXEN		TXEN		USCZ0		RXB8		TXB8
						ENABLE INTEERUPTS				ENABLE		ENABLE					IF I SEND 9 BIT
			@RECIEVE   @TRANSMIT		 @DATA BUFFER				RECIEVER	TRANSMITTER					
											EMPTY
			
UCSRC		URSEL        UMSEL				UPM1		UPM0		USBS		USCZ1		USCZ0		UCP0
			SELECT		SYNCHRO					PARITY BIT			STOP		DETERMINE THE DATA
			UBRR OR		OR											BIT			RATE BITS/FRAME
			UCSRB		ASYN													WITH BIT USCZ0
*/
#include "uart.h"
#include "avr/delay.h"

void UART_init(unsigned int baud)
{
	/* Set baud rate */
	UBRRH = (unsigned char)(baud>>8);
	UBRRL = (unsigned char)baud;
	/* Enable receiver and transmitter */
	UCSRB = (1<<RXEN)|(1<<TXEN);
	/* Set frame format: 8data, 2stop bit */
	UCSRC = (1<<URSEL)|(1<<USBS)|(3<<UCSZ0); //for 1 stop bit
}

void UART_TRANSMIT( unsigned char data )
{
	/* Wait for empty transmit buffer */
	while ( !( UCSRA & (1<<UDRE)) );
	/* Put data into buffer, sends the data */
	UDR = data;
	_delay_ms(50);
}

unsigned char UART_RECIEVE( void )
{
	/* Wait for data to be received */
	while ( !(UCSRA & (1<<RXC)) );
	/* Get and return received data from buffer */
	return UDR;
}

void UART_SendStr( char* data )
{
	int i=0;
	while(data[i] != '\0')
	{
		UART_TRANSMIT(data[i]);
		i++;
	}
}
