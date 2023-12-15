#include "gpio.hpp"

#include <avr/io.h>

void ledOn(enum PIN_LED pinLed)
{
	PORTB &= ~_BV(pinLed);
}

void ledOff(enum PIN_LED pinLed)
{
	PORTB |= _BV(pinLed);
}

void ledToggle(enum PIN_LED pinLed)
{
	PORTB ^= _BV(pinLed);
}

void handleKey()
{
	if (bit_is_clear(PINC, PIN_KEY_A1)) {
		ledOn(PIN_LED_KEY);
	} else {
		ledOff(PIN_LED_KEY);
	}
}

void gpioInitialize()
{
	DDRB = _BV(PIN_LED_HEART_BIT) | _BV(PIN_LED_KEY) | _BV(PIN_LED_TOGGLE);
	PORTB = _BV(PIN_LED_HEART_BIT) | _BV(PIN_LED_KEY) | _BV(PIN_LED_TOGGLE);
}
