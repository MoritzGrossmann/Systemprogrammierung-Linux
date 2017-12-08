# Der GNU C-Debugger #

- [Der GNU C-Debugger](#der-gnu-c-debugger)
    - [Grundlegende Kommandos](#grundlegende-kommandos)
    - [Weitere Kommandos](#weitere-kommandos)
        - [Breakpoints](#breakpoints)
            - [Setzen eines BReakpoints](#setzen-eines-breakpoints)
            - [Anzeigen der BReakpoints](#anzeigen-der-breakpoints)
            - [Löschen eines Breakpoints](#l%C3%B6schen-eines-breakpoints)
        - [Ablaufen des Programmes bis zum nächsten Breakpoint](#ablaufen-des-programmes-bis-zum-n%C3%A4chsten-breakpoint)
        - [Überwachen von Ausdrücken](#%C3%BCberwachen-von-ausdr%C3%BCcken)
        - [Inspektion von Speicher](#inspektion-von-speicher)
        - [Inspektion eines Core-dump](#inspektion-eines-core-dump)

## Grundlegende Kommandos ##

Der GNU C-Debugger akzeptiert eine Vielzahl verschiedener Kommandos. So kann man beispielsweise eine Programm-Datei laden. 

> gdb > file hello

das PRogramm debuggen

> gdb > start

den Quelltext anzeigen 

> gdb > list

oder schrittweise ablaufen lassen

> gdb > step

Hilfe ist jederzeit aufrufbar

> gdb > help

## Weitere Kommandos ##

### Breakpoints ##

#### Setzen eines BReakpoints ####

> gdb > break &lt;linenumber>

> gdb > break &lt;function>

#### Anzeigen der BReakpoints ####

> gdb > info breakpoints

#### Löschen eines Breakpoints ####

> gdb > delete &lt;breakpoint#>

### Ablaufen des Programmes bis zum nächsten Breakpoint ###

> gdb > run

### Überwachen von Ausdrücken ###

> gdb displey &lt;ausdruck>

### Inspektion von Speicher ###

> gdb > print &lt;variable>

### Inspektion eines Core-dump ###

> gdb > core &lt;core-datei>