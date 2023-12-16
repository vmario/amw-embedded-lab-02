---
title: "Ćwiczenie 2: Przerwania GPIO"
subtitle: "Instrukcja laboratorium"
footer-left: "Instrukcja laboratorium"
author: [Mariusz Chilmon <<mariusz.chilmon@ctm.gdynia.pl>>]
lang: "pl"
titlepage: yes
titlepage-logo: "logo.png"
logo-width: "70mm"
colorlinks: yes
header-includes: |
  \usepackage{awesomebox}
...

> Remember, things take time.
>
> — _Piet Hein_

# Cel ćwiczenia

Celem ćwiczenia jest zapoznanie się z:

* bezsensewnością odmierzania czasu w pętli głównej,
* korzyściami z wykorzystania przerwań,
* konfiguracją przerwań GPIO,
* uruchamianiem podsystemu przerwań,
* makrem `ISR()` do obsługi przerwań w AVR-GCC.

# Uruchomienie programu wyjściowego

1. Podłącz płytkę _WPSH209_ do _Arduino Uno_.
1. Załóż zworkę `J2`.
1. Zbuduj program i wgraj do mikrokontrolera.
1. Zweryfikuj, czy dioda LED `D1` mruga.
1. Zweryfikuj, czy dioda LED `D2` zaświeca się po wciśnięciu przycisku `A1`.

\awesomebox[teal]{2pt}{\faCode}{teal}{Zauważ, że dioda \lstinline{D2} na ogół zaświeca się i gaśnie z opóźnieniem. Wynika to z~tego, że stan przycisku sprawdzany jest tylko co jakiś czas, między wykonaniami funkcji \lstinline{heartBit()}.}

\awesomebox[teal]{2pt}{\faCode}{teal}{Funkcja \lstinline{heartBit()} symuluje wykonywanie przez pętlę główną złożonego programu. W rzeczywistości funkcja ta prawie całą moc obliczeniową mikrokontrolera zużywa na odmierzanie czasu w funkcji bibliotecznej \lstinline{_delay_ms()}. Jak widzisz, odmierzanie czasu w ten sposób jest bardzo problematyczne.}

# Zadanie podstawowe

## Modyfikacja programu

1. Przenieś wywołanie funkcji `handleKey()` z pętli głównej do obsługi przerwania `PCINT1`, czyli funkcji `ISR(PCINT1_vect)`.
1. W funkcji `interruptsInitialize()` umieść:
   1. włączenie przerwania `PCINT1`;
   1. aktywację tego przerwania przez pin, do którego jest podłączony przycisk `A1`;
   1. odblokowanie globalnej maski przerwań.

\awesomebox[violet]{2pt}{\faBook}{violet}{Zapoznaj się z rejestrami \lstinline{PCICR} i \lstinline{PCMSK1} oraz funkcją \lstinline{sei()}.}

\awesomebox[purple]{2pt}{\faMicrochip}{purple}{Piny mikrokontrolera (wybrane lub dowolne, zależnie od możliwości mikrokontrolera) mogą przerywać działanie pętli głównej, np. po pojawieniu się zbocza. Umożliwia to szybką reakcję na zdarzenie zewnętrzne.

Zazwyczaj mikrokontrolery z rodziny ATmega posiadają kilka pinów obsługujących przerwania \lstinline{INTX} (np. \lstinline{INT0}, \lstinline{INT1}...), które można skonfigurować w dowolny sposób (np. reakcja tylko na zbocze opadające) oraz zestaw przerwań \lstinline{PCINTX}, umożliwiających reakcję na zmianę stanu na pozostałych pinach, pogrupowanych w ośmioelementowe bloki.}

## Wymagania funkcjonalne

1. Dioda `D1` miga bez zmian.
1. Dioda `D2` reaguje natychmiast na wciśnięcia przycisku `A1`.

# Zadanie rozszerzone

## Modyfikacja programu

Zmodyfikuj pętlę główną i obsługę przerwania tak, by po wciśnięciu przycisku była ustawiana zmienna, która zmieni w pętli głównej stan diody `D3` na przeciwny.

\awesomebox[teal]{2pt}{\faCode}{teal}{Do zmiany stanu diody na przeciwny możesz użyć funkcji \lstinline{ledToogle(PIN_LED_TOGGLE)}.}

\awesomebox[teal]{2pt}{\faCode}{teal}{Pamiętaj o kwalifikatorze typu \lstinline{volatile}.}

## Wymagania funkcjonalne

1. Dioda `D1` miga bez zmian.
1. Dioda `D2` reaguje natychmiast na wciśnięcia przycisku `A1`.
1. Dioda `D3` zmienia stan na przeciwny z opóźnieniem, wynikającym z działania pętli głównej.

\awesomebox[teal]{2pt}{\faCode}{teal}{W tym zadaniu wykorzystujemy przerwanie nie do tego, by zareagować natychmiast na zdarzenie, ale tylko do tego, by je zarejestrować i obsłużyć później w pętli głównej. W~ten sposób często obsługiwane są zdarzenia, które wymagają czasochłonnych operacji. Dzięki takiemu podejściu procesor nie utyka na dłuższy czas w obsłudze przerwania.}
