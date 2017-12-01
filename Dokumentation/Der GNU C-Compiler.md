# Der GNU C-Compiler #

- [Der GNU C-Compiler](#der-gnu-c-compiler)
    - [Beispiel](#beispiel)
    - [C-Standard festlegen](#c-standard-festlegen)
        - [ANSI Standard(C90)](#ansi-standardc90)
        - [ISO-Standard(C99)](#iso-standardc99)
    - [Dateitypen](#dateitypen)
    - [Auswahl einiger Schalter für gcc](#auswahl-einiger-schalter-f%C3%BCr-gcc)
        - [Beispiel -D](#beispiel--d)

- C-Compiler: cc (Alias für gcc)
- C++-Compiler: c++ (Alias für g++)
- C-Präprozessor: cpp
- Assembler: as
- Linker: ld

## Beispiel ##

> **moritz@Latitude-E5520 ~ $** vi Hello.c

```c
#include <stdio.h>

int main (int argc, char **args) {
    printf("Hello Linux World\n");
    return 0;
}
```
>:wq!

> **moritz@Latitude-E5520 ~ $** gcc Hello.c -o "Hello World"  
> **moritz@Latitude-E5520 ~ $** ./Hello\ World  
> Hello Linux World  
> **moritz@Latitude-E5520 ~ $**

## C-Standard festlegen ##

### ANSI Standard(C90) ###

> **moritz@Latitude-E5520 ~ $** gcc **-ansi** Hello.c -o "Hello World"

oder

> **moritz@Latitude-E5520 ~ $** gcc **-std=c90** Hello.c -o "Hello World"

### ISO-Standard(C99) ###

> **moritz@Latitude-E5520 ~ $** gcc **-std=c99** Hello.c -o "Hello World"

Ein weiterer Schalter warnt, falls Code nicht ISO-konform ist:

> **moritz@Latitude-E5520 ~ $** gcc -o "Hello World" **-pedantic** Hello.c

Ein weiterer oft benutzter Schalter gibt eine vielzahl Compiler-Warnungen und Hinweise

> **moritz@Latitude-E5520 ~ $** gcc -o "Hello World" **-Wall** Hello.c

## Dateitypen ##

Der gcc erkennt eine Reihe von Dateitypen anhand deren Endung
|Endung |Erklärung                          |
|-------|-----------------------------------|
|.c     |C-Quellcode                        |
|.h     |C-Headerdatei                      |
|.C, .cc|C++-Quellcodedatei                 |
|.cxx (cpp)|                                |
|.m     |Objective-C Quellcode              |
|.s, .S |Assemblerdatei                     |
|.i     |Präprozessierte C-Quelltextdatei   |
|.ii    |Präprozessierte C++-Quelltextdatei |
|.o     |übersetzte Objektdatei             |
|.a     |übersetzte Bibliotheksdatei        |

.o und .a zur übergabe an den Linker

## Auswahl einiger Schalter für gcc ##

| Schalter          | Erklärung                                                     |
|-------------------|---------------------------------------------------------------|
|-o name            | Name der Outputdatei                                          |
|-g, -ggdb          | Fügt Debug-Symbole hinzu                                      |
|-c                 | Nur kompilieren, nicht linken                                 |
|-E                 | Nur Präprozessorlauf                                          |
|-S                 | Nur Assembler                                                 |
|-v                 | Ausführliche Ausgabe                                          |
|-I directory       | Ergänzt Suchpfad für Include-Dateien                          |
|-L directory       | Ergänzt Suchpfad für Bibliotheksdateien                       |
|-l name            | Linker soll Bibliothek libname.so oder libname.a einbinden    |
|-D name = [wert]   | Fügt name als Makro für den Präprozessor ein                  |
|-m machineType     | Kompiliert für Prozessorachitektur                            |

### Beispiel -D ###

```c
#include <stdio.h>

#ifdef SCHALTER
int num() {return 3; }
#else
int num() {return 9; }
#endif

int main (int argc, char **args) {
    printf("%d\n", num());
    return 0;
}
```

> **moritz@Latitude-E5520 ~ $** gcc Hello.c -o Number -DSCHALTER  
> **moritz@Latitude-E5520 ~ $** ./Number  
> 3  
> **moritz@Latitude-E5520 ~ $** gcc Hello.c -o Number  
> **moritz@Latitude-E5520 ~ $** ./Number  
> 9

