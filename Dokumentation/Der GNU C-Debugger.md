# Der GNU C-Debugger #

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