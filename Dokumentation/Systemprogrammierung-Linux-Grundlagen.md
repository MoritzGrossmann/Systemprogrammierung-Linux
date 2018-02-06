# Aufbau des Betriebssystems #

- [Aufbau des Betriebssystems](#aufbau-des-betriebssystems)
    - [Kernel (Hauptbestandteil)](#kernel-hauptbestandteil)
        - [Scheduler](#scheduler)
        - [Verwaltung Angeschlossener Hardware](#verwaltung-angeschlossener-hardware)
        - [Init-Prozess](#init-prozess)
        - [Shells](#shells)
- [Der Bootvorgang](#der-bootvorgang)
    - [dmesg](#dmesg)
    - [Verzeichnis /boot](#verzeichnis-boot)
    - [Logfiles](#logfiles)
        - [syslogd](#syslogd)
        - [journalctl](#journalctl)
- [Aufbau des Dateisystems](#aufbau-des-dateisystems)
    - [/bin](#bin)
    - [/dev](#dev)
        - [Bsp.: Festplatten](#bsp-festplatten)
            - [Nach Pfad](#nach-pfad)
            - [Nach UUID](#nach-uuid)
    - [/etc](#etc)
    - [/lib](#lib)
    - [/mnt](#mnt)
    - [/media](#media)
    - [/proc](#proc)
    - [/sbin](#sbin)
    - [/usr](#usr)
        - [/usr/share](#usr-share)
        - [/usr/local](#usr-local)
    - [/run](#run)
    - [/var](#var)
    - [/sys](#sys)
        - [/sys/module](#sys-module)
- [Bash-Befehle](#bash-befehle)
    - [Wichtige Befehle](#wichtige-befehle)
        - [ps](#ps)
        - [ls](#ls)
        - [less](#less)
            - [Bsp.: Benutzer Anzeigen](#bsp-benutzer-anzeigen)
            - [Bsp.: Passwörter der Benutzer](#bsp-passw-rter-der-benutzer)
        - [passwd](#passwd)
        - [sudo](#sudo)
        - [Jobs](#jobs)
            - [Bsp.: ping &lt;url>](#bsp-ping-lt-url)
- [UNIX-Standards](#unix-standards)
    - [IEEE](#ieee)
    - [X / Open-Gruppe (heute Open Group)](#x-open-gruppe-heute-open-group)
    - [In Programmiersprache C](#in-programmiersprache-c)
- [Der GNU C-Compiler](#der-gnu-c-compiler)
    - [Beispiel](#beispiel)
    - [C-Standard festlegen](#c-standard-festlegen)
        - [ANSI Standard(C90)](#ansi-standard-c90)
        - [ISO-Standard(C99)](#iso-standard-c99)
    - [Dateitypen](#dateitypen)
    - [Auswahl einiger Schalter für gcc](#auswahl-einiger-schalter-f-r-gcc)
        - [Beispiel -D](#beispiel-d)
- [2.2 Verwendung von Makefiles](#2-2-verwendung-von-makefiles)
    - [Aufbau eines Makefiles](#aufbau-eines-makefiles)

## Kernel (Hauptbestandteil) ##

- Programme können nur quasi-Parrallel ausgeführt werden

### Scheduler ###

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

# Der Bootvorgang #

- [Der Bootvorgang](#der-bootvorgang)
    - [dmesg](#dmesg)
    - [Verzeichnis /boot](#verzeichnis-boot)
    - [Logfiles](#logfiles)
        - [syslogd](#syslogd)
        - [journalctl](#journalctl)

## dmesg ##

- Auslesen des Logs vom Bootvorgang
- Filtern von Nachrichten ist möglich

> **moritz@Latitude-E5520 ~ $** dmesg  
> [    0.000000] microcode: microcode updated early to revision 0x29, date = 2013-06-12  
> [    0.000000] Linux version 4.11.0-14-generic (buildd@lcy01-08) (gcc version 5.4.0 20160609 (Ubuntu 5.4.0-6ubuntu1~16.04.4) )
> #20~16.04.1-Ubuntu SMP Wed Aug 9 09:06:22 UTC 2017 (Ubuntu 4.11.0-14.20~16.04.1-generic 4.11.12)" ```// linux-version generic ist default kernel```  
> [    0.000000] Command line: BOOT_IMAGE=/boot/vmlinuz-4.11.0-14-generic root=UUID=4e7490ec-7fce-4ceb-9699-0ff40076a767 ro quiet splash vt.handoff=7 ```// UUID der root-Partition```  
> ...

- Nur Kernelmessages

> **moritz@Latitude-E5520 ~ $** dmesg -k

## Verzeichnis /boot ##

- initrd..img = initial Ramdisk (minirootfilesystem, wird beim Booten remountet, lädt dann das root-Filesystem)
- Verzeichnis grub
    - grub.cfg = grub config datei
        - sollte nicht verändert werden
        - nur mit hilfsprogrammen änderungen
        - default grub.cfg unter /etc/default/grub, diese sollte geändert werden und mit grub-mkconfig gespeichert werden
		- Regelt den Bootloader:
			- Welche Module werden geladen?
			- Was wird in welcher Reihenfolge geladen

## Logfiles ##

Die meisten logs befinden sich unter **/var/log**

### syslogd ###

- logging Deamon
- schreibt normalerweise in **/var/log/messages**
- neuer dings in Datenbank, wird abgefragt mit **joernalctl**

### journalctl ###

> **moritz@Latitude-E5520 ~ $** journalctl
- Ist ein Befehl zur Anzeige der Logdatenbank

# Aufbau des Dateisystems #

- [Aufbau des Dateisystems](#aufbau-des-dateisystems)
    - [/bin](#bin)
    - [/dev](#dev)
        - [Bsp.: Festplatten](#bsp-festplatten)
            - [Nach Pfad](#nach-pfad)
            - [Nach UUID](#nach-uuid)
    - [/etc](#etc)
    - [/lib](#lib)
    - [/mnt](#mnt)
    - [/media](#media)
    - [/proc](#proc)
    - [/sbin](#sbin)
    - [/usr](#usr)
        - [/usr/share](#usrshare)
        - [/usr/local](#usrlocal)
    - [/run](#run)
    - [/var](#var)
    - [/sys](#sys)
        - [/sys/module](#sysmodule)

- ist fester BEstandteil jeden Kernels
- ```/``` ist Rootverzeichnis

```bash

moritz@Latitude-E5520 / $ ls
bin   cdrom  etc   initrd.img      lib    lib64       media  opt   root  sbin  sys  usr  vmlinuz
boot  dev    home  initrd.img.old  lib32  lost+found  mnt    proc  run   srv   tmp  var  vmlinuz.old

```

## /bin ##

- die wichtigsten Programme

## /dev ##

- Gerätedateien

### Bsp.: Festplatten ###

#### Nach Pfad ####

```bash

moritz@Latitude-E5520 / $ ls /dev/disk/by-path/
pci-0000:00:1f.2-ata-1  pci-0000:00:1f.2-ata-1-part1  pci-0000:00:1f.2-ata-1-part2  pci-0000:00:1f.2-ata-1-part3  pci-0000:00:1f.2-ata-2

```

#### Nach UUID ####

```bash

moritz@Latitude-E5520 / $ ls /dev/disk/by-uuid/
4e7490ec-7fce-4ceb-9699-0ff40076a767  e9aca507-c962-4381-a934-8a93bbda37a0  F3C6-8EC8

```

## /etc ##

- Verschiedenes
- Alle dateien die nirgendwo anders dazu passen
- Auch binarys
- Config-Dateien

## /lib ##

- Systembibliotheken

## /mnt ##

- Einhängepunkt für Dateisysteme

## /media ##

- Einhängepunkt für Wechseldatenträger

## /proc ##

- **Virtuelles** Dateisystem
- Prozessdateien

## /sbin ##

- systemkritische Programme

## /usr ##

- Unix-System-Ressources
- Zusatzsoftware

### /usr/share ###

- Für verteilte Dateien

### /usr/local ###

- für software von Drittanbietern

## /run ##

- alles was zur Laufzeit benötigt wird

## /var ##

- Variables
- Log-Dateien

## /sys ##

### /sys/module ###

- Kernelmodule

# Bash-Befehle #

- [Bash-Befehle](#bash-befehle)
    - [Wichtige Befehle](#wichtige-befehle)
        - [ps](#ps)
        - [ls](#ls)
        - [less](#less)
            - [Bsp.: Benutzer Anzeigen](#bsp-benutzer-anzeigen)
            - [Bsp.: Passwörter der Benutzer](#bsp-passw%C3%B6rter-der-benutzer)
        - [passwd](#passwd)
        - [sudo](#sudo)
        - [Jobs](#jobs)
            - [Bsp.: ping &lt;url>](#bsp-ping-lturl)

## Wichtige Befehle ##

|Befehl|Parameter |Erklärung|
|------|:----------:|------------------------|
|pwd| |Anzeige des aktuellen Verzeichnis|
|ls| |Listing des Aktuellen Verzeichnisses|
|cat|&lt;Dateiname> |Anzeige der Der Datei &lt;Dateiname>|
|vi|&lt;Dateiname>| Editieren von &lt;Dateiname>|
|less|&lt;Dateiname>| Anzeige der Datei &lt;Dateiname>, Seitenweise, suchen möglich|
|cd|&lt;Verzeichnis>|wechsel des Verzeichnisses in &lt;Verzeichnis> *|
|mkdir|&lt;Verzeichnis>| erstellen des Verzeichnisses &lt;Verzeichnis>|
|rmdir|&lt;Verzeichnis>| Löschen des Verzeichnisses &lt;Verzeichnis>, muss leer sein|
|rm|&lt;Dateiname>| löscht die Datei &lt;Dateiname>, mit -r auch Verzeichnisse möglich|
|mv| &lt;Quelle> &lt;Ziel>| Verschieben der Datei &lt;Quelle> an das Ziel &lt;Ziel>|
|ps| | Anzeige laufender Prozesse|
|jobs| | Anzeige gestarteter (Batch)-jobs *|
|bg| &lt;jobnummer>| Ausführung des Jobs &lt;jobnummer> im Hintergrund* |
|fg |&lt;jobnummer>| Ausführung des Jobs &lt;jobnummer> im Vordergrund* |
|kill| &lt;pid> | beenden des Prozesses mit der Nummer &lt;pid>*|
|chmod||Ändert Berechtigungen an Dateien|
|passwd||Ändern des Passwortes eines Benutzers|
|sudo| &lt;Befehl> | Ausführen eines Befehls mit Systemverwaltungsrechten|
|chsh| | Ändern der Login-Shell eines Benutzers |
|chown| |Ändern des Besitzers einer Datei|
|chgrp| | Ändern der Gruppenzugehörigkeit einer Datei|
|man| &lt;Befehl> | zeigt die Bedienungsanleitung für den Befel an|
|help| |zeigt hilfe zur shell an|
|grep| &lt;Ausdruck> | filtert Zeilen, die den Ausdruck enthalten|
|zypper||Paketverwaltung in Open-Suse, **alias für apt**|
|[Strg] + Z||Anhalten eines Jobs|


### ps ###

- listet laufende Prozesse

```bash
moritz@Latitude-E5520 ~ $ ps
PID TTY          TIME CMD
11983 pts/0    00:00:00 bash
13709 pts/0    00:00:00 ps
```

```bash
moritz@Latitude-E5520 ~ $ ps -a
PID TTY          TIME CMD
13211 tty1     00:00:00 bash
13733 pts/0    00:00:00
```

```bash
moritz@Latitude-E5520 ~ $ ps -aux
USER       PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND
root         1  0.0  0.0 119984  6184 ?        Ss   09:41   0:01 /sbin/init splash
root         2  0.0  0.0      0     0 ?        S    09:41   0:00 [kthreadd]
..
root     13264  0.0  0.0  17492  1820 tty3     Ss+  10:10   0:00 /sbin/agetty --noclear tty3 linux
root     13268  0.0  0.0  17492  1828 tty4     Ss+  10:10   0:00 /sbin/agetty --noclear tty4 linux
root     13271  0.0  0.0  17492  1824 tty5     Ss+  10:10   0:00 /sbin/agetty --noclear tty5 linux
moritz   13378  6.8  2.0 3374780 168872 ?      Sl   10:11   0:18 /home/moritz/.dropbox-dist/dropbox-lnx.x86_64-36.4.22/dropbox
moritz   13582 11.6  2.4 3877292 194824 ?      SLl  10:13   0:17 evolution
moritz   13778  0.0  0.0  38992  3496 pts/0    R+   10:15   0:00 ps -aux
```
- Aktuelles Dateisystem: btrfs -> "Better oder Butter"
- **pstree** listet Prozesse in Baumstruktur auf

### ls ###

- Zeigt den Inhalt eines Ordners an

### less ###

- gibt den inhalt einer Datei in der Konsole aus

#### Bsp.: Benutzer Anzeigen ####

> **moritz@Latitude-E5520 ~ $** less /etc/passwd

#### Bsp.: Passwörter der Benutzer ####

> **moritz@Latitude-E5520 ~ $** sudo less /etc/shadow

### passwd ###

- Ändern des Passwortes

> **moritz@Latitude-E5520 ~ $** passwd </br>
> Ändern des Passworts für moritz. </br>
> (aktuelles) UNIX-Passwort: ******** </br>
> Geben Sie ein neues UNIX-Passwort ein: ******** </br>

- wenn passwort vergessen wurde, kann es auch vom Superuser geändert werden

### sudo ###

- führt Programme mit Superuser-Berechtigungen aus
- **Superuser:** root

### Jobs ###

[STRG + Z] hält Job an

#### Bsp.: ping &lt;url> ####

- joburl: #1
- pid: #2902

> **moritz@Latitude-E5520 ~ $** ping www.web.de > /dev/null &  
> [1] 6483  
> **moritz@Latitude-E5520 ~ $** jobs  
> [1]+  Läuft                  ping www.web.de > /dev/null &  
> **moritz@Latitude-E5520 ~ $** ps  
> PID TTY          TIME CMD  
> 3403 pts/0    00:00:00 bash  
> 6483 pts/0    00:00:00 ping  
> 6484 pts/0    00:00:00 ps

# UNIX-Standards #

- [UNIX-Standards](#unix-standards)
    - [IEEE](#ieee)
    - [X / Open-Gruppe (heute Open Group)](#x-open-gruppe-heute-open-group)
    - [In Programmiersprache C](#in-programmiersprache-c)

## IEEE ##

- Portable Operating System Interface (POSIX)
	- Definieren Schnittstellen die plattformunabhängig ansprechbar sind.
- Sammlung von vielen Standards

## X / Open-Gruppe (heute Open Group) ##

- Zusammenschluss aus mehreren Computerherstellern
- X/Open Portability Guide (XPG)

## In Programmiersprache C ##

- ANSI
- ISO
- sowie entsprechende POSIX- und X/Open-Implementierungen

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
|.C, .cc|C-Quellcodedatei                   |
|.cxx (cpp)| C++-Quellcodedatei             |
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

# 2.2 Verwendung von Makefiles #
Unterstützten den SW-Entwickler bei Entwicklungsaufgaben. Dadurch, dass Kommandozeilen beim übersetzen vom gcc durchaus eine stattliche Länge erreichen, lohnt es sich diese in einem Makefile abzuspeichern.
Bei größeren Projekten muss auch eine Organisation in Paketen und Ordnern geschehen.
Auch unterstützen Makefiles bei der Handhabung. Das Standardwerkzeug zum verwenden von Makefiles heißt: make.

Das Programm make kennt Standardregeln, die automatisch angewandt werden, wenn kein Makefile vorhanden ist.

Make erkennt, ob ein Target übersetzt wurde daran, dass eine gleichnamige Datei mit Zeitstempel existiert.
Ein neues übersetzen ist auch dann nötig wenn sich die zu überwachende c-Quelldatei ändert.

Make kennt eine Reihe von Makros:
- Compiler-Flags CFLAGS
- Linker-Flags LDFLAGS

Typische Targets:

- make all -> weist erstes Target zu
- make install -> nur installiert
- make debug -> übersetzen mit debug Ausgabe
- make test -> Ausführung von Testfällen
- make clean -> ausführen löschen von temp-Datei

kann mit cmake (configured make) erweitert werden.

Wenn das makefile zu komplex wird =>

- configure script

dieses hat die Aufgabe systemabhängige Einstellungen(z. B. Makrobelegung), Pfade zu Libraries, Includes für den make-lauf vorzubereiten
d.h. configure erstellt dynamisch ein Makefile.
Anpassungen des Makefiles sind über den configure Parameter möglich.
Parameter für make:

- s (silent) zeigt ausgeführte Kommandos nicht an.
- n (no execute) zeigt nur Kommandos an führt sie nicht aus.
- p (print) zeigt alle Makrodefinitionen und Targetrules an.
- q (question) Abfrage des aktuellen Zustandes der Ziele
## Aufbau eines Makefiles ##
```c
# Am Zeilenanfang steht das Target gefolgt von einem : 
hello: hello.c
	gcc hello.c -o hello
	
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

## Öffnen von Dateien mit C-Standard ##

```c
FILE* fopen(char *name, char *flags);
```

### Flags ###

| Flag | Erklärung                                                                            |
| ---- | ------------------------------------------------------------------------------------ |
| "r"  | Datei zum lesen öffnen                                                               |
| "r+" | Datei zum lesen und schreiben öffnen                                                 |
| "rb" | Datei binär öffnen                                                                   |
| "w"  | erstellt eine neue Datei zum schreiben, wenn schon existent, dann wird überschrieben |
| "w+  | erstellt eine neue Datei zum lesen und schrieben                                     |
| "wb" | Datei binär schreiben                                                                |
| "a"  | appends to file                                                                      |
| "ab" |