#include "gpio.hpp"
#include "heartBit.hpp"

#include <avr/interrupt.h>

/**
 * Inicjalizacja przerwań.
 */
void interruptsInitialize()
{
}

/**
 * Obsługa przerwania INT0.
 */
ISR(PCINT1_vect)
{
}

/**
 * Pętla główna.
 */
void mainLoop()
{
	heartBit();
	handleKey();
}

/**
 * Funkcja główna.
 */
int main()
{
	gpioInitialize();
	interruptsInitialize();

	while (true) {
		mainLoop();
	}
}
