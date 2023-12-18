---
title: "Ćwiczenie 2: Przerwania GPIO"
author: [Mariusz Chilmon <<mariusz.chilmon@ctm.gdynia.pl>>]
lang: "pl"
titlepage: no
colorlinks: yes
header-right: "\\faEdit"
footer-left: "Sprawozdanie z laboratorium"
header-includes: |
  \usepackage{awesomebox}
  \usepackage{tikz}
  \usetikzlibrary{positioning}
  \tikzset{
  pics/byte cube/.style args = {#1,#2}{
      code = {
         \draw[fill=white] (0,0) rectangle (1,1);
         \node at (0.5,0.5){#1};
         \draw[cube #1] (0,0)--(-60:2mm)--++(1,0)--++(0,1)--++(120:2mm)--(1,0)--cycle;
         \draw(1,0)--++(-60:2mm);
         \node at (0.5,-0.5){$2^{#2}$};
      }
    },
    cube 1/.style = {fill=gray!30}, % style for bytes that are "on"
    cube 0/.style = {fill=white},   % style for bytes that are "off"
  }

  \newcommand\BinaryNumber[1]{%
  \begin{tikzpicture}
     % count the number of bytes and store as \C
     \foreach \i [count=\c] in {#1} { \xdef\C{\c} }
     \foreach \i [count=\c, evaluate=\c as \ex using {int(\C-\c)}] in {#1} {
       \pic at (\c, 1) {byte cube={\i,\ex}};
     }
  \end{tikzpicture}

    }
...

_W trosce o Państwa wyniki proszę o czytelne wpisywanie nazwisk._

**Data**: \dotfill

**Autorzy**: \dotfill

# Część praktyczna

## Zadanie podstawowe

**Ocena prowadzącego**: \dotfill

## Zadanie rozszerzone

**Ocena prowadzącego**: \dotfill

# Część teoretyczna

## Zadanie podstawowe

\begin{tikzpicture}[node distance=0mm,
box/.style={draw, minimum height=7mm, minimum width=18mm},
label/.style={font=\bfseries, minimum height=7mm, minimum width=18mm},
value/.style={yshift=7mm}]
\node[box] (b7)               {---};
\node[box] (b6) [right=of b7] {---};
\node[box] (b5) [right=of b6] {---};
\node[box] (b4) [right=of b5] {---};
\node[box] (b3) [right=of b4] {---};
\node[box] (b2) [right=of b3] {PCIE2};
\node[box] (b1) [right=of b2] {PCIE1};
\node[box] (b0) [right=of b1] {PCIE0};
\node[label] [right=of b0] {PCICR};
\node[value] [above of=b7] {7};
\node[value] [above of=b6] {6};
\node[value] [above of=b5] {5};
\node[value] [above of=b4] {4};
\node[value] [above of=b3] {3};
\node[value] [above of=b2] {2};
\node[value] [above of=b1] {1};
\node[value] [above of=b0] {0};
\end{tikzpicture}

\begin{tikzpicture}[node distance=0mm,
box/.style={draw, minimum height=7mm, minimum width=18mm},
label/.style={font=\bfseries, minimum height=7mm, minimum width=18mm},
value/.style={yshift=7mm}]
\node[box] (b7)               {PCINT23};
\node[box] (b6) [right=of b7] {PCINT22};
\node[box] (b5) [right=of b6] {PCINT21};
\node[box] (b4) [right=of b5] {PCINT20};
\node[box] (b3) [right=of b4] {PCINT19};
\node[box] (b2) [right=of b3] {PCINT18};
\node[box] (b1) [right=of b2] {PCINT17};
\node[box] (b0) [right=of b1] {PCINT16};
\node[label] [right=of b0] {PCMSK2};
\node[value] [above of=b7] {7};
\node[value] [above of=b6] {6};
\node[value] [above of=b5] {5};
\node[value] [above of=b4] {4};
\node[value] [above of=b3] {3};
\node[value] [above of=b2] {2};
\node[value] [above of=b1] {1};
\node[value] [above of=b0] {0};
\end{tikzpicture}

\begin{tikzpicture}[node distance=0mm,
box/.style={draw, minimum height=7mm, minimum width=18mm},
label/.style={font=\bfseries, minimum height=7mm, minimum width=18mm},
value/.style={yshift=7mm}]
\node[box] (b7)               {---};
\node[box] (b6) [right=of b7] {PCINT14};
\node[box] (b5) [right=of b6] {PCINT13};
\node[box] (b4) [right=of b5] {PCINT12};
\node[box] (b3) [right=of b4] {PCINT11};
\node[box] (b2) [right=of b3] {PCINT10};
\node[box] (b1) [right=of b2] {PCINT9};
\node[box] (b0) [right=of b1] {PCINT8};
\node[label] [right=of b0] {PCMSK1};
\node[value] [above of=b7] {7};
\node[value] [above of=b6] {6};
\node[value] [above of=b5] {5};
\node[value] [above of=b4] {4};
\node[value] [above of=b3] {3};
\node[value] [above of=b2] {2};
\node[value] [above of=b1] {1};
\node[value] [above of=b0] {0};
\end{tikzpicture}

\begin{tikzpicture}[node distance=0mm,
box/.style={draw, minimum height=7mm, minimum width=18mm},
label/.style={font=\bfseries, minimum height=7mm, minimum width=18mm},
value/.style={yshift=7mm}]
\node[box] (b7)               {PCINT7};
\node[box] (b6) [right=of b7] {PCINT6};
\node[box] (b5) [right=of b6] {PCINT5};
\node[box] (b4) [right=of b5] {PCINT4};
\node[box] (b3) [right=of b4] {PCINT3};
\node[box] (b2) [right=of b3] {PCINT2};
\node[box] (b1) [right=of b2] {PCINT1};
\node[box] (b0) [right=of b1] {PCINT0};
\node[label] [right=of b0] {PCMSK0};
\node[value] [above of=b7] {7};
\node[value] [above of=b6] {6};
\node[value] [above of=b5] {5};
\node[value] [above of=b4] {4};
\node[value] [above of=b3] {3};
\node[value] [above of=b2] {2};
\node[value] [above of=b1] {1};
\node[value] [above of=b0] {0};
\end{tikzpicture}

\begin{tikzpicture}[node distance=0mm,
box/.style={draw, minimum height=7mm, minimum width=18mm},
label/.style={font=\bfseries, minimum height=7mm, minimum width=18mm},
value/.style={yshift=7mm}]
\node[box] (b7)               {I};
\node[box] (b6) [right=of b7] {T};
\node[box] (b5) [right=of b6] {H};
\node[box] (b4) [right=of b5] {S};
\node[box] (b3) [right=of b4] {V};
\node[box] (b2) [right=of b3] {N};
\node[box] (b1) [right=of b2] {Z};
\node[box] (b0) [right=of b1] {C};
\node[label] [right=of b0] {SREG};
\node[value] [above of=b7] {7};
\node[value] [above of=b6] {6};
\node[value] [above of=b5] {5};
\node[value] [above of=b4] {4};
\node[value] [above of=b3] {3};
\node[value] [above of=b2] {2};
\node[value] [above of=b1] {1};
\node[value] [above of=b0] {0};
\end{tikzpicture}

Opisz przeznaczenie rejestrów `DDR`, `PIN` i `PORT`. Zwróć uwagę na znaczenie rejestrów `PORT` w&nbsp;zależności od kierunku portu.

`DDR` --- 
\vspace{1.5cm}

`PIN` --- 
\vspace{1.5cm}

`PORT` w przypadku pinu wejściowego --- 
\vspace{1.5cm}

`PORT` w przypadku pinu wyjściowego --- 
\vspace{1.5cm}

## Zadanie rozszerzone

Podaj efekt kompilacji instrukcji zapisu stanu portu `PORTB = 0b00001000`, ustawienia pojedynczego bitu `PORTB |= 0b00001000` i ustawienia wielu bitów `PORTB |= 0b00101000`. Opisz instrukcje, które zastosował kompilator:

`PORTB  = 0b00001000` $\longrightarrow$
\vspace{1.5cm}

`PORTB |= 0b00001000` $\longrightarrow$
\vspace{1.5cm}

`PORTB |= 0b00101000` $\longrightarrow$
\vspace{1.5cm}

\awesomebox[teal]{2pt}{\faCode}{teal}{Zwróć uwagę, że w językach C i C++ operator przypisania \lstinline{=} jest na ogół prostszy niż operator przypisania złożonego z alternatywą bitową \lstinline{|=}, który standardowo wymaga odczytania zmiennej, wykonania operacji \lstinline{|} i zapisania wyniku do tej zmiennej. Tu jednak możliwe jest wykorzystanie dedykowanej instrukcji, o ile ustawiamy pojedynczy bit.}
