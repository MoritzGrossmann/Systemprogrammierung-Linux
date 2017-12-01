# Aufbau des Betriebssystems #

## Kernel (Hauptbestandteil) ##

- Programme können nur quasi-Parrallel ausgeführt werden

### Sheduler ###

- Unterporogramm vom Kernel
- Weißt Prozessen Ausführungszeit zu
- Wann ist welches Programm aktiv

### Verwaltung Angeschlossener Hardware ###

- Treiberbibliothek
- Großteil des Kernels sind Treiber
- Kernel kann geschrumpft werden auf benötigte Treiber
- beim Bootvorgang werden Treiber geladen

### Init-Prozess ###

- Wurzel aller prozesse
- startet alle weiteren Prozesse

### Shells ###

- Kernel hat gewisse anzahl Schalen
- Kernel öffnet anzahl tty's
- tty's aufrufbar mit Strg + Alt + [F1-7] (7 ist graphische Oberfläche)
- im tty läuft ein Login-Prozess
- nach Anmeldung startet "login" die Benutzershell bzw. die Graphische Oberfläche