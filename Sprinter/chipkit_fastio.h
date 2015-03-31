#ifndef		MASK
/// MASKING- returns \f$2^PIN\f$
	#define		MASK(PIN)				(1 << PIN)
#endif

/// Read a pin
#define		_READ(IO)			((bool)(DIO ## IO ## _RPORT & MASK(DIO ## IO ## _PIN)))
/// write to a pin
#define		_WRITE(IO, v)		do { if (v) {DIO ##  IO ## _WPORT |= MASK(DIO ## IO ## _PIN); } else {DIO ##  IO ## _WPORT &= ~MASK(DIO ## IO ## _PIN); }; } while (0)
/// toggle a pin
#define		_TOGGLE(IO)			do {DIO ##  IO ## _RPORT = MASK(DIO ## IO ## _PIN); } while (0)

/// set pin as input
#define		_SET_INPUT(IO)		do {DIO ##  IO ## _DDRI =    MASK(DIO ## IO ## _PIN); } while (0)
/// set pin as output
#define		_SET_OUTPUT(IO)		do {DIO ##  IO ## _DDRO =    MASK(DIO ## IO ## _PIN); } while (0)

/// check if pin is an input
#define		_GET_INPUT(IO)		((DIO ## IO ## _DDR & MASK(DIO ## IO ## _PIN)) == 0)
/// check if pin is an output
#define		_GET_OUTPUT(IO)		((DIO ## IO ## _DDR & MASK(DIO ## IO ## _PIN)) != 0)

//	why double up on these macros? see http://gcc.gnu.org/onlinedocs/cpp/Stringification.html

/// Read a pin wrapper
#define		READ(IO)				_READ(IO)
/// Write to a pin wrapper
#define		WRITE(IO, v)			_WRITE(IO, v)
/// toggle a pin wrapper
#define		TOGGLE(IO)				_TOGGLE(IO)

/// set pin as input wrapper
#define		SET_INPUT(IO)			_SET_INPUT(IO)
/// set pin as output wrapper
#define		SET_OUTPUT(IO)		_SET_OUTPUT(IO)

/// check if pin is an input wrapper
#define		GET_INPUT(IO)			_GET_INPUT(IO)
/// check if pin is an output wrapper
#define		GET_OUTPUT(IO)		_GET_OUTPUT(IO)

// UNO32

// UART
#define	RXD					DIO0 // pin # for a specific board
#define	TXD					DIO1

// SPI
#define	SCK					DIO13
#define	MISO				DIO12
#define	MOSI				DIO11
#define	SS					DIO10

// TWI (I2C)
#define	SCL					AIO5
#define	SDA					AIO4

// timers and PWM
#define	OC0A				DIO6
#define	OC0B				DIO5
#define	OC1A				DIO9
#define	OC1B				DIO10
#define	OC2A				DIO11
#define	OC2B				DIO3

#define	DEBUG_LED		AIO5

/*
pins
*/
#include "uno32_pins.h"

