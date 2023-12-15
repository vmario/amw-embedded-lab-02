#pragma once

/**
 * Numery pinów powiązane z LED-ami.
 */
enum PIN_LED {
	PIN_LED_HEART_BIT = 5, ///< Dioda rytmicznie mrugająca.
	PIN_LED_KEY = 4, ///< Dioda reagująca wprost na przycisk.
	PIN_LED_TOGGLE = 3, ///< Dioda przełączana przyciskiem.
};

/**
 * Numery pinów powiązane z przyciskami.
 */
enum PIN_KEY {
	PIN_KEY_A1 = 1, ///< Przycisk włączający diodę na PIN_LED_KEY.
};

/**
 * Zaświeca diodę na wskazanym pinie.
 * 
 * @param pinLed Wskazany pin.
 */
void ledOn(enum PIN_LED pinLed);

/**
 * Gasi diodę na wskazanym pinie.
 * 
 * @param pinLed Wskazany pin.
 */
void ledOff(enum PIN_LED pinLed);

/**
 * Zmienia stan diody na wskazanym pinie.
 * 
 * @param pinLed Wskazany pin.
 */
void ledToggle(enum PIN_LED pinLed);

/**
 * Obsługuje wciśnięcie klawisza.
 */
void handleKey();

/**
 * Inicjalizuje porty GPIO.
 */
void gpioInitialize();
