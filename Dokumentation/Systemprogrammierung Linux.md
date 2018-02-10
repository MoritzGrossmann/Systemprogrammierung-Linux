# Systemprogrammierung Linux #

- [Systemprogrammierung Linux](#systemprogrammierung-linux)
    - [3. Fehlerbehandlung](#3-fehlerbehandlung)
        - [Error.h](#errorh)
        - [Parsen von Kommandozeilen](#parsen-von-kommandozeilen)
        - [Abstrakt](#abstrakt)
        - [Probleme](#probleme)
        - [Abhilfe](#abhilfe)
    - [4. Elementare I/O-Operationen](#4-elementare-io-operationen)
        - [Wichtige Header](#wichtige-header)
        - [4.1 Filediskreptoren](#41-filediskreptoren)
            - [Typische Filediskreptoren](#typische-filediskreptoren)
            - [Verwendete Datei des Kernels anzeigen](#verwendete-datei-des-kernels-anzeigen)
        - [4.2 Lesen und Schreiben von Dateien](#42-lesen-und-schreiben-von-dateien)
            - [Öffnen einer Datei](#%C3%B6ffnen-einer-datei)
            - [Lesen und Schreiben einer Datei](#lesen-und-schreiben-einer-datei)
            - [Schließen einer Datei](#schlie%C3%9Fen-einer-datei)
            - [Lesen einer Datei](#lesen-einer-datei)
            - [Schreiben einer Datei](#schreiben-einer-datei)
        - [4.3 Filedeskriptoren in Prozesstabelle](#43-filedeskriptoren-in-prozesstabelle)
            - [Schreib-Lesezeiger positionieren](#schreib-lesezeiger-positionieren)
            - [Positionierung im stdid](#positionierung-im-stdid)
            - [Duplizieren von Filedeskriptoren](#duplizieren-von-filedeskriptoren)
            - [Letzten 20 Bytes einer Datei in stdout ausgeben](#letzten-20-bytes-einer-datei-in-stdout-ausgeben)
        - [4.4 Kontrolle der Eigenschaften einer Datei](#44-kontrolle-der-eigenschaften-einer-datei)
        - [4.5 Filezeiger](#45-filezeiger)
    - [5. Arbeiten mit Dateien und Verzeichnissen](#5-arbeiten-mit-dateien-und-verzeichnissen)
        - [5.1 Attribute von Dateien](#51-attribute-von-dateien)
        - [5.2 Auslesen der Datei-Attribute](#52-auslesen-der-datei-attribute)
        - [5.3 Dateiarten](#53-dateiarten)
            - [Makros zum Test des Dateityps](#makros-zum-test-des-dateityps)
        - [5.4 Dateizugriffsrechte](#54-dateizugriffsrechte)
            - [Einfache Zugriffsrechte](#einfache-zugriffsrechte)
            - [Erweiterte Zugriffsrechte](#erweiterte-zugriffsrechte)
            - [Ändern der Zugriffsrechte](#%C3%A4ndern-der-zugriffsrechte)
            - [Dateikreirungsmaske](#dateikreirungsmaske)
        - [5.5 Ändern von Besitzer und Gruppe](#55-%C3%A4ndern-von-besitzer-und-gruppe)
        - [5.6 Dateisystemverlinkungen](#56-dateisystemverlinkungen)
        - [5.7 Dateigröße](#57-dateigr%C3%B6%C3%9Fe)
        - [5.8 Zeiten einer Datei](#58-zeiten-einer-datei)
        - [5.9 Verzeichnisse](#59-verzeichnisse)
            - [Lesen von Verzeichnissen](#lesen-von-verzeichnissen)
        - [5.10 Gerätedateien](#510-ger%C3%A4tedateien)
            - [Spezielle Gerätedateien](#spezielle-ger%C3%A4tedateien)
        - [5.11 Puffercache](#511-puffercache)
    - [7. Prozesse unter Linux](#7-prozesse-unter-linux)
        - [7.1 Start eines Prozesses](#71-start-eines-prozesses)
        - [7.2 Beenden eines Prozesses](#72-beenden-eines-prozesses)
            - [Exit-Status eines Prozesses](#exit-status-eines-prozesses)
            - [Beenden ohne Aufräumen](#beenden-ohne-aufr%C3%A4umen)
            - [Zusätzliches Aufräumen](#zus%C3%A4tzliches-aufr%C3%A4umen)
        - [7.3 Umgebungsvariablen](#73-umgebungsvariablen)
            - [Abfragen einzelner Umgebungsvariablen](#abfragen-einzelner-umgebungsvariablen)
            - [Verändern von Umgebungsvariablen](#ver%C3%A4ndern-von-umgebungsvariablen)
            - [Speicherstruktur eines Prozesses](#speicherstruktur-eines-prozesses)
        - [7.4 Dynamisches Anfordern von Speicher](#74-dynamisches-anfordern-von-speicher)
            - [Freigabe dynamisch angeforderten Speicherplatzes](#freigabe-dynamisch-angeforderten-speicherplatzes)
            - [Anfordern von Speicherplatz im Stack](#anfordern-von-speicherplatz-im-stack)
        - [7.5 Ressourcenbeschränkungen](#75-ressourcenbeschr%C3%A4nkungen)
            - [Einige Limits und deren Bedeutung](#einige-limits-und-deren-bedeutung)
            - [Beispiel](#beispiel)
        - [7.6 Ressourcenverbrauch](#76-ressourcenverbrauch)
        - [7.7 Identifikation von Prozessen](#77-identifikation-von-prozessen)
            - [Abfrage von PID und PPID](#abfrage-von-pid-und-ppid)
            - [Abfrage der realen User- und Group-ID](#abfrage-der-realen-user--und-group-id)
            - [Abfrage der effektiven User- und Group-ID](#abfrage-der-effektiven-user--und-group-id)
        - [7.8 Prozesse erzeugen](#78-prozesse-erzeugen)
        - [7.9 Auf Beendigung eines Prozesses warten](#79-auf-beendigung-eines-prozesses-warten)
            - [Verweiste Kindprozesse](#verweiste-kindprozesse)
            - [Zombieprozesse](#zombieprozesse)
                - [Verhindern von Zombies](#verhindern-von-zombies)
            - [Informationen über benutzte Ressourcen](#informationen-%C3%BCber-benutzte-ressourcen)
        - [7.10 Synchronisation](#710-synchronisation)
        - [7.11 Systemruf exec](#711-systemruf-exec)
            - [Vererbung bei exec](#vererbung-bei-exec)
        - [7.12 Die Funktion system](#712-die-funktion-system)
        - [7.13 Verändern von User ID und Group ID](#713-ver%C3%A4ndern-von-user-id-und-group-id)
            - [User-ID und Group-ID für Dateisystemzugriffe](#user-id-und-group-id-f%C3%BCr-dateisystemzugriffe)
    - [8. Signale](#8-signale)
        - [8.1 Einrichten von Signalhandlern](#81-einrichten-von-signalhandlern)
        - [8.2 Kindprozesse und Signale](#82-kindprozesse-und-signale)
        - [8.3 Signalnummer](#83-signalnummer)
        - [8.4 Das neue Signalkonzept](#84-das-neue-signalkonzept)
    - [11. Pipes und FIFOs](#11-pipes-und-fifos)
        - [11.1 Pipes](#111-pipes)
            - [Einrichten einer Pipe](#einrichten-einer-pipe)
            - [Verknüpfung von Pipe mit Standardeingabe](#verkn%C3%BCpfung-von-pipe-mit-standardeingabe)
            - [Pipe zu einem anderen Programm](#pipe-zu-einem-anderen-programm)
        - [11.2 Benannte Pipes (FIFOs)](#112-benannte-pipes-fifos)
            - [Kreieren einer benannten Pipe](#kreieren-einer-benannten-pipe)
            - [Zugriffsregeln für FIFOs](#zugriffsregeln-f%C3%BCr-fifos)
    - [12 interprozesskommunikation](#12-interprozesskommunikation)
        - [12.1 Kennungen und Schlüsell](#121-kennungen-und-schl%C3%BCsell)
        - [12.2 Erzeugen eines neuen Objektes](#122-erzeugen-eines-neuen-objektes)
        - [12.3 Verbinden mit einem vorhandenen Objekt](#123-verbinden-mit-einem-vorhandenen-objekt)
        - [12.4 Löschen von Objekten](#124-l%C3%B6schen-von-objekten)
        - [12.5 Zugriffsrechte](#125-zugriffsrechte)
        - [12.6 Limits](#126-limits)
        - [12.7 Message-Queues](#127-message-queues)
            - [Status einer Warteschalnge](#status-einer-warteschalnge)
            - [Limits](#limits)
            - [Erzeugen einer Message-Queue](#erzeugen-einer-message-queue)
            - [Senden einer Nachricht](#senden-einer-nachricht)
            - [Aufbau einer Nachricht](#aufbau-einer-nachricht)
            - [Empfang einer Nachricht](#empfang-einer-nachricht)

## 3. Fehlerbehandlung ##

Die Fehlerbehandlung in C besteht aus einem Fehlercode (Fehlernummer) und etwaigen Beschreibungstext. Diese Texte können in verschiedenen Sprachen übersetzt werden.

```c
#include <stdio.h>

void perror(const char *s);
```

```c
#include <errno.h>

const char *suse_errlist[];

int sys_nerr; //Anzahl der Elemente in der errListe

int  errno; // Nummer des aktuellen Fehlers oder null
```

Die Funktion perror(...) erzeugt eine Fehlermeldung, entsprechend des Wertes von errno, auf dem Standard Fehlerkanal.
Häufig wird perror(...) der Name der Funktion übergeben, in der der Fehler augetreten ist.

```c
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    int i = 0;
    while (i < sys_nerrer) printf("%d\t%s\n",i, strerror(i++));
    return EXIT_SUCCESS
}

```

```c
#include <string.h>

char *strerror(int errnum);
```

liefert entsprechenden Zeiger auf die Fehlermeldung. Ist die Fehlernummer unbekannt wird "Unknown error xxx" zurückgelifert
Der Fehlerwert erno wird auf EINVAL gesetzt.

```c
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

int main(int argc, char **argv) 
{
    for (int i = 0; i < 10; i++)
    {
        errno = 1;
        perror("main");
    }
    return EXIT_SUCCESS;
}
```

### Error.h ###

```c
#include <error.h>

extern unsigned int error_message_count; 
//wird bei jedem Fehler hochgezählt

extern int error_one_per_line; 
//0 oder 1, wenn 1, dann nur eine Fehlermeldung bei z.B. Schleifendurchlauf
```

```c
void error(int status, int errnum, const char *format, ... );

//Wenn status 0, dann kein Programmabbruch
```

```c
void error_at_line(int status, int errnum, const char *filename, unsigned int linenum, const char *format, ... );
```

```c
//Beispiel

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <error.h>

int main(int argc, char **argv)
{
        for (int i = 0; i < 10; i++) {
                errno = 1;
                error_at_line(0, i, __FILE__, __LINE__, "Fehlernummer: %i", i);
        }
        return EXIT_SUCCESS;
}
```

```shell
moritz@FUJITSU-U904:~/Systemprogrammierung Linux/C-Programme$ gcc -Wall error.c  -o error
moritz@FUJITSU-U904:~/Systemprogrammierung Linux/C-Programme$ ./error
./error:error.c:10: Fehlernummer: 0
./error:error.c:10: Fehlernummer: 1: Operation not permitted
./error:error.c:10: Fehlernummer: 2: No such file or directory
./error:error.c:10: Fehlernummer: 3: No such process
./error:error.c:10: Fehlernummer: 4: Interrupted system call
./error:error.c:10: Fehlernummer: 5: Input/output error
./error:error.c:10: Fehlernummer: 6: No such device or address
./error:error.c:10: Fehlernummer: 7: Argument list too long
./error:error.c:10: Fehlernummer: 8: Exec format error
./error:error.c:10: Fehlernummer: 9: Bad file descriptor
```

```c
extern void (*error_print_progname)(void)
```

### Parsen von Kommandozeilen ###

Bsp.:

```shell
proc -a 123 -b -cd
    option a hat Wert 123
    option b,c und d sind gesetzt
```

### Abstrakt ###

```{r, engine='sh', count_lines}
<programm> -<param>[<value>]
```

### Probleme ###

- Reihenfolge der Parameter ist beliebig
- Parameterwerte können durch Leerzeichen getrennt oder direkt nach der Option stehen (bedeuted 1 oder 2 einträge in argv[])
- optionen können auch direkt (ohne Leerzeichen) aufeinander folgen
- optionen können in Kommandozeile fehlen (bedeutet: Prüfung auf Pfilchtparameter)

> Ergo: für jede Problem benötigt man Fehlerbehandlung,
> (Bedeutet: Benutzer soll wissen, was er falsch gemacht hat)

### Abhilfe ###

```c
int getopt(int argc, char *argv[], char *optString);
```

> Header: unix-standard-Header **<unistd.h>** (wichtigster)

```c
extern char *optarg;   //ist gesetzt, wenn es Argumente gab
```

Rückgabewert von getopt ist die gefundene Option (ein character). Im Fehlerfall ein '?' (unbekannte Option) oder ':' (pflichtparameter fehlt) bzw leere Menge (kommandozeile zuende)

Unter Linux sind oft noch "lange" Optionen, sogenannte Long-options erlaubt.

```c
int getopt_long(...); //Arbeitet im Prinzip wie getopr

```

Lange Optionen mittels Struktur

```c
struct option;
```

angegeben

Bsp.:

```{r, engine='sh', count_lines}
prog --field=1 --xcoord 20 --ycoord=10
```

> short-options werden exakt so behandelt, wie bei getopt  
> Die struct-option bezieht sich nur auf die long options

## 4. Elementare I/O-Operationen ##

### Wichtige Header ###

```c
#include <unistd.h>
#include <fcntl.h>
```

### 4.1 Filediskreptoren ###

Im UNIX-Kern werden Dateien und Verzeichnisse in Form von Zugriffsnummern, sog. Deskriptoren, verwaltet.

#### Typische Filediskreptoren ####

| Nummer | Erklärung             | C-Makros      |
| ------ | --------------------- | ------------- |
| 0      | Standardeingabe       | STDIN_FILENO  |
| 1      | Standardausgabe       | STDOUT_FILENO |
| 2      | Standardfehlerausgabe | STDERR_FILENO |

#### Verwendete Datei des Kernels anzeigen ####

>lsof

```shell
moritz@FUJITSU-U904:~/Systemprogrammierung Linux/C-Programme$ lsof
COMMAND PID   USER   FD   TYPE DEVICE    SIZE             NODE NAME
init      1   root  cwd    DIR    0,2     512  844424930140856 /
init      1   root  rtd    DIR    0,2     512  844424930140856 /
init      1   root  txt    REG    0,2   79416 1125899906887153 /init
init      1   root  mem    REG    0,0                    44529 /init (path dev=0,2, inode=1125899906887153)
init      1   root NOFD                                        /proc/1/fd (opendir: Permission denied)
init      2   root  cwd    DIR    0,2     512  844424930140856 /
init      2   root  rtd    DIR    0,2     512  844424930140856 /
init      2   root  txt    REG    0,2   79416 1125899906887153 /init
init      2   root  mem    REG    0,0                    44529 /init (path dev=0,2, inode=1125899906887153)
init      2   root NOFD                                        /proc/2/fd (opendir: Permission denied)
bash      3 moritz  cwd    DIR   0,12     512 3940649674601231 /mnt/c/Users/morit/OneDrive/Hochschule/Systemprogrammierung Linux/C-Programme
bash      3 moritz  rtd    DIR    0,2     512  844424930140856 /
bash      3 moritz  txt    REG    0,2 1037528  844424930140941 /bin/bash
bash      3 moritz  mem    REG    0,0                     8973 /bin/bash (path dev=0,2, inode=844424930140941)
bash      3 moritz  mem    REG    0,0                    10951 /lib/x86_64-linux-gnu/libnss_files-2.23.so (path dev=0,2, inode=844424930142919)
bash      3 moritz  mem    REG    0,0                    10915 /lib/x86_64-linux-gnu/libnss_nis-2.23.so (path dev=0,2, inode=844424930142883)
bash      3 moritz  mem    REG    0,0                    10944 /lib/x86_64-linux-gnu/libnsl-2.23.so (path dev=0,2, inode=844424930142912)
bash      3 moritz  mem    REG    0,0                    10918 /lib/x86_64-linux-gnu/libnss_compat-2.23.so (path dev=0,2, inode=844424930142886)
bash      3 moritz  mem    REG    0,0                    10908 /lib/x86_64-linux-gnu/libc-2.23.so (path dev=0,2, inode=844424930142876)
bash      3 moritz  mem    REG    0,0                    10897 /lib/x86_64-linux-gnu/libdl-2.23.so (path dev=0,2, inode=844424930142865)
bash      3 moritz  mem    REG    0,0                    10945 /lib/x86_64-linux-gnu/libtinfo.so.5.9 (path dev=0,2, inode=844424930142913)
bash      3 moritz  mem    REG    0,0                    10893 /lib/x86_64-linux-gnu/ld-2.23.so (path dev=0,2, inode=844424930142861)
bash      3 moritz  mem    REG    0,0                    40932 /usr/lib/locale/locale-archive (path dev=0,2, inode=562949953462244)
bash      3 moritz  mem    REG    0,0                    38804 /usr/lib/x86_64-linux-gnu/gconv/gconv-modules.cache (path dev=0,2, inode=562949953460116)

...
```

### 4.2 Lesen und Schreiben von Dateien ###

#### Öffnen einer Datei ####

```c
#include <sys/types.h>
#include <sys/stat.h>
#include <fcutl.h>

int open(const char *pfadname, int flags, mode_t mode)

//Rückgabe: bei Erfolg ein Fildeskriptor oder -1 bei Fehler
```

Als Flags muss mindestens eines derfolgenden Verwendung finden

- O_RDONLY (=0) nur lesen
- O_WRONLY (=1) nur schreiben
- O_RDWR (=2) lesen und schreiben

Optional lassen sich bitweise Oder verknüpfen

- O_APPEND datei zum schreiben an das Ende öffnen
- O_CREAT neu anlegen, falls Datei nicht exisitert -> mode berücksichtigen
- O_EXCL verhindert öffnen, fall Datei bereits existiert
- O_TRUNC Bewirkt Abschneiden, sodass sie neu geschrieben wird
- O_SYNC warte bis schreibvorgang abgeschlossen ist

#### Lesen und Schreiben einer Datei ####

| Flag     | Beschreibung                                                            | Oktal |
| -------- | ----------------------------------------------------------------------- | ----- |
| O_NOCTTY | falls ein Terminal geöffnet wird, soll es nicht Kontrollterminal werden |
| O_CREAT  | Wird das dritte Argument mode (Zugriffsmodi) benötigt					 |
| S_ISUID  | set User-Id Bit                                                         |
| S_ISGID  | set Group-Id Bit                                                        |
| S_ISVTX  | sticky Bit (saved Text)                                                 |
| S_IRUSR  | setzt das Leserecht für den Eigentümer                                  | 400   |
| S_IWUSR  | setzt das Schreibrecht für den Eigentümer                               | 200   |
| S_IXUSR  | setzt das Ausführrecht für den Eigentümer                               | 100   |
| S_IRWXU  | setzt alle Rechte für den Eigentümer                                    | 700   |
| S_RGRP   |                                                                         |
| S_WGRP   |
| S_XGRP   |
| S_RWXG   |
| S_IROTH  |
| S_IWOTH  |
| S_IXOTH  |
| S_RWXO   |

> Alternativ kann zum Erzeugen einer Datei auch creat(...) verwendet werden. Das ist Äquivalent zu open(...) mit den Flags O_CREAT | O_WRONLY | O_TRUNC

**Beispiel**

```c
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char **argv) 
{
    //Zugriffsrechte für die neue Datei: -rw-rw-r--
    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH; //0664;
    int flags = O_CREAT | O_WRONLY;

    const char *name = "tempfile";

    int fd; //Filedeskriptor

    if (fd = open(name, flags, mode) == -1) 
    { 
        perror("open");
        EXIT_FAILURE;
    }

    close(fd);

    printf("OPEN MAX: %d\n", OPEN_MAX);
    EXIT_SUCCESS;
}
```

#### Schließen einer Datei ####

```c
#include <unistd.h>

int close(int fd);

//Bei erfolg wird 0 zurück gegeben, sonst -1
```

> Maximal können **OPEN_MAX** Deskriptoren geöffnet werden

#### Lesen einer Datei ####

```c
#include <unistd.h>

ssize_t read(int fd, void *buffer, size_t bytes);
```
**Rückgabe:** tatsächlich gelesene Anzahl Bytes, oder 0, falls Dateiende erreicht oder -1 im Fehlerfall

#### Schreiben einer Datei ####

```c
#include <unistd.h>

ssize_t write(int fd, void *buffer, size_t bytes);
```

**Rückgabe:** tatsächliche Anzahl geschriebener Bytes, oder -1 im Fehlerfall

> Bemerkung: Geschriebene Daten werden zunächst in einem Cache (Puffer) gesammelt und zu einem späteren Zeitpunkt auf das physische Gerät geschrieben. **Wenn Sync-Flag beim öffnen gesetzt, dann wird sofort geschrieben**

> Zwischenzeitliches Lesen wird dann aus dem Cache beantwortet

> Erhöht Schreibgeschwindigkeit, mit dem Nachteil, dass im falle eines Systemabsturzes die Daten verloren sind

> Setzt man das Flag **O_SYNC** so kehrt write(...) erst dann zurück, wenn die Daten tatsächlich auf das Medium geschrieben sind

### 4.3 Filedeskriptoren in Prozesstabelle ###

| fd  | Flags  | Zeiger |
| --- | ------ | ------ |
| 0   | RDONLY |        |
| 1   | WRONLY |        |
| 2   | WRONLY |        |
| 3   |        |        |
| 4   |        |        |

**Dateitabelle**

| ...                          |
| ---------------------------- |
| filestatus                   |
| Position Lese-Schreibzeichen |
| V-node zeiger                |
| ...                          |
| status flags                 |
| Position Lese-Schreibzeichen |
| V-node zeiger                |

**V-node Tabelle**

| ...         |
| ----------- |
| v-node Info |
| i-node Info |
|             |

> Ein weiterer Prozess öffnet die gleiche Datei mit einem neuen Schreib-Lesezeiger

#### Schreib-Lesezeiger positionieren ####

Öffnet man eine Datei normal, befindet sich der Zeiger am Anfang der Datei. (Offset=0)
  
Wird eine Datei mit O_APPEND-Flag geöffnet, befindet sich der Zeiger vor jedem Schreiben am Ende der Datei. Konkurrierender Zugriff von 2 Prozessen auf eine Datei (Bsp. Log-File). Deshalb wird der Schreibkopf immer automatisch auf das Ende der Datei gesetzt.

Jede Schreib- oder Leseoperation bewegt den Zeiger um die tatsächliche Anzahl Bytes vorwärts. 

Zur Positionierung des Lese-Schreibzeigers kann die Funktion **lseek(..)** verwendet werden. 

```c
#include <unistd.h>
#include <sys/types.c>

off_t lseek(int fd, off_t offset, int woher);

//Rückgabewert ist die neue Position des Zeigers oder -1 im Fehlerfall
```

| Parameter | Erklärung                                                                                               |
| --------- | ------------------------------------------------------------------------------------------------------- |
| offset    | Legt die Byteanzahl fest, um die verschoben werden soll                                                  |
| woher     | Legt fest, von wo die Verschiebung statt findet, also Richtung. Dafür kennt l_seek 3 verschiedene Werte |
  

| Wert | Erklärung |
|-|-|
| SEEK_SET | von Dateianfang Richtung Ende. Nur positiver Offset |
| SEEK_CUR | von aktueller Poistion, Richtung durch Vorzeichen von Offset bestimmt (Lese-/Schreibzeiger + akt. Pos. + offset gesetzt)|
| SEEK_END | vom Dateiende, Richtung wird durch Vorzeichen bestimmt (Lese-Schreibzeiger wird auf Dateiende + Offset gesetzt)|

> **Bemerkung:** Positionierung/Schreiben hinter das Datei-Ende erzeugt ein Loch. Beim Lesen liefert read(..) dort Nullen

```c
//Beipiel

int fd = ...;

lseek(fd, 0l, SEEK_SET); // Zu Dateianfang springen

lseek(fd, 25l, SEEK_CUR); // 25 Zeichen vorwärts springen

lseek(fd, -1l, SEEK_END); // Zum letzten relevanten Byte springen (ende der Datei)

lseek(fd, 0l, SEEK_CUR); // Gibt aktuelle Position zurück

```

#### Positionierung im stdid ####

```c
//Beispiel 

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv) {
    fprintf(stderr, "Positionierung in stdin");
    if (lseek(STDIN_FILENO, 0l, SEEK_CUR) == -1)
    {
        fprintf(stderr, " geht nicht\n");
    } else {
        fprintf(stderr, " ist möglich\n");
    }

    return EXIT_SUCCESS;
}

```

```bash
 2017-11-03 10:37:13 ⌚  FUJITSU-U904 in ~/Systemprogrammierung Linux/C-Programme/Uebung 4
○ → ./positionierung
Positionierung in stdin geht nicht

 2017-11-03 10:38:10 ⌚  FUJITSU-U904 in ~/Systemprogrammierung Linux/C-Programme/Uebung 4
○ → ./positionierung </etc/passwd
Positionierung in stdin ist möglich

```

#### Duplizieren von Filedeskriptoren ####

Es gibt Anwendungsfälle, in denen das Duplizieren von Filedeskriptoren erforderlich ist. 
Dafür gibt es 2 Funktionen

```c
#include <unistd.h>

int dub(int fd); // Liefert nächsten freien Deskriptor zurück

int dub2(int fd, int fd2);

// Rückgabe bei beiden: neuer Filedeskriptor bei Erfolg oder -1 im Fehlerfall
```

Erster Parameter ist jeweils der zu duplizierender Filedeskriptor. dub(..) liefert den nächsten frieen Deskriptor zurück.  

dub2(..): liefert als neuen Filedeskriptor den Wert des zweiten Deskriptor. 

> Soltle fd2 bereits geöffnet sein, wird dieser vorher geschlossen (außer fd und fd2 sind gleich)

> **Bemerkung:** Beim Duplizieren wird für den neuen Deskriptor das clode-on-exit Flag gelöscht

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main (int argc, char **argv)
{
    if (dub2(STDOUT_FILENO, STDERR_FILENO) == -1) perror("dub2");

    char *str = "Ausgabeumlenkung STDERR nach STDOUT\n";

    write(STDERR_MO, str, strlen(str));
    write(STDOUT_MO, str, strlen(str));

    return EXIT_SUCCESS;
}
```

#### Letzten 20 Bytes einer Datei in stdout ausgeben ####

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>

int main (int argc, char **argv)
{
    if (argc < 2)
    {
        errno = EINVAL;
        perror("Dateiname als Parameter.");
        return EXIT_FAILURE;
    }

    int fd = open(argv[1], O_RDONLY);

    if (fd < 0) 
    {
        perror("open");
        return EXIT_FAILURE;
    }

    if (lseek(fd, -20l, SEEK_END) == -1) {
        perror ("lseek");
    }

    char byte = 0;

    while (read(fd, &byte, 1) > 0 ) write(STDOUT_FILENO, &byte, 1);

    close(fd);

    return EXIT_SUCCES;
}
```

### 4.4 Kontrolle der Eigenschaften einer Datei ###

Für nachträgliches Abfragen/Ändern von Dateieinstellungen (Flags) verwendet man fcntl(..)

```c
#include <unistd.h>
#include <fcntl.h>

int fcntl(int fd, int kommando, ... /*int arg*/);

// Der Rückgabewert ist im Erfolgsfall abhängig vom Kommando. Im Fehlerfall liefert die Funktion -1
```

Die verfügbaren Kommandos lauten:

F_DUPFD  
F_DUPFD_CLOEXEC  

F_SETFD  
F_GETFD

F_SETFL  
F_GETFL

F_SETOWN  
F_GETOWN

F_SETLK  
F_GETLK  
F_SETLKW

| Flag             | Beschreibung                                                            |
| ---------------- | ----------------------------------------------------------------------- |
| F_DUPFD          | Duplizieren eines Filedeskriptors: Das dritte Argument ist zur          |
| F_DUPFD_CLOEXEC  | vorhandener Filedeskriptor, bei 0 wird nächste Wer verwendet			 |
|
| F_SETFD          | Abfrage und setzen der FD-Flags                                         |
| F_GETFD          | (akt. einziges Flag: FD_CLOEXEC)                                        |
|
| F_SETFL          | Abfrage und setzen des Statusflags                                      |
| F_GETFL          | Bsp.: O_RDONLY, O_APPEND                                                |
|
| F_SETOWN         | Abfrage und setzen von PID/PGID des Prozesses                           |
| F_GETOWN         | der SIGIO und SIGUNG(? ob richtig?)                                     |
|
| F_SETLK          | Abfrage und setzen von                                                  |
| F_GETLK          | record / locks                                                          |
| F_SETLKW         |                                                                         |


### 4.5 Filezeiger ###

Die Standard C-Biblothek verwendet anstelle von Filedeskriptoren Zeiger auf eine Filestruktur.

```c
#include <stdio.h>

int fileno(FILE *fp);

FILE *fdopen(int fd), const char *modus);
```

fileno liefert den Filedeskriptor zu einem FILE-Pointer.  
fdopen liefert einen Zeiger auf eine FILE-Struktur oder NULL im Fehlerfall.
Der Parameter modus legt Zugriffsart fest ("r", "w", "a", "b", "+" (in Kombination))

Dateinhalt wird bei "w" nicht (wie bei fopen) gelöscht.

> Anwendung: z.B. Öffnen von Pipes und Sockets und Verwendung der Standard I/O-Funktionen

```c
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char ** argv)
{
    if (fcntl(STDIN_FILENO, F_GETFD) == FD_CLOEXEC)
    {
        printf("Die Standardeingabe wird beim beenden geschlossen");
    } else {
        printf("Die Standardeingabe bleibt beim beenden geöffnet");
    }

    int fd = open("Test.txt", )
}
```

## 5. Arbeiten mit Dateien und Verzeichnissen ##

### 5.1 Attribute von Dateien ###

```c
struct stat {
    dev_t st_dev;           //Nummer des Gerätes, welches Datei enhält
    ino_t st_ino;           //I-node Nummer
    mode_t st_mode;         //Dateiart und Zugriffsrecht
    nlink_t st_nlink;       //Anzahl der Links
    uid_t std_uid;          //User-ID Eigentümer
    gid_t st_gid;           //Group-ID Eigentümer
    dev_t st_rdev;          //Gerätenummer, spezielle Datei
    off_t st_size;          //Größte in Byte
    blksize_t st_blksize;   //Optimal Blockgröße für File-I/O
    blkcnt_t st_blocks;     //Anzahl belegter 512-Byte Blöcke
    time_t st_atime;        //(Access) Zugriffszeit
    time_t st_mtime;        //(Modify) Änderungszeit
    time_t st_ctime;        //(Change) Änderungszeit des i-node
}
```

### 5.2 Auslesen der Datei-Attribute ###

```c
#include <sys/types.h>
#include <sys/stat.h>

int stat(const char *pfadname, struct stat *puffer);

int fstat(int fd, struct stat *puffer);

int lstat(const char *pfadname, struct stat *puffer);
```

Die Funktion lstat zeigt, falls es sich bei der Pfadangabe um einen symbolischen Link handelt, die Attribute des Links selbst an. 

### 5.3 Dateiarten ###

Reguläre Datei: Text-/Binärdateien in beliebigen Format  
Verzeichnis: Datei mit Liste von Verzeichniseinträgen und zugehörigen I-node nummern  
Gerätedatei (special File): logische Beschriebungsdatei von physischem oder virtuellem Gerät, I/O-Operationen verwenden jeweiligen Gerätetreiber.

> Unterscheidung: Zeichenorientiertes Gerät (character Device), Blockorientiertes Gerät (block Device)

FIFO (named Pipe): Werden zur Interprozesskommunikation verwendet. Können nur einmal gelesen werden, keine Sprünge erlaubt  
Sockets: Kommunikation über Netzwerk oder Lokal  
Symbolische Links: Datei, die auf andere Datei zeigt

#### Makros zum Test des Dateityps ####

S_ISREG()  
S_ISDIR()  
S_ISCHR()  
S_ISBLK()  
S_ISFIFO()  
S_ISLNK()  
S_ISSOCK()  

```c
//Beispiel

(st_mode & 0170000) == 0040000 //Verzeichnis
```

```c
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    struct stat mystat;

    if(stat("test.txt", &mystat) < 0) perror("stat");

    if (W_ISREG(mystat.st_mode))
    {
        printf("test.txt ist eine Reguläre Datei";
    }

    return EXIT_SUCCESS;
}
```

Ältere UNIX-Varianten kennen die Makros nicht, haben dafür Konstanten.

```c
(st_mode & S_IFMT) == S_IFDIR
```

S_ID wird jediglich durch S_IF ersetzt

### 5.4 Dateizugriffsrechte ###

- Lesen r
- Schreiben w
- Ausführen x
> Jeweils für:
- Eigentümer
- Gruppe
- Andere

| Typ    | Typ    | Typ    |
| ------ | ------ | ------ |
| E-R    | G-R    | O-3    |
| rwx    | rwx    | rwx    |

- x = 1
- w = 2
- wx = 3
- r = 4
- xr = 5
- wr = 6
- rwx = 7

Für ausführbare Dateien existiert ein weiteres Flag mit Sonderfunktion:
Das Flag überträgt die Berechtigung des Bsitzers der ausführbaren Datei an den Benutzer der das Programm ausführt.

Bsp.: passwd [username] -> Benötigt root-Rechte
-> Gibt root-Benutzertyp zum ändern des Passworts

Wenn Bit gesetzt, dass einer es machen darf
-> Dann dürfen es alle

Bessere Alternative:
sudo und etc/sudou verwenden
-> Lässt für einzelne Dateien sudo setzen

#### Einfache Zugriffsrechte ####
- 9-Bit Rechtesystem für Dateien
- Zum Löschen/Erzeugen einer Datei benötigt man Ausführrechte in einem Ordner, der die Datei enthält
- Ebenso benötigt man Ausführrecht an einem Verzeichnis in das man wechseln möchte.

#### Erweiterte Zugriffsrechte ####
Rechteübertragung von z.B. root mittels Sticky-Bit

Ein Prozess der unter realer UID/GID (vom Benutzer erhalten) gestartet wird, bekommt nun effektive Eigentümer (SUID) und Gruppenrechte (SGID) zugeordnet.

#### Ändern der Zugriffsrechte ####
```c
#include <sys/types.h>
#include <sys/stat.h>

int chmod(const char* path, mode_t mode);
int fchmod(int fd, mode_t mode);
```
> Rückgabe: 0 bei Erfolg, -1 sonst.

#### Dateikreirungsmaske ####
```c
mode_t umask(mode_t mask);
```
> Die umask ist eine Maske, sie enthält Rechte, die verweigert werden -> also verboten.
> Rückgabe ist die vorherige umask, erwartet wird die umask

### 5.5 Ändern von Besitzer und Gruppe ###

```c
#include <sys/types.h>
#include <unistd.h>

int chown(const char* path, uid_t owner, gid_t group);
int fchown(int fd, uid_t owner, gid_t group);
int lhown(const char* path, uid_t owner, gid_t group);
```
> Rückgabe: 0 bei Erfolg, -1 sonst.
> Ist auf aktuellen Systemen _POSIX_CHOWN_RESTRICTED definert, benötigt man SU-Rechte für chown

### 5.6 Dateisystemverlinkungen ###

Es gibt zwei Arten von Verlinkungen: Hard Links und Soft Links (symbolische Links)

Ein Harter Link ist ein weiterer Verzeichniseintrag, welcher auf dem selben i-Node der Datei zeigt.
Ergo: Datei ist in verschiedenen Verzeichnissen eingetragen oder in einem Verzeichnis mehrfach mit unterschiedlichen Namen.
Der Linkzähler des i-Node gibt an, wieviele Verzeichniseinträge zum jeweiligen i-Node existieren.
Erst wenn der letzte Link auf diesem i-Node entfernt wird, kann die Datei gelöscht werden.

Ein symbolischer Link ist dagegen eine spezielle Datei, mit Verweis auf das eigentliche Ziel, also eigener i-Node.
Im Gegensatz zu Hardlinks, können Softlinks auch über Dateisystemgrenzen hinweg verknüpft werden.
Außerdem ist es Softlinks erlaubt auf Verzeichnisse zu zeigen. Nachteil ist jedoch, dass beim löschen der Originaldatei ein symbolischer Link verweist.
Richtet man die Dtaei später wieder ein, funktioniert alles wie zuvor.


Unter Linux existiert keine Datei, die (nicht) irgendwie verlinkt ist.
Verzeichnisbaum:
- Wurzel      /
(root)    L bin
		  L etc
		  L ...
		  L name
		  L temp

Das heißt, der i-Node, welcher zur Datei gehört, muss in mindestens einem Verzeichnis gelistet sein.
Die Zuordnung des Dateinamen zu seiner i-Node Nummer geschieht beim Eintragen in ein Verzeichnis.
Verzeichnis in Unix := Datei mit Namen und i-Node-Nummern. 
Also: Eine i-Node-Nummer kann im Verzeichnissbaum gelinkt sein.
Diese Links werden "Hard-Links" genannt.

Harte Dateiverlinkungen können mit der Funktion link(...) erzeugt werden.

```c
#include <unistd.h>

int link(const char* name, const char* linkname);
```
> Beide Angaben sind Pfadnamen
> Die Verlinkung war Erfolgreich, wenn 0 zurückgeliefert wird. (Im Fehlerfall -1; z.b. Wenn Linkname bereits existiert oder Name keine gültige Datei ist)

Harte Verlinkungen auf Verzeichnisse sind nicht erlaubt! (Wegen endloser Rekursion)

Zum entfernen eines Links kann unlink(...) verwendet werden.
```c
#include <unistd.h>

int unlink(const char* name);
```
> Entfent den Verzeichniseintrag (link) auf eine Datei i-Node
> Wenn diese der letzte Link ist, wird danach der i-Node freigegeben
> Liefert 0 bei Erfolg, sonst -1
> Tritt ein Fehler auf, bleibt die Datei erhalten

Wird eine Datei geschlossen (Filedeskriptor), so prüft der Kernel, ob diese Datei von anderen Prozessen noch geöffnet ist. Ist dies der Fall, so prüft der Kernel, ob der Linkzähler 0 erreicht hat.
Sind Beide Bedingungen erfüllt, wird die Datei auch physisch gelöscht.
Manche Programme machen sich dies zu nutze, in dem temporären Dateien, direkt nach dem Anlegen gelöscht werden. (Sind in Dateisystem unsichtbar)
Der laufende Prozess hält sie weiterhin offen (Zum schreiben/lesen), damit wird sie physisch noch nicht gelöscht. Das geschieht erst, wenn sich der Prozess beendet (Und bei Absturz des Programms).

Wird mittels unlink(...) ein symbolischer Link gelöscht, wird nur dieser Link entfernt. 
Zum entfernen eines Verzeichnisses muss auf remove(...) oder rmdir(...) ausgewichen werden. (aus stdlib -c)
Symbolische Links auf eine Datei oder ein Verzeichniss werden mit symlink(...) erzeigt.
```c
#include <unistd.h>

int symlink(const char* ziel, const char* symlink);
```
> Rückgabe: 0 bei Erfolg, -1 bei Fehler.
> Fehler, z.B.: Wenn Ziel und symlink den gleichen Namen tragen und in selben Verzeichnis sein sollen

Beim Umgang mit symbolischen Links ist es vortheilhaft zu wissen, welche Systemfunktionen selbständig folgen und welche es nicht tun.
Funktionen die diesen Links folgen (dereferenzieren) sind: access, chdir, chmod, chown, creut(?), exec, link, mkdir, mkfile (Akzeptieren: Pfad und ? bis zum i-Node), mkmod, open, opendir, pathcont, stat, trancate

Funktionen die symbolischen Links verarbeiten sind: lchown, lstat, readlink, remove, rename, unlink
Ausnahme: rmdir(...) liefert Fehler, falls Pfad ein symlink ist.

Möchte man das Ziel eines symlink erfahren, kann readlink(...) verwendet werden.
```c
#include <unistd.h>

int readlink(const char* symlink, char* puffer, int size);
```
> Liefert im Erfolgsfall die Anzahl gelesener Bytes.
> Pfadname der Zieldatei oder -1 bei Fehlern.
> Die in den Puffer geschriebene Zeichenakette wird nicht Nullterminiert

### 5.7 Dateigröße ###
struct stat -> st_size (Bytes) für reg.Dateien, Verzeichnisse und symlinks

Blockgröße 512 oder 1024 Bytes
st_blocksize = Blockgröße für E/A-Operationen
st_blocks = Anzahl 512-Bytes-Blöcke

Verzeichnisse haben gewöhnliche st_size wort als vielfaches von 16.
Bei symlink ist st_size die Länge des Pfades auf der die Links verweist.
Die Größe einer Datei kann geändert werden von truncate(...) oder ftruncate(...) geändert werden.

```c
#include <sys/types.h>
#include <unistd.h>

int truncate(const char* path, off_t length);
int ftruncate(int fd, off_t length);
```
> Rückgabe: 0 bei Erfolg, -1 bei Fehlern
> Normalerweise wird truncate zum Abschneiden benutzt, also Dateigröße reduzieren/Datei leeren.
> Es besteht aber auch die Möglichkeit eine Datei virtuell zu vergrößern. Das kann Sinnvoll sein, wenn man z.B. für einen bevorstehenden Download Plattenplatz reservieren möchte. 
> Beim vergrößern können Löcher entstehen, dessen Bytes beim Auslesen den Wert 0 haben.

### 5.8 Zeiten einer Datei ###

| Time      | Use             |
| --------- | --------------- |
| st_mtime  | modification    |
| st_atime  | access          |
| st_ctime  | change (i-Node) |
> Diese Zeiten sind auch unter der Bezeichnung MAC-time bekannt und werden in Computerforensik verwendet.

Diese Zeiten lassen sich nachträglich ändern. Mit folgenden Funkltionen:
- utime(...)
- utimes(...)

```c
#include <sys/types.h>
#include <utime>

int utime(const char* path, const struct utimebuf* tm);
struct utimebuf{
		time_t actime;  // accesstime
		time_t modtime; // modification
		}
```

Jedes mal, wenn utime mit null aufgerufen wird, wird st_ctime automatisch auf die aktuelle Systemzeit gesetzt.
Die Werte actime und modtime sind Unix zeitstempel (also Sekunden seit dem 01.01.1970 01:00 CET (00:00 UTC))

Benötigte Berechtigung:
Effektive UID des Prozesses muss Besitzer sein oder Prozess wird als root ausgeführt.
Wir utime() mit nicht initialisierten Wert aufgerufen, werden die Zeitstempel auf die aktuelle Systemzeit gesetzt.

```c
#include <sys/types.h>
#include <utime>

int utimes(const char* path, const struct timeval tm[2]);
struct timeval{
		long tv_sec;  // second
		long tv_usec; // microseconds
		}
```

### 5.9 Verzeichnisse ###

Anlegen eines neuen Ordners:
```c
#include <sys/types.h>
#include <sys/stat.h>

int mkdir (const char* path, mode_t mode);
```
> Liefert 0 bei Erfolg, -1 bei Fehler.
> Beachte Ordner sollten zusätzlich Ausführrecht gewähren, um Zugriff auf darin befindliche Dateien zu erhalten.

Löschen eines leeren Verzeichnis:
```c
#include <sys/types.h>
#include <sys/stat.h>

int rmdir (const char* path);
```
> Liefert 0 bei Erfolg, -1 bei Fehler.


#### Lesen von Verzeichnissen ####

```c
#include <sys/types.h>
#include <dirent.h>

DIR *opendir(const char *path);

struct dirent *readdir(DIR *folder);

void rewinddir(DIR *folder);

int closedir(DIR *folder);

```
Die Struktur DIR ist eine interne Datenstruktur, die beim Öffnen erzeugt wird und für weitere Verarbeitung genutzt wird. Die Funktionen opendir(...) und readdir(...) liefern im Fehlerfall NULL-Zeiger. closedir(...) liefert im Erfolg 0, sonst -1.  
Nach opendir(...) wird mit readdir(...) der erste Eintrag gelesen. Jeder weitere Eintrag kann durch wiederholen von readdir(...) gelesen werden.  
Mit rewinddir(...) wird der ELsezeiger wieder auf Anfang der Namensliste gesetzt.

Die rekursive Verarbeitung von Verzeichnisbäumen wird zusätzlich durch 2 Funktionen ftw (file traverse walk) und nftw (new file traverse walk) unterstützt.

Diese akzeptieren eine callback-Benutzer-Funktion, welche für jeden Verzeichniseintrag aufgerufen wird.

Unterschied: Behandlung Symbolischer Links

ftw: folgt Symlinks  
nftw: optional, kann eingestellt werden

```c
#include <ftw.h>

int ftw(const char *dirpath, int (*fn) (const char *path, const struct stat *sb, int type flags), int nopenfd);
```
> Der Rückgabewert von ftw ist der Rückgabewert der übergebenen Funktion.
> Liefert die übergebene Funktionenen einen Wert verschieden von 0, so bricht ftw ab.

```c
#define _XOPEN_SOURCE 600

#include <stdio.h>
#include <stdlib.h>
#include <ftw.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int dir_depth(const char *path)
{
    int z = 0;
    char *zgr = (char *)path;

    while((zgr = strchr(zgr, '/'))) 
    {
        zgr++;
        z++;
    }
    return z;
}

int traverse(const char *path, const struct stat *sb, int typeflags) 
{
    static char firsttime = 1;
    static int initial_depth;

    if (!firsttime)
    {
        for (int i = 1; i < dir_depth(path) - initial_depth; i++) printf("\t|");

        printf("----%s", strrchr(path, '/') + 1);

    } else {
        initial_depth = dir_depth(path);
        firsttime = 0;
        printf("%s\n", path);
    }

    switch (typeflags) 
    {
        case FTW_F:
            printf("\n");
            break;
        case FTW_D:
            printf("/\n");
            break;
        case FTW_DNR:
            printf("/-\n");
            break;
        case FTW_NS:
        default:
            perror("file traverse walk");
    }

    return 0;
}

int main(int argc, char **argv) 
{

    int fd = open("..", O_RDONLY);
    fchdir(fd);
    char *cwd = getcwd(NULL, 0);
    printf("%s\n", cwd);
    free(cwd);
    close(fd);
    chdir("..");

    ftw(".", &traverse, 100); //Aktuelles Verzeichnis

    return EXIT_SUCCESS;
}

```

### 5.10 Gerätedateien ###

Gerätedateien sind Kernel-Schnittstellen zur Hardware, genauer gesagt zum Treiber, der die Hardware steuert.

Geräte müssen nicht immer physisch verhanden sein. Es gibt auch viele logische(virtuelle) Geräte.

> Verwendet man I/O-Funktionen mit einer Gerätedatei, so kommuniziert man mit dem Treiber

Damit der Kernel weis, welchen Treiber we verwenden soll, sind jeder Gerätedatei zwei Nummern zugeordnet:
- eine Major-Device Number und
- eine Minor-Device Number

(beides über struct stat verfügbar)

st_rdev - Nummer des zugeordneten Geräts

Major Number legt Gerätetyp fest, während Minor-Number dem pasenden Treiebr übergeben wird, zur Unterscheidnung verschiedener Geräte gleichen Typs

#### Spezielle Gerätedateien ###

- /dev/null (Müllschlucker)
    - schreiben endlos
    - lesen liefert EOF
    - z.B. leeren von Dateien
- /dev/zero
    - schreiben endlos (Müllschlucker)
    - lesen liefert endlos Nullen
    - z.B. zum Formatieren
- /dev/full
    - schreiben nicht möglich (kein speicherplatz)
    - lesen liefert endlos nullen
    - z.B. testen von Programmen auf fehlertoleranz
- /dev/random
- /dev/urandom
    - erzeugen zufällige folge von Bits
    - bei random beruht Bitfolge auf **reine** Zufallsquellen. (i.d.R. externe Events)
    - dies erzeugt Entghropie
    - ist davon genug vorhanden, werden die nächsten Zufallsbits erzeugt
    - Wird genutzt zum generieren von sicherheitsrelevanten Zahlen (z.B. Schlüsseln)
    - bei urandom wird ein Algorithmus für Zufallszahlen genutzt

### 5.11 Puffercache ###

```c
#include <unistd.h>

void sync(void);
int fsync(int fd);

```
> fsync liefert bei Erfolg 0, sonst -1  

Beide veranlassen den Kernel gepufferte Daten physisch zu schreiben
Sync trägt bei Kernel ein, dass alle geöffneten Dateien zu schreiben sind und kehrt sofort zurück  
Dem gegenüber bezieht sich fsync(...) nur auf eine Datei und veranlasst auch nur das Schreiben dieser. fsync kehrt erst zurück, wenn physikalischer schreibprozess abgeschlossen.

Physikalische Schreibprozesse werden von einem Hintergrundprozess etwas alle 30 Sekunden automatisch ausgeführt.

## 7. Prozesse unter Linux ##

Ein laufendes Programm in einem Multitasking-Betriebssystem wird Prozess genannt.  
Jeder Prozess läuft in einer Umgebung (Environment), er benötigt Seicher, Zugriff auf Ressourcen, das Dateisystem, externe Geräte, Treiber etc. Auch Treiber sind Programme. Es muss auch geregelt sein, wie Prozesse, zum Zwecke des Datenaustausches oder spezieller Benachrichtigungen, miteinander kommunizieren können.

### 7.1 Start eines Prozesses ###
Startup-Routine im Kernel sorgt für den Aufruf der main-Funktion, Übergabe von Argumenten und der Bereitstellung von Umgebungsdaten.

```c

int main(int argc, char **argv);

```

Das Array argv enthält an der Stelle argv[argc] einen NULL-Pointer. (POSIX /C-Std).

### 7.2 Beenden eines Prozesses ###

Linux unterscheidet zwei Arten, wie ein Prozess beendet werden kann.  
Normalerweise endet ein Prozess mit dem Ende der main-Funktion und des entsprechenden Rückgabewertes.  
Alternativ kann die Funktion exit(...) verwendet werden. Ein Prozess kann auch beendet werden, wenn man die Ausführung abbricht, mittels abort(...) oder einem externen Signal.

#### Exit-Status eines Prozesses ####

Beendet sich ein Programm regulär, leifert es einen Wert zurück. Der Wert kann Aufschluss übder den Erfolg des Programmes geben.

Im Erfolgsfall typischerweise 0, bei Fehler einen Wert verschieden von 0.

#### Beenden ohne Aufräumen ####

Beendet sich ein PRogramm normal, werden zuvor alle Puffer geleert, alle Dateien geschlossen und die mit der Funktion tmpfile() angelegten Dateien gelöscht. Nach dem aufräumen ruft exit(...) seinerseits _exit(...) auf, um zum Kernel zurück zu kehren.

```c
#include <stdlib.h>

void _exit(int status);

```

Von POSIX vorgeschrieben, bewirkt sofortiges Beenden und Rückkehr zum Kernel, ohne Aufräumen.

#### Zusätzliches Aufräumen ####

Bei regulären Beenden können benutzerdefinierte Routinen registriert und Aufgerufen werden.

```c
#include <unistd.h>

int atexit(void (*function)(void))

```

Im Fehlerfall liefert atexit(...) einen Wert ungleich 0

### 7.3 Umgebungsvariablen ###

Die Liste der Umgebungsvariablen ist, wie  die Argumentliste (argv), ein Array aus Zeichenketten. Diese Nullterminiert, wie die Liste selbst.  
Durch Deklaration der globalen Variablen 
```c
extern char **environ; 
```
kann auf die Umgebungsvariablen zugegriffen werden. Die Variablenbelegung sind Strings der Form name=Wert.

#### Abfragen einzelner Umgebungsvariablen ####
```c
#include <stdlib.h>
	char * getenv(const char *name);
```
Liefert Null, falls name nicht in Environment vorhanden, ansonsten einen Zeiger auf den Anfang von Wert (name = wert)
Bem.: Sollte möglichst nicht verändert werden, da weitere Aufrufe von getenv den selben Zeiger liefern.

#### Verändern von Umgebungsvariablen ####

```c
#include <stdlib.h>
	int putenv(const char *entry);
	int setenv(const char *name, const char *wert, int overwrite);
	void unsetenv(const char *name);
	int clearenv(void);
```
	Rückgabe: 0 bei Erfolg oder ungleich 0 bei Fehler.
	Der Parameter bei putenv(…) muss schon die Form: "name=wert" besitzen. Sollte name bereits existieren,  wird der bisherige Eintrag entfernt.
	Demgegenüber ändert setenv(…) den übergebenen Wert, falls ein Eintrag bereits vorhanden, nur, wenn der dritte Parameter overwrite ungleich 0 ist.
	Die Funktion clearenv(…) liefert Fehler, falls das Environment bereits verändert wurde, ohne putenv, setenv oder unsetenv zu verwenden.

#### Speicherstruktur eines Prozesses####

siehe Bild Speicherstruktur eines Prozesses

### 7.4 Dynamisches Anfordern von Speicher ###

```c
#include <stdlib.h>
	void* malloc(size_t size);
	void* calloc(size_t amount, size_t size);
	void* realloc(void *ptr, size_t size);
```
Konnte der Speicher allokiert werden, liefern die Funktionen seine Adresse (im Heap-Segment) zurück, ansonsten NULL.
Im Unterschied zu malloc(…) belegt calloc(…) den Speicher mit Nullen.
Verkleinern oder vergrößern kann realloc(…).
=> Der Speicherbereich ist in jedem Fall zusammenhängend (verantwortlich ist die MemoryManagementUnit)

#### Freigabe dynamisch angeforderten Speicherplatzes ####

```c
#include <stdlib.h>
	void free(void *ptr);
```
Wird eine Adresse übergeben, die nicht mit obigen Funktionen allokiert wurde oder eine, die bereits mittels free(…) freigegeben wurde, ist das Verhalten undefiniert. Kann fatale Folgen für Prozess haben, da Speicherverwaltung inkonsistent wird.
	
Gemäß C-Standard sind folgende Aufrufe identisch:
- realloc(NULL, groesse); <=> malloc(groesse);
- realloc(addr, 0); <=> free(addr);

Ein Aufruf von free(NULL) ist wirkungslos.

#### Anfordern von Speicherplatz im Stack ####
```c
#include <stdlib.h>
	void* alloca(size_t size);
```
Bei Erfolg liefert alloca(…) die Speicheradresse (im Stack-Segment), sonst NULL. Stackbereich der momentanen Funktion wird erweitert. Nach Ende der Funktion wird Speicher automatisch frei gegeben, ist also nur temporär.
Gefahr: Ist nicht genug Speicher vorhanden, ruft alloca(…) einen Stacküberlauf hervor. (Weiterer Programmablauf undefiniert)

### 7.5 Ressourcenbeschränkungen ###

Die Ressourcenvergabe an Prozesse (Speichergröße, CPU-Zeit, Anzahl geöffneter Dateien, Stack-Größe und weiteres) durch den Kernel ist beschränkt.

Diese Schranken (limits) sind konfigurierbar. In gewissen Bereich kann ein Prozess diese Schranken selbst frei wählen.

Zum Erfragen und Setzen von Ressourcenbeschränkungen dienen:

```c
#include <sys/resource.h>

int getrlimit(int resource, struct rlimit *ptr);

int setrlimit(int resource, const struct rlimit *ptr);
```

Rückgabe 0 bei Erfolg und verschieden von 0 Fehler.

Die Struktur rlimit:

```c
struct rlimit {
    rlim_t rlim_cur; //Aktuelles Limit
    rlim_t rlim_max; //Maximaler Wert
}

//Konstante Für Unbeschränkt
RLIM_INFINITY //(-1)
// Drück aus, dass es keine Beschränkung für die Ressource gibt
```

Ein Prozess darf seine Ressourcen frei wähen, solange diese kleiner gleich den Maximal-Werten (rlim_max) ist.

Außerdem darf ein Prozess den Maximal Gültigen Wert für sich Verringern. Nur der Superuser darf den manimalen Wert für den Ressourcenbedarf erhöhen.

Praktische Relevanz hat dies beim Testen von Software.

#### Einige Limits und deren Bedeutung ####

| Limit         | Bedeutung                                        |
| ------------- | ------------------------------------------------ |
| RLIMIT_CORE   | Beschränkung der Größe in Core-Files             |
| RLIMIT_CPU    | CPU-Zeit je Prozess                              |
| RLIMIT_DATA   | Beschränkung der Datensegmentgröße               |
| RLIMIT_FSIZE  | Beschränkung der Dateigröße                      |
| RLIMIT_NOFILE | Anzahl der geöffneten Dateien                    |
| RLIMIT_NICE   | Beschränkung des nice-Wertes                     |
| RLIMIT_NPROC  | Beschränkung der Prozessanzahl inklusive Threads |
| RLIMIT_STACK  | Beschränkug der Stack-Größe                      |
| RLIMIT_AS     | Beschränkung der Größe des Addressraumes         |

#### Beispiel ####

```c
#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>

int main(int argc, char **argv) {

    struct rlimit limit;
    if ( getrlimit(RLIMIT_CORE, &limit)) perror ("getrlimit");

    printf("CORE-FILE: %d (cur), %d (max)\n", limit.rlim_cur, limit.rlim_max);

    if ( getrlimit(RLIMIT_CPU, &limit)) perror ("getrlimit");

    printf("CPU: %d (cur), %d (max)\n", limit.rlim_cur, limit.rlim_max);

    return EXIT_SUCCESS;
}
```

### 7.6 Ressourcenverbrauch ###

Der aktuelle Ressourcenverbrauch eines Prozesses kann mit: getrusage(..) abgefragt werden.

```c
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>

int getrusage(int whom, struct rusage *usage);
```

Rückgabe 0 bei Erfolg, -1 bei Fehler.

Der erste Parameter entscheidet, von wem man den Verbrauch erfragen möchte. Das kann eine von 3 Konstanten sein:

| Konstante       | Erklärung                                   |
| --------------- | ------------------------------------------- |
| RUSAGE_SELF     | Prozes selbst inkl. Threads                 |
| RUSAGE_CHILDREN | Ressourcenverbrauch aller Kindprozesse      |
| RUSAGE_THREAD   | Ressourcenverbrauch des aufrufenden Threads |

In Linux verwendet:
	
- ru_utime,
- ru_stime,
- ru_maxrss,
- ru_minflt,
- ru_majflt,
- ru_inblock,
- ru_outblock,
- ru_nvcsw,
- ru_nivcsw


### 7.7 Identifikation von Prozessen ###

Intern wird jeder Prozess durch eine Nummer repräsentiert, die Prozess-ID (PID). Der Kernel stellt sicher, dass es keine 2 Prozesse mit gleicher PID gibt. 

Bis auf wenige Ausnahmen hat jeder Prozess ein Eltern-Prozess, welcher den Start veranlasst hat.

Um die Eltern-Kind beziehungen herstellen zu können verwendet der Kernel zu jedem Prozess die parent process ID (PPID).

Beide Angaben zusammen ergeben eine Baumstruktur => Prozesshierachie.

Neben diesen Identifikationsnummern benötigen Prozesse noch Berechtigungen, diese haften unter UNIX an Benutzern und Gruppen. Entscheidend für die Rechte, mit denen ein Prozess Operationen ausführt, sind **effektive** User- und Group-ID.

#### Abfrage von PID und PPID 

```c
#include <sys/types.h>
#include <unistd.h>

pid_t getpid(void);
pid_t getppid(void);
```

Beide Funktionen sind stehts erfolgreich.

#### Abfrage der realen User- und Group-ID

```c
#include <sys/types.h>
#include <unistd.h>

uid_t getuid(void);
gid_t getgid(void);
```

Beide Funktionen sind stets erfolgreich.

#### Abfrage der effektiven User- und Group-ID

```c
#include <sys/types.h>
#include <unistd.h>

uid_t geteuid(void);
gid_t getegid(void);
```

Beide Funktionen sind stets erfolgreich.

### 7.8 Prozesse erzeugen ###

Will man unter UNIX neue Prozesse aus einem laufenden Programm heraus erzeugen, nutzt man die Funktion fork();

```c
#include <sys/types.h>
#include <unistd.h>

pid_t fork(void);
```
Rückgabe: (im Elternprozess) die PID des neuen (kopierten) Prozesses, im Kindprozess die 0, bei Fehler -1.  
Der Kernel erzeugt bei fork() eine Kopie des aktuellen Prozesses und ordnet dieser den Originalprozess als Elternprozess zu. Durch den Rückgabewert können beide unterschieden werden.

> Bemerkung: Die Rückgaberegelung als Unterscheidung ist Sinnvoll, da der Kindprozess ohnehin die PID des Elternprozesses mit get_PPID() abfragen kann.

Typisches Szenario

```c
int childID = fork();

if (childID < 0)
{
    perror("could not fork")
}
else if (childID) 
{
    // Elternprozess
} 
else
{
    // childID = 0
    // -> Kindprozess
}
```



> Beachte: Um Zombieprozesse zu vermeiden, muss auf deren Beendigung gewartet werden!

**Beispiel**

```c
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main (int argc, char **argv)
{
    pid_t parent, self, pid;

    if ((pid = fork()) < 0) perror("could not fork");
    else if (pid) // Elternprozess
    {
        printf("Elternprozess:\t");
        parent = getppid();
        self = getpid();

        printf("ppid %d, pid %d, kind: %d\n", parent, self, pid);

        // Um Zombies zu verhindern

        wait();

    } else {
        printf("Kindprozess:\t");
        parent = getppid();
        self = getpid();
        
        printf("ppid %d, pid %d\n", parent, self);
    }

    return EXIT_SUCCESS;
}
```

Einige Kernel setzen bei fork() auf copy-on-write (cow), eine Technik, die den Kindprozess den Speicher des Elternprozesses mitbenutzen lässt, solange dieser nur daraus ließt. Eine echte Kopie wird erst erzeugt, wenn das Kind in den Speicher schreibt. Das ist besonders dann nützlich, wenn auf fork() der Systemruf exec(..) folgt. In dem Fall steht vfork() zur Verfügung.

> Bemerkung: Bei vfork() ist garantiert, dass der Kindprozess **vor** dem Elternprozess ausgeführt wird

Linux unterstützt zudem noch den Systemruf clone(), der Ebenfalls eine Prozesskopie erzeugt, wobei die Art und Weise der Prozesskopie einstellbar ist.

Bildet die Grundlage für weitere Operationen mit leichtgewichtigen Prozessen (Threads)

### 7.9 Auf Beendigung eines Prozesses warten ###

Wie jedes Programm kann ein Prozess normal (mit Exit-Status) beendet oder abgebrochen werden. 

Elternprozesse können im Normalfall den Exit-Status eines Kindes mit wait() oder waitpid(..) abfragen.

```c
#include <sys/types.h>
#include <wait.h>

pid_t wait(int *status);

pid_t waitpid(pid_t pid, int *status, int opt);
```

Beide Funktionen liefern bei Erfolg die ProzessID. Im Falle eines Fehlers wird -1 oder 0 (falls kein Kind aktiv ist/war) zurückgegeben und WNOHANG

Die Funktion wait() wartet auf Beendigung eines beliebigen Kind-Prozesses, während waitpid(..) auf das Ende eines bestimmten Kindprozesses warten kann.

Beide Funktionen blockieren, bei waitpid(..) kann das mit einer Option ausgesetzt werden. 

Zur Überprüfung des Exit-Status gibt es folgende Makros:

| Marko                | Erklärung                                                                                       |
| -------------------- | ----------------------------------------------------------------------------------------------- |
| WIFEXITED(status)    | Normal beendet                                                                                  |
| WEXITSTATUS(status)  | Liefert Exitstatus unterste 8 Bit                                                               |
| WIFSIGNALED(status)  | Durch Signal beendet (z.B. abort)                                                               |
| WTERMSIG(status)     | Signalnummer (nur bei WIFSIGNALED)                                                              |
| WCOREDUMP(status)    | Prüft, ob ein Coredump erzeugt wurde (nur bei WIFSIGNALED und nicht auf jedem System verfügbar) |
| WIFSTOPPD(status)    | Kindprozess wurde durch Signal gestoppt                                                         |
| WSTOPSIG(status)     | Lifert Signal, dass zum Stop führte                                                             |
| WIFCONTINUED(status) | Kindprozess wurde fortgesetzt                                                                   |

#### Verweiste Kindprozesse ####

Endet ein Eltternprozess, ehe sich alle seine Kinder beenden so wird der init-Prozess neuer ELternprozess aller verwaisten Kinder. So ist gesichert, dass jeder Prozess einen Elternprozess hat. 

#### Zombieprozesse ####

Endet ein Kindprozess, ohne dass der Elternprozess auf diesen gewartet hat, so merkt sich der Kernel einige Informationen (u.a. PID, exit-status, verbrauchte CPU-Zeit) in seiner Prozesstabelle, bis das der Eltenrprozess wait() oder waitpid(..) aufruft und die Infos abfragt, bzw. damit der Elternprozess das zu einem späteren Zeitpunkt tun kann.

Den status des Prozesses setzt der Kernel dabei auf Z wie Zombie.

```c
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main (int argc, char **argv)
{
    int num = 0;

    while(num++ < MAX) {
        pid_t pid = fork();

        if (pid < 0) perror ("could not fork");
        else if (pid == 0) {
            // Kindeprozess
            printf("Kind nummer %d gestartet\n", num);
            sleep(2);
            printf("Kind nummer %d beenden\n", num);
            exit(EXIT_SUCCESS);
        }
    }

    int status;
    while (num-- > 0) 
    {
        wait(&status);
    }

    printf("Elternprozes beendet\n");

    return EXIT_SUCCESS;
}
```

##### Verhindern von Zombies #####

Zombies können vermieden werden, indem der ELternprozess auf seine Kinder wartet.

Alternativ:

EP -> wartet nur kurz auf Beenden von Kindprozess  
|  
|  
KP -> forkt ein zweites mal und beendet sich  
|  
|  
Enkel -> init prozess wird neuer Elternprozess(Enkel verwaist)

#### Informationen über benutzte Ressourcen ####

```c
#include <sys/types.h>
#include <wait.h>

pid_t wait3(int *status, int opt, struct rusage *usage);

pit_t wait4(pid_t pid, int *status, int opt, struct rusage *usage);
```

### 7.10 Synchronisation ###

Wenn mehrere Prozesse gemeinsam an einer Lösung arbeiten, so benötigt man i.d.R. eine Möglichkeit, diese untereinander zu synchronisieren, damit sie geordnet ablaufen können.

Für einfach Synchronisationsaufgaben können Signale verwendet werden, die es ermöglichen, dass ein Prozess auf ein eingehendes Signal eines anderen Prozesses wartet, bzw. einem anderen ein spezielles Signal zukommen lässt.

### 7.11 Systemruf exec ###

Nach dem Erzeugen einer Prozesskopie mittels (v)fork() läuft im Kindprozess das gleiche Programm, wie im Elternprozess, weiter ab.

Die Funktion exec() macht es möglich, das abzuarbeitende Programm im laufenden Prozess auszutauschen. Dabei wird das neue Programm von Anfang an (also mit main()) begonnen.

```c
#include <unistd.h>

int exec(const char *pfad, *pfad, const char *arg0, ... /* NULL */);

int execlp(const char *datei, const char *arg0, ... /* NULL */);

int execle(const char *pfad, const char *arg0, ... /* NULL */);

int execv(const char *pfad, char* const argv[]);

int execvp(const char *datei, char* const argv[]);

int execvpe(const char *datei, char* const argv[], char* const envp[]);

int execve(const char *pfad, char* const argv[], char* const envp[]);
```
- l… List, Argumentenliste (NULL-terminiert)
- v… Vector, Kommandozeilenargumente werden als Array übergeben (NULL-terminiert)
- p… Path, enthält der erste Parameter ein '/', so wird die Datei direkt ausgeführt, ist kein '/' vorhanden, wird im Suchpfad (PATH) nach einer ausführbaren Datei gesucht, enthält diese keinen Maschinencode, so wird eine Shell mit dieser Datei gestartet.
- e… Environment

#### Vererbung bei exec ####
Das neue Programme behält vom bisherigen Prozess alle verfügbaren Parameter und Einstellung. Das Schließen von geöffneten Dateien hängt vom close-on-exec-Flag ab. (Voreinstellung: AUS). Die effektive UID und GID werden nur beibehalten, falls das neue Programm das Set-UID oder Set-GID Flag nicht gesetzt hat.

### 7.12 Die Funktion system ###
```c
#include <stdlib.h>
	int system(const char *Kommandozeile);
```
Die Funktion system ist Teil der C-Standardbibliothek.
Sie kann verwendet werden, um eine Kommandozeile auszuführen, welche z.B. ein anderes Programm startet.

Intern ruft system(…) die Funktionen fork(…), exec(…), und waitpid(…) auf.
-> system kehrt erst zurück, wenn sich der Prozess beendet hat.

Der Rückgabewert ist -1 im Fehlerfall, ansonsten wird der wait()-Status des ausgeführten Programms zurückgeliefert.

>**Bem.:** Konnte die Shell (/bin/sh) nicht ausgeführt werden, liefert system den Status exit(127), übergibt man an system(…) einen NULL-Zeiger, kann getestet werden, ob eine Shell verfügbar ist. Der Rückgabewert ist ungleich 0, wenn Shell verfügbar, sonst 0.

### 7.13 Verändern von User ID und Group ID ###

```c
#include <sys/types.h>
#include <unistd.h>
	int setuid(uid_t uid);
	int setgid(gid_t gid);
	
	int seteuid(uid_t uid);
	int setegid(gid_t gid);
		 
	int setreuid(uid_t uid);
	int setregid(gid_t gid);
```

Rückgabe: 0 bei Erfolg, sonst -1.
Die erfolgreiche Ausführung hängt von zu beachtenden Regeln ab.

Sofern ein Prozess Superuser-Rechte besitzt, werden mit setuid(…) und setreuid(…) stets reale und effektive UserID gesetzt, mit setuid(…) ändert sich nur die effektive UID.
Besitzt der Prozess keine root-Rechte, ist also nicht privilegiert, darf ein Prozess seine reale und effektive UID immer nur vertauschen, gleiches gilt für die GID.

#### User-ID und Group-ID für Dateisystemzugriffe ####

Sofern ein Prozess Superuser-Rechte besitzt, werden mit setuid(…) und setreuid(…) stets reale und effektive UserID gesetzt, mit setuid(…) ändert sich nur die effektive UID.

Besitzt der Prozess keine root-Rechte, ist also nicht privilegiert, darf ein Prozess seine reale und effektive UID immer nur vertauschen, gleiches gilt für die GID.

## 8. Signale ##

Signale unter Unix sind sogenannte Software-Interrupts (soft-IRQ bzw. Signale), die im Kernel erzeugt und an Prozesse weitergeleitet werden.
Quellen für Signale können die Hardware (Interrupts) oder Software gesteuerte Ereignisse (Aufruf einer Systemfunktion, Druck einer bestimmten Taste, Senden eines bestimmten Signals)  sein. Das unter Unix angewandte Signalkonzept bedient sich dabei asynchroner Ereignisse (Signals), verschiedener Event-Handler (Signal-handler) und entsprechender Warteschlangen.
Prozesse haben die Möglichkeit auch Signale (asynchron) an andere Prozesse zu senden, diese können ihrerseits mit Signalen antworten. Das ermöglicht Kommunikation, die zu Synchronisationszwecken eingesetzt werden kann. Datenaustausch ist dabei (direkt) jedoch nicht möglich.

### 8.1 Einrichten von Signalhandlern ###

Die Funktion signal(…) ermöglicht es, einen benutzerdefinierten Signal-Handler für ein Signal einzurichten. Das Verhalten von signal(…) variiert unter verschiedenen Unix-Varianten. Es sollte deshalb besser das neue Signalkonzept mit der Funktion sigaction(…) benutzt werden.

```c
#include <signal.h>
	typedef void (* sighandler_t) (int);
	sighandler_t signal(int signum, sighandler_t handler);
```

Als Rückgabewert liefert signal(…) den vorher eingestellten Signalhandler, oder SIG_ERR (== -1)zurück.

Es gibt zwei Wildcards, die als Signalhandler registriert werden können:
```c
SIG_IGN (ignore) (== 1)
SIG_DFL (default) (== 0)
```

Möchte ein Prozess während der Bearbeitung eines kritischen Abschnittes, einen möglichen Abbruch mit [Strg] + C (SIGTERM) verhindern, so kann mit dem Handler SIG_IGN das Signal (vorübergehend) ignoriert werden. Dieses Szenario funktioniert auf allen Unix-Varianten.

Registriert man eine benutzerdefinierte Routine für ein Signal, so wird bei Auftreten des Signales zuerst der voreingestellte Handler (SIG_DFL) wieder eingesetzt oder die Signalbehandlung wird blockiert und danach der benutzerdefinierte Signalhandler mit der Signalnummer aufgerufen.

### 8.2 Kindprozesse und Signale ###

Kindprozesse, die mittels fork() erzeugt wurden, haben die gleichen Signalhandler wie der Elternprozess. Wenn exec(…) verwendet wird, dann werden aufgrund des Tausches des Maschinencodes, die benutzerdefinierten Handler ungültig und somit auf die voreingestellte Behandlung zurückgesetzt. Ignorierte Signale bleiben unberührt.

### 8.3 Signalnummer ###

Jedem Signal ist eine symbolische Konstante zugeordnet.
Die Nummer 0 ist nicht vergeben, wird von der Funktion kill(…) als spezieller Parameter verwendet.

> kill -l

| ---------------- | -------------------------------------------------------- |
| SIGABRT          | abort -> Beenden mit core-Datei                          |
| SIGALRM          | timer abgelaufen -> Beenden                              |
| SIGCHLD          | Statusänderung in Kindprozess -> Ignorieren              |
| SIGCONT          | Angehaltenen Prozess fortsetzen -> Fortsetzen/Ignorieren |
| SIGFPE           | Floating-Point-Exception -> Beenden mit core-Datei       |
| SIGHUP           | Verbindungsabbruch -> Beenden                            |
| SIGILL           | Unerlaubter Befehl -> Beenden mit core-Datei             |
| SIGINT           | Interrupt am Terminal mit [Strg] + C -> Beenden          |
| SIGKILL          | Beendigung durch töten -> Beenden                        |
| SIGPIPE          | Schreiben in Pipe ohne Leser -> Beenden                  |
| SIGQUIT          | Unterbrechungstaste Terminal -> Beenden mit core-Datei   |
| SIGSEGV          | Speicherzugriffsfehler -> Beenden mit core-Datei         |
| SIGSTOP          | Prozess anhalten im Terminal mit [STRG] + Z -> Anhalten  |
| SIGTERM          | Beendigung -> Beenden                                    |
| SIGUSR1, SIGUSR2 | benutzerdefiniertes Signal -> Beenden                    |
|----------------- | -------------------------------------------------------- |


### 8.4 Das neue Signalkonzept ###

**Signalmengen (~masken)**

Datentyp: sigset_t
verwendet für jedes Sinal 1 Bit

wird verwendet, um eine Menge von Signalen, während der Abarbeitung eines benutzerdef. Handlers, zu blockieren. Die Nummer des Bits ist die Signalnummer -1, da kein Signal die nummer 0 hat. 

```c
#include <signal.c>

int sigemptyset(sigset_t *set);

int sigfillset(sigset_t *set);

int sigaddset(sigset_t *set, int signalnr);

int sigdelset(sigset_t *set, int signalnr);

int sigismember(const sigset_t *set, int signalnr);
```

Bis auf sigismember(..), die entweder 1 (true) oder 0 (false) zurückgibt, liefern alle Funktionen im Erfolgsfall 0 zurück und ansonsten -1.

sigfillset, sigemptyset: initialisieren einer signalmenge mit Nullen (leer) oder Einsen (alle).

sigaddset, sigdelset: schalten einzelne Bits an oder aus.

Mit sigismember kann geprüft werden, ob ein Signal in den gegebenen Menge vorhanden ist oder nicht.

**Signalhandler einrichten**

Einrichten/Erfragen eines Signalhandlers mit Funktionen: 

```c
sigaction(..);
```

Anders als bei früheren Implementierungen bleibt ein mit sigaction(..) installierter Signalhandler so lange installiert, bis er explizit wieder geändert wird.

Tritt das gleiche Signal währen der Ausführung des Handlers erneut auf, wird es blockiert. 

```c
#include <signal.h>

int sigaction(int signr, const struct sigaction *act, struct sigaction *old_act);
```

Bei Erfolg liefert sigaction(..) den wert 0, und im Fehlerfall -1. Für die letzten beiden Parameter kann NULL angegeben werden, was bedeutet, dass man nur einen Handler abfragen oder nur setzen oder beides gleichzeitig machen möchte. 

Die Datenstruktur sigaction wird verwendet um neben dem Signalhandler die zu blockierende Signalmenge und Flags zu blockieren. 

```c
struct sigaction {
    /*Adresse des Signalhandlers*/
    void (*sa_handler)(int);

    /*Zu blockierende Signale*/
    sigset_t sa_mask;

    /*Optionen*/
    int sa_flags;
};
```

Optionen:

| Option       | Erklärung                                                                                                                                                                                |
| ------------ | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| SA_NOCLOSTOP | Signal SIGCHILD. wird nur ausgelößt, wenn sich Kindprozess beendet, nicht jedoch bei STOP                                                                                                |
| SA_NOCLDWAIT | Signal SIGCHILD. vermeidet Zombies. Ruft Elternprozess danach wait(..) auf, kehrt es erst zurück, wenn alle Kinder beendet sind                                                          |
| SA_RESTART   | Blockierende Systemaufrufe, die durch ein auftretendes Signal unterbrochen wurden, werden automatisch neu gestartet. Ist sas Flag nicht gesetzt, schlägt der Systemaufruf mit EINTR Fehl |
| SA_NODEFER   | Während der Ausführung eines Handlers wird das selbe Signal nicht automatisch blockiert                                                                                         |
| SA_RESETHAND | Bei Eintritt in die Routine wird der Defaulthandler wieder eingestellt                                                                                                                   |

**Synonyme unter Linux**

SA_NODEFER = SA_NOMASK
SA_RESETHAND = SA_ONESHOT

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

static int num;

void handler(int sig) 
{
    printf("%s %d", strsignal(sig), ++num);
}

int main(int argc, char **argv)
{
    sruct sigaction act = {handler, 0};

    if (sigaction(SIGUSR1, &act, NULL) == -1) perror("sigaction");

    while (1) {
        sleep(1)
    }

    return EXIT_SUCCESS;
}
```

**Signalmaske abfragen**

Möchte man mehrere Signale für einen Prozess blockieren, zum Beispiel während der Abarbeitung eines krititschen Bereiches, kann man dies durch Angabe einer Signalmenge in einem einzigen Funktionsaufruf tun.

```c
#include <signal.h>

int sigprocmask(int how, const sigset_t *set, sigset_t *dd_set);
```

Wie bei sigaction(..) kann sigprocmask(..) nicht nur zum Ändern der Signalmaske eingesetzt werden, sondern auch zum Abfragen der aktuellen Maske (gesteuert wird übergabe von NULL-Zeiger). 

Rückgabewerte sind im Erfolgsfall 0 und im Fehlerfall -1. 

Für das erste Element sind drei Werte möglich:

| Option      | Erklärung                                                       |
| ----------- | --------------------------------------------------------------- |
| SIG_BLOCK   | Signalmaske wird zur aktuellen Maske im Prozess hinzugefügt     |
| SIG_UNBLOCK | Aus aktueller Signalmaske des Prozesses werden Signale entfernt |
| SIG_SETMASK | Die aktuelle Signalmaske im Prozess wird überschrieben          |

**Hängende Signale**

Ankommende Signal, die von einem Prozess blockiert werden, bleiben hängen. Zur Abfragem welche Signale gerade hängen, verwendet man sigpending(..).

```c
#include <signal.h>

int sigpending(sigset_t *set);
```

Die Funktion liefert im Erfolgsfall 0, oder -1 bei Fehler.

**Erlaubte Systemaufrufe**

Während der Ausführung eines (benutzerdefinierten) Signalhandlers wird die eigentliche Ausführung des Programmes unterbochen. Nachdem das Signal bearbeitet wurde setzt der Prozess seine Ausführung an der entsprechenden Stelle fort.

Was kann dabei zu Problemen führen?

- eigene Programmierfehler durch verändern von Daten (Schleifenvariable) im Signalhandler
- Aufruf nicht reentranter Systemfunktionen, z.B. gleichzeitig in Programm in Programm u. Signalhandler
=> In Signalhandlern dürfen grundsätzlich nur reentrante Funktionen verwendet werden.	
**Senden von Signalen**

Um einen Prozess Signale senden zu können, muss man berechtigt sein. Berechtigt ist jeder sendende Prozess, der entweder Super-User-Rechte hat oder eine der User-Ids (real/effektiv) mit dem User-IDs des Empfänger-Prozess übereinstimmt.

Zum senden stehen 2 Funktionen zur Verfügung

```c
#include <sys/types.h>
#include <signal.h>

int raise(int signr);

int kill(pid_t pid, int signr);
```

Rücgabe 0 bei Erfolg, -1 bei Fehler.

Mit der Funktion raise(..) sendet ein Prozess ein Signal an sich selbst. Sollte dabei ein Signalhandler aufgerufen werden, so kehrt raise(..) erst nach der Ausführung der Handler-Funktion zurück.

Das senden eines Signals an einen anderen Prozess ermöglicht dagegen die Funktion kill(..).

Es gibt 4 mögliche Angaben für pid:

- pid > 0: Signal wird an Prozess mit pid geschickt
- pid == 0: Signal wird allen Prozessen der gleichen Prozessgruppe geschickt.
- pid == -1: Das Signal wird allen Prozessen (Broadcast) geschickt, soweit Berechtigungen ausreichend. Der aufrufende Prozess erhält das Signal selbst **nicht**.
- pid < -1: Das Signal wird an Prozessgruppe (pid) geschickt

An die Prozesse des Kernels selbst (swapper, init-Prozess) können keine Signale gesendet werden.

Das Senden eines NULL-Signals an eine pid bewirkt, dass kill(..) eine Überprüfung durchführt, ob ein Signal an den gewünschten Empfänger geschickt werden kann.

**Alarm.Timer einrichten**

Ein Alarm-Timer ist ein zeitgesteuertes bzw. zeit-verzögertes Signal. der Alarm-Timer wird mit alarm(..) eingestellt, welches nach ablauf der angegebenen Zeit das Signal SIGALRM an sich selbst sendet. Wird das Signal nicht durch einen benutzerdef. Handler abgefangen oder ignoriert, so beendet sich der Prozess.

```c
#include <unistd.h>

int alarm(unsigned int sekunden);
```

Liefert die Anzahl Restsekunden zurück, die ein zuvor gestarteter Timer noch gehabt hat, oder 0, wenn zuvor kein Timer eingerichtet war. 

Wird alarm(..) mit 0 sekunden aufgerufen, so wird ein aktuell laufender Timer abgebrochen und Restzeit ausgegeben.

Alternativ drei Systemtimer (ITIMER_REAL, ITIMER_VIRTUAL, ITIMER_PROF).

mittels: getitimer(..) und setitimer(..) gesetzt bzw. überprüft werden. 

ITIMER_REAL läuft in Echtzeit ab und liefert bei Ablauf SIGALRM

ITIMER_VIRTUAL läuft nur ab, während Prozess tatsächlich ausgeführt wird und liefert bei Ablauf SIGVTALRM.

ITIMER_PROF läuft sowohl während System- als auch Benutzermodus und liefert bei Ablauf SIGPROF.



**Suspendieren eines Prozesses**

Suspendieren bis bel. Signal eintrifft: pause();

```c
#include <unistd.h>

int pause(void);
```

Die Funktion kehrt nur zurück, wenn ein Signal empfangen wird. Rückgabe -1 bei Fehler, errno == EINTR

Neben pause() können noch sleep(..), usleep(..) und nanosleep(..) verwendet werden, um einen Prozess zu suspendieren.

Durch Angabe eines Zeitwertes kehren die Funktionen auch zurück, wenn kein Signal empfangen wurde.

Rückgabe: 0 bei Ablauf des Timers, sleep(..) liefert ansonsten die Restsekunden falls Schlaf durch Signal unterbrochen wurde. Die anderen beiden leifern in dem Fall -1.

sigprocmask(..) + pause (..) => sigsuspend(..)  
"Rücksetzen der Prozessmaske und warten auf Signal"

**Programmabbrucht mit abort**

Anomales Beenden eines Prozesses kann mit SIGABRT. Besser als bei SIGKILL kann ein Benutzer definierter Handler vor dem Beenden noch Aufräumarbeiten durchführen. 

```c
#include unistdh.h
void abort(void);
```

Die Funktion kehrt niemals zurück.

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

void handler(int sig) 
{
    int rest = alarm(0);
    printf("%d %s\n", rest, strsignal(sig));
    alarm(rest);
}

int main(int argc, char **argv)
{
    int dauer = 10;

    if (argc > 1) dauer = atoi(argv[1]);

    alarm(dauer);

    struct sigaction act = {handler, 0,0};

    if (sigaction(SIGUSR2, &act, NULL)) perror("sigaction");

    while (1) pause();

    return EXIT_SUCCESS;
}
```

## 11. Pipes und FIFOs ##

### 11.1 Pipes ###

Zwei wesentliche Eigenschaften:
- eine Pipe kann nur zwischen zwei verwandten Prozessen eingerichtet werden (Eltern-Kind). Typisch: Elternprozess richtet Pipe ein, es erfolgt fork(). Kindprozess erbt Pipe und beide können sie Benutzen.
- Eine Pipe ist stets Halp-Duplex, das heißt, sowie Daten auf einer Seite hineingeschrieben werden, so werden auf der anderen Seite ausgelesen. Dazu werden zwei Filedeskriptoren angeboten, einer zum Lesen, einer zum Schreiben. 

#### Einrichten einer Pipe ####

Systemfunktion: pipe(..)

```c
#include <unistd.h>

int pipe(int fd[2]); //zwei Filedeskriptoren
```

Die beiden Filedeskriptoren werden im angegebenen Übergabeparameter zurückgeliefert.

Rückgabe: 0 bei Erfolg, -1 sonst

Die Filedeskriptoren sind bereits geöffnet, fd[0] zum Lesen, fd[1] zum Schreiben.

Nach fork() haben beide Prozesse Lese- und Schreibmöglichkeit, Anwendungsentwickler entscheidet die Richtung. Zur vereinfachung können die Prozesse nicht genutzte Filedeskriptoren schließen.

Wird eine Seite der Pipe geschlossen resultieren 2 Regeln:

1. Beim Lesen aus einer Pipe, deren Schreibseite geschlossen ist, liefert read(..) den Wert 0 (EOF).

2. Beim Schreiben in einer Pipe, aus der keiner mehr ließt (Leseseite geschlossen) liefert write(..) einen Fehler und es wird SIGPIPE an den Prozess gesendet.

#### Verknüpfung von Pipe mit Standardeingabe ####

Nach einem Aufruf von fork() folgt häufig ein Aufruf der Funktion exec().

Will man eine Pipe verwenden (mit fremden Programmcode), so ist Überlagerung eines Standardkanals nötig. Funktion dub2(..) -> close-on-exec Flag wird bei dub2(..) nicht gesetzt.

#### Pipe zu einem anderen Programm ####

Oft möchte man die Ausgabe eines anderen Programmes lesen oder auf die standardeingabe des Programmes schreiben.

```c
#include <stdio.h>

FILE *popen(const char *cmdline, const char *typ);

int pclose(FILE *stream);
```

Die Funktion popen(..) liefert bei Erfolg einen Dateizeiger, ansonsten -1.

Die Funktion pclose(..) liefert im Normalfall den Existstatus des Programmes, ansosnten -1.

cmdline ist NULL-Terminierte Kommandozeile und wird in Subshells ausgeführt. Der Typ gibt an ob gelesen 'r' oder geschriebene 'w' werden soll, beides gleichzeitig ist nicht möglich.

Der Stream **muss** mit pclose(..) geschlossen werden. fclose erzeugt Zombie.

### 11.2 Benannte Pipes (FIFOs) ###

Währen pipes nur zwischen Verwandten Prozessen eingesetzt werden können, kann man mit FIFOs auch zwischen bekannten Prozessen Daten austauschen. FIFOs werden auch ales "named Pipes" bezeichnet. 

#### Kreieren einer benannten Pipe ####

```c
#include <sys/types.h>
#include <sys/stat.h>

int mkfifo(const char *path, mode_t mode);
```

Die Funktion liefert 0 bei Erfolg, sonst -1.

Der aufruf bewirkt, dass Datei namens path erzeugt wird. Das ist keine reguläre Datei, sondern eine FIFO. Das Argument mode gibt Zugriffsrechte an.

Danach können beliebige Prozesse die FIFO Lesen oder Schreiben.

#### Zugriffsregeln für FIFOs ####

- Blockierendes Öffnen einer FIFO wird beim Öffnen einer FIFO das Flag O_NONBLOCK **nicht** verwendet (Normalfall). So blockiert Open mit Modus O_RDONLY so lange, bis FIFO auch zum Schreiben geöffnet wird. Umgekehrt wird ein open(..) mit O_WRONLY so lange blockiert, bis FIFO auch zum LEsen geöffnet wird
- Nicht Blockierendes Öffnen einer FIFO. Ist das Flag O_NONBLOCK gesetzt kehrt open(..) mit O_RDONLY sofort zurück. Ein open(..) mit O_WRONLY dagegen führt zu Fehler (ENXIO), falls die FIFO nciht bereits zum lesen geöffnet wurde.
- Schreiben einer FIFO ohne Leser. Wird in eine FIFO gescheribeen, die nocht auch zum Lesen geöffnet ist, wird SIGPIPE generiert.
- Lesen einer FIFO  ohne Schreiber schließ der letzte Schreibende Prozess die FIFO, wird für den Leser ein EOF erzeugt.
- Gleichzeitiges Schreiben meherere Prozesse. Es ist garantiert, dass sich Daten nicht mischen, so lange nicht mehr als PIPE_BUF Bytes auf einmal geschrieben werden.

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>

void handler(int sig)
{
    printf("cought signal: %s\n", strsignal(sig));
}

int main(int argc, char **argv)
{
    struct sigaction act = {handler, 0};
    sigaction(SIGPIPE, &act, NULL);

    int fd[2];

    if(pipe(fd)) perror("pipe");

    char *str = "I am writing a text t oa pipe, which is buffered in kernel\n";

    int len = strlen(str);

    if (len != write(fd[1], str, len)) perror("write");

    char buf[len];

    buf[0] = 0;

    if (len != read(fd[0], str, len)) perror("read");

    printf("%s", buf);

    return EXIT_SUCCESS;
}
```

## 12 interprozesskommunikation ##

Message-Queues, Semaphore und Shared-Memory

### 12.1 Kennungen und Schlüsell ###

Der Kernel verwaltet die IPC-Hilfmittel weitestgehend einheitlich. Jedem IPC-Objekt wird eine Systemweit eindeutige Nummer (Kennung/Identifier) zugeordnet. Jeder Prozess, der den Identifikator eines IPC-Objektes kennt, kann sicht mit diesem verbinden. Das erzeugen von IPC-Objekten geschieht implizit. Bei einer Verbindungsanfrage mit den Funktionen: msgget, semget, shmget. 

Dabei erwarten diese Funktionen stets die Angabe eines Schlüssels. ISt ein Objekt mit entsprechenden Schlüssel verfügbar, so wird dessen Kennung zurückgeleifert. Gibt es kein passendes Objekt, so wird ein neues eingerichtet. Möchte man sicher ein neues Objekt erzeugen, nutzt man die Kennung IPC_PRIVATE.

### 12.2 Erzeugen eines neuen Objektes ###

Die Funktionen akzeptieren Flags. 
Zum Erzeugen muss das Flag IPC_CREAT anegegeben werden. Ist außerdem das Flag IPC_EXCLUSIVE gesetzt, so liefern die Funktionen einen Fehler (-1), falls zu gegebenen Schlüssel bereits ein Objekt exisitert. 

### 12.3 Verbinden mit einem vorhandenen Objekt ###

Möchte man die Kennung eines vorhandenen Objektes erfragen, muss man denselben Schlüssel benutzen, wie beim Erzeugen. Außerdem darf IPC_CREATE nicht gesetzt sein.

```bash
$> ipcs
```
### 12.4 Löschen von Objekten ###

IPC-Objekte existieren solange, bis sie explizit gelöscht werden, oder ein shutdown erfolg.

Der Erzeuger, Eigentümer oder Benutzer mit entsprechenden Rechten dürfen ein IPC-Objekt löschen. 
Zum Löschen können die Funktionen verwendet werden:
- msgctl
- semctl
- shmctl
> Dabei muss das Kommando (kdo.) IPC_RMID verwendet werden.


```bash
$> ipcrm
```

### 12.5 Zugriffsrechte ###

Zu jedem Objekt können Zugriffsrechte abgefragt bzw. modifiziert werden.

```c
#inlcude <sys/ipc.h>
struct ipc_perm
{
    uid_t uid; // effektive UID Owner
    gid_t gid; // -"- GID -"-
    uid_t cuid; // -"- UID Creator
    gid_t cgid; // -"- GID -"-
    mode_t mode; // Zugriffsmodus (rw-rw-rw-)
    ulong seq; // Kennung
    key_t key; // Schlüssel
};
```

> Die Werte für uid, gid und mode können nachträglich geändert werden.
> Zugriffsrechte gleichen denen der stat-Struktur, mit Unterschied, dass nur Lesen und Schreiben verwendet wird.

### 12.6 Limits ###

Für alle IPC-Objektarten sind Limits festgelegt, die in der Regel nur durch Neukonfiguration des Kernels verändert werden können.

### 12.7 Message-Queues ###

Nachrichtenwarteschlangen werden im Kernel als verkettete Listen verwaltet. Die Einrichtung geschieht mit msgget(…), das Senden und Empfangen mit msgsnd(…) und msgrcv(…).
Jede Message besteht aus einem Nachrichtentyp (long) und einem Puffer.

#### Status einer Warteschalnge ####

Für Statusabfragen zu einer Warteschlange steht die Datenstruktur msqid_ds zur Verfügung.
Das gibt Auskunft über z.B. Zugriffsrechte, Adr. der ersten Nachricht, Adr. der letzten Nachricht, Anzahl Bytes in der Queue, maximale Anzahl Bytes, PID letzter Sender, PID letzter Empfänger, Zeiten: letztes Senden, letztes Empfangen und letzte Änderung.

#### Limits ####

- MSGMAX -> Maximalgröße einer Nachritcht
- MSGMNB -> maximum number of Bytes in Queue
- MSGMNI -> max. Anzahl Warteschlangen in System
- MSGTQL -> max. Anzahl Messages in System

#### Erzeugen einer Message-Queue ####

```c
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
    
int msgget(key_t schluessel, int flag);
```

> Lierfert Kennung bei Erfolg oder -1 bei Fehler.

#### Senden einer Nachricht ####

```c
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int msgsnd(int kennung, const void *puffer, size_t mlaenge, int flags);
```

> Rückgabewerte: 0 bei Erfolg, sonst -1.
Ist die Warteschlange voll, so blockiert msgsnd(…) normalerweise bis
- die Warteschlange entsprechend Platz bietet.
- die Warteschlange gelöscht wird. (EIDRM)
- ein Signal den Wartezustand unterbricht. (EINTR)
Soll msgsnd(…) nicht blockieren, so muss IPC_NOWAIT gesetzt sein. Ist die Warteschlange voll, liefert dies Fehler (EAGAIN).

> Bemerkung: Die Angabe mlaenge bezieht sich auf Nutzdaten und darf nicht 0 sein.

#### Aufbau einer Nachricht ####
Prinizipiell kann das Format einer Nacricht frei gewählt werden. Unix erwartet jedoch, dass die ersten sizeof(long) Byte einer Nachricht stets eine positve Zahl ungleich 0 sind.
Unix bietet Prioritätensystem basierend auf Typ einer Nachricht.
Empfehlung:

```c
struct msg
{
    long type; //Zu Beginn der Nachricht befindet sich der Typ
    char mtext[len]; // Anschließend folgen die eigentlichen Daten, länge kann fest oder variabel 
                    //sein, speicher muss aber zusammenhängend sein
};
```    

#### Empfang einer Nachricht ####

```c
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
    
int msgrcv(int kennung, void *puffer, size_t maxlen, long typ, int flags);
```
    
Der Rückgabewert ist im Erfolgsfall die tatsächliche Länge der Nachricht.
Ist die zu empfangene Nachricht größer als Maxlen, liefert msgrcv(…) den Fehelr (E2BIG) und die Nachricht verbleibt in Warteschlange.
Ist zusätzlich das Falg MSG_NOERROR gesetzt, werden überzählige Bytes abgeschnitten.
Das Argument typ legt den Typ der Nachricht fest:
- typ == 0 : Erste Nachricht aus Queue (wie FIFO)
- typ > 0   : Erste Nachricht mit gewünschten Typ, ist Flag MSG_EXCEPT gesetzt, wird erste Nachricht gewählt, die typ nicht hat
- typ < 0   : Erste Nachricht, deren Typ <= |typ| ist.
    
> Bemerkung: Bei Client-Server Anwendungen wird oft die PID bzw. Kennung der Antwortwarteschlange als Typ verwendet (Multiplex).

