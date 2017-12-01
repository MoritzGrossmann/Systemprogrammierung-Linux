# Systemprogrammierung Linux #

- [Systemprogrammierung Linux](#systemprogrammierung-linux)
    - [Öffnen von Dateien mit C-Standard](#%C3%B6ffnen-von-dateien-mit-c-standard)
        - [Flags](#flags)
    - [3. Fehlerbehandlung](#3-fehlerbehandlung)
        - [Error.h](#errorh)
    - [Parsen von Kommandozeilen](#parsen-von-kommandozeilen)
        - [Abstrakt](#abstrakt)
        - [Probleme](#probleme)
        - [Abhilfe](#abhilfe)
    - [Elementare I/O-Operationen](#elementare-io-operationen)
        - [Wichtige Header](#wichtige-header)
        - [Filediskreptoren](#filediskreptoren)
            - [Typische Filediskreptoren](#typische-filediskreptoren)
            - [Verwendete Datei des Kernels anzeigen](#verwendete-datei-des-kernels-anzeigen)
        - [Lesen und Schreiben von Dateien](#lesen-und-schreiben-von-dateien)
            - [Öffnen einer Datei](#%C3%B6ffnen-einer-datei)
            - [Lesen und Schreiben einer Datei](#lesen-und-schreiben-einer-datei)
            - [Schließen einer Datei](#schlie%C3%9Fen-einer-datei)
        - [Lesen einer Datei](#lesen-einer-datei)
        - [Schreiben einer Datei](#schreiben-einer-datei)
        - [Filedeskriptoren in Prozesstabelle](#filedeskriptoren-in-prozesstabelle)
        - [Schreib-Lesezeiger positionieren](#schreib-lesezeiger-positionieren)
            - [Positionierung im stdid](#positionierung-im-stdid)
            - [Duplizieren von Filedeskriptoren](#duplizieren-von-filedeskriptoren)
            - [Letzten 20 Bytes einer Datei in sdtout ausgeben](#letzten-20-bytes-einer-datei-in-sdtout-ausgeben)
        - [Kontrolle der Eigenschaften einer Datei](#kontrolle-der-eigenschaften-einer-datei)
        - [Filezeiger](#filezeiger)
    - [Arbeiten mit Dateien und Verzeichnissen](#arbeiten-mit-dateien-und-verzeichnissen)
        - [Attribute von Dateien](#attribute-von-dateien)
            - [Auslesen der Datei-Attribute](#auslesen-der-datei-attribute)
        - [Dateiarten](#dateiarten)
            - [Makros zum Test des Dateityps](#makros-zum-test-des-dateityps)
        - [Dateisystemverlinkungen](#dateisystemverlinkungen)
        - [Dateigröße](#dateigr%C3%B6%C3%9Fe)
        - [Lesen von Verzeichnissen](#lesen-von-verzeichnissen)
        - [Gerätedateien](#ger%C3%A4tedateien)
            - [Spezielle Gerätedateien](#spezielle-ger%C3%A4tedateien)
        - [Puffercache](#puffercache)
    - [Prozesse unter Linux](#prozesse-unter-linux)
        - [Start eines Prozesses](#start-eines-prozesses)
        - [Beenden eines Prozesses](#beenden-eines-prozesses)
            - [Exit-Status eines Prozesses](#exit-status-eines-prozesses)
            - [Beenden ohne Aufräumen](#beenden-ohne-aufr%C3%A4umen)
            - [Zusätzliches Aufräumen](#zus%C3%A4tzliches-aufr%C3%A4umen)
        - [Umgebungsvariablen](#umgebungsvariablen)

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

## 3. Fehlerbehandlung ##

Die Fehlerbehandlung in C besteht aus einem Fehlercode (Fehlernummer) und etwaigen Beschreibungen

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
#include <sdtio.h>
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

liefert entsprechenden Zeiger auf die Fehlermeldung. Ist die Fehlernummer unbekannt wird "Unknown error nnn" zurückgelifert

```c
#include <sdtio.h>
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

## Parsen von Kommandozeilen ##

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
- optionen können in Kommandozeile fehlen (bedeutet: rüfung auf Pfilchtparameter)

> Ergo: für jede Problem benötigt man Fehlerbehandlung),
> Nutzer soll wissen, was er falsch gemacht hat

### Abhilfe ###

```c
int getopt(int argc, char *argv[], char *optString);
```

> Header: unix-standard-Header **<unistd.h>**

```c
extern char *optarg;   //ist gesetzt, wenn es Argumente gab
```

Rückgabewert von getopt ist die gefundene Option (ein character). Im Fehlerfall ein '?' (unbekannte Option) oder ':' (pflichtparameter fehlt) bzw leere Menge (kommandozeile zuende)

Unter Linux sind oft noch "lange" optionen, sogenannte Long-options erlaubt.

```c
int getop_long(...); //Arbeitet im Prinzip wie getopr

```

lange optionen werden mittels Struktur

```c
struct option;
```

angegeben

Bsp.:

```{r, engine='sh', count_lines}
prog --field=1 --xcoord 20 --ycoord=10
```

> short-options werden exact so behandelt wie bei getopt  
> Die struct option bezieht sich nur auf die long options

## Elementare I/O-Operationen ##

### Wichtige Header ###

```c
#include <unistd.h>
#include <fcntl.h>
```

### Filediskreptoren ###

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

### Lesen und Schreiben von Dateien ###

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
- O_CREATE neu anlegen, falls Datei nicht exisitert
- O_EXCL verhindert öffnen, fall Datei bereits existiert
- O_TRUNC Bewirkt Abschneiden, sodass sie neu geschrieben wird
- O_SYNC warte bis schreibvorgang abgeschlossen ist

#### Lesen und Schreiben einer Datei ####

| Flag     | Beschreibung                                                            | Oktal |
| -------- | ----------------------------------------------------------------------- | ----- |
| O_NOCTTY | falls ein Terminal geöffnet wird, soll es nicht Kontrollterminal werden |
| O_CREAT  |
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

> Alternativ kann zum Erzeugen einer Datei auch create(...) verwendet werden. Das ist Äquivalent zu open(...) mit den Flags O_CREAT | O_WRONLY | O_TRUNC

**Beipspiel**

```c
#include <sys/stat.h>
#include <sys/types.h>
#include <fctnl.h>
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

### Lesen einer Datei ###

```c
#include <unistd.h>

ssize_t read(int fd, void *buffer, size_t bytes);
```
**Rückgabe:** tatsächlich gelesene Anzahl Bytes, oder 0, falls Dateiende erreicht oder -1 im Fehlerfall

### Schreiben einer Datei ###

```c
#include <unistd.h>

ssize_t write(int fd, void *buffer, size_t bytes);
```

**Rückgabe:** tatsächliche Anzahl geschriebener Bytes, oder -1 im Fehlerfall

> Bemerkung: Geschriebene Daten werden zunächst in einem Cache gesammelt und zu einem späteren Zeitpunkt auf das physische Gerät geschrieben. **Wenn Sync-Flag beim öffnen gesetzt, dann wird sofort geschrieben**

> Zwischenzeitliches Lesen wird dann aus dem Cache beantwortet

> erhöht Schreibgeschwindigkeit, mit dem Nachteil, dass im falle eines Systemabsturzes die Daten verloren sind

> Setzt man das Flag **O_SYNC** so kehrt write(...) erst dann zurück, wenn die daten tatsächlich auf das Medium geschrieben sind

### Filedeskriptoren in Prozesstabelle ###

| fd | Flags  | Zeiger|
|----|--------|-------|
| 0  | RDONLY |       |
| 1  | WRONLY |       |
| 2  | WRONLY |       |
| 3  |        |       | 
| 4  |        |       |

**Dateitabelle**

|...|
|---|
|filestatus |
| Position Lese-Schreibzeichen |
| V-node zeiger |
|...|
| status flags |
| Position Lese-Schreibzeichen |
| V-node zeiger |

**V-node Tabelle**

|...|
|---|
|v-node Info |
|i-node Info |
||

> Ein weiterer Prozess öffnet die gleiche Datei mit einem neuen Schreib-Lesezeiger

### Schreib-Lesezeiger positionieren ###

Öffnet man eine Datei normal, befindet sich der Zeiger am Anfang der Datei. 
  
Wird eine Datei mit O_APPEND-Flag geöffnet, befindet sich der Zeiger vor jedem Schreiben am Ende der Datei.

Jede Schreib- oder LEseoperation bewegt den Zeiger um die tatsächliche Anzahl Bytes vorwärts. 

Zur Positionierung des Lese-Schreibzeigers kann die Funktion **lseek(..)** verwendet werden. 

```c
#include <unistd.h>
#include <sys/types.c>

off_t lseek(int fd, off_t offset, int woher);

//Rückgabewert ist die neue Position des Zeigers oder -1 im Fehlerfall
```

| Parameter | Erklärung                                                         |
|-----------|-------------------------------------------------------------------|
| offset    | legt die Byteanzahl fest, u die verschoben werden soll            |
| woher     | legt fest, von wo die Verschiebung statt findet, also Richtung. Dafür kennt l_seek 3 verschiedene Werte |
  

| Wert | Erklärung |
|-|-|
| SEEK_SET | von Dateianfang Richtung Ende. Nur positiver Offset |
| SEEK_CUR | von aktueller Poistion, Richtung durch Vorzeichen von Offset bestimmt |
| SEEK_END | vom Dateiende, Richtung wird durch Vorzeichen bestimmt |

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

int dub(int fd);

int dub2(int fd, int fd2);

// Rückgabe: neuer Filedeskriptor bei Erfolg oder -1 im Fehlerfall
```

Erster Parameter ist jeweils der zu duplizierender Filedeskriptor. dub(..) liefert den nächsten frieen Deskriptor zurück.  

dub2(..) liefert als neuen Filedeskriptor den Wert des zweiten Deskriptor. 

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

#### Letzten 20 Bytes einer Datei in sdtout ausgeben ####

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

### Kontrolle der Eigenschaften einer Datei ###

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

### Filezeiger ###

Die Standard C-Biblothek verwendet anstelle von Filedeskriptoren Zeiger auf eine Filestruktur.

```c
#include <stdio.h>

int fileno(FILE *fp);

FILE *fdopen(int fd), const char *modus);
```

fileno liefert den Filedeskriptor zu einem FILE-Pointer.  
fdopen liefert einen Zeiger auf eine FILE-Struktur oder NULL im Fehlerfall.
Der Parameter modus legt Zugriffsart fest ("r", "w", "a", "b", "+" (in Kombination))

Dateiinhalt wird bei "w" nicht (wie bei fopen) gelöscht.

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

## Arbeiten mit Dateien und Verzeichnissen ##

### Attribute von Dateien ###

```c
struct stat {
    dev_t st_dev;           //Nummer des Gerätes, welches Datei enhält
    ino_t st_ino;           //I-node Nummer
    mode_t st_mode;         //Dateiart und Zugriffsrecht
    nlink_t st_nlink;       //Anzahl der Links
    uid_t std_uid;          //User-ID
    gid_t st_gid;           //Group-ID
    dev_t st_rdev;          //Gerätenummer, spezielle Datei
    off_t st_size;          //Größte in Byte
    blksize_t st_blksize;   //Optimal Blockgröße für File-I/O
    blkcnt_t st_blocks;     //Anzahl belegter 512-Byte Blöcke
    time_t st_atime;        //(Access) Zugriffszeit
    time_t st_mtime;        //(Modify) Änderungszeit
    time_t st_ctime;        //(Change) Änderungszeit des i-node
}
```

#### Auslesen der Datei-Attribute ####

```c
#include <sys/types.h>
#include <sys/stat.h>

int stat(const char *pfadname, struct stat *puffer);

int fstat(int fd, struct stat *puffer);

int lstat(const char *pfadname, struct stat *puffer);
```

Die Funktion lstat zeigt, falls es sich bei der Pfadangabe um einen symbolischen Link handelt, die Attribute des Links selbst an. 

### Dateiarten ###

Reguläre Datei: Text-/Binärdateien in beliebigen Format  
Verzeichnis: Datei mit Liste von Verzeichniseinträgen und zugehörigen I-node nummern  
Gerätedatei (special File): logische Beschriebungsdatei von physischem oder virtuellem Gerät, I/O-Operationen verwenden jeweiligen Gerätetreiber.

> Unterscheidung: Zeichenorientiertes Gerät (character Device), Blockorientiertes Gerät (block Device)

FIFO (named Pipe): Werden zur Interprozesskommunikation verwendet. Können nur ein mal gelesen werden, keine Sprünge erlaubt  
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

### Dateisystemverlinkungen ###

### Dateigröße ###

### Lesen von Verzeichnissen ###

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

Diese akzeotiueren eine callback-Benutzer-Funktion, welche für jeden Verzeichniseintrag aufgerufen wird.

Unterschied: Behandlung Symbolischer Links

ftw: folgt Symlinks  
nftw: optional, kann eingestellt werden

```c
#include <ftw.h>

int ftw(const char *dirpath, int (*fn) (const char *path, const struct stat *sb, int type flags), int nopenfd);
```

Der Rückgabewert von ftw ist der Rückgabewert der übergebenen Funktion.

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

### Gerätedateien ###

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

### Puffercache ###

```c
#include <unistd.h>

void sync(void);

int fsync(int fd);

```

fsync liefert bei Erfolg 0, sonst -1  
Beide veranlassen den Kernel gepufferte Daten physisch zu schreiben
Sync trägt bei Kernel ein, dass alle geöffneten Dateien zu schreiben sind und kehrt sofort zurück  
Dem gegenüber bezieht sich fsync(...) nur auf eine Datei und veranlasst auch nur das Schreiben dieser. fsync kehrt erst zurück, wenn physikalischer schreibprozess abgeschlossen.

Physikalische Schreibprozesse werden von einem Hintergrundprozess etwas alle 30 Sekunden automatisch ausgeführt.

## Prozesse unter Linux ##

Ein laufendes Programm in einem Multitasking-Betriebssystem wird Prozess genannt.  
Jeder Prozess läuft in einer Umgebung (Environment), er benötigt Seicher, benötigt Zugriff auf Ressourcen, das Dateisystem, externe Geräte, Treiber etc. Auch Treiber sind Programme. Es muss auch geregelt sein, wie Prozesse, zum Zwecke des Datenaustausches oder spezieller Benachrichtigungen, miteinander kommunizieren können.

### Start eines Prozesses ###

```c

int main(int argc, char **argv);

```

Das Array argv enthält an der Stelle argv[argc] einen NULL-Pointer. (POSIX /C-Std).

### Beenden eines Prozesses ###

Linux unterscheidet zwei Arten, wie ein Prozess beendet werden kann.  
Normalerweise endet ein Prozess mit dem Ende der main-Funktion und entsprechenden Rückgabewert.  
Alternativ kann die Funktion exit(...) verwendet werden. Ein Prozess kann auch beendet werden, wenn man die Ausführung abbricht, mittels abort(...) oder einem externen Signal.

#### Exit-Status eines Prozesses ####

Beendet sich ein Programm regulär, leifert es einen Wert zurück. Der Wert kann Aufschluss übder den Erfolg des Programmes geben.

Im ERfolgsfall typischerweise 0, bei Fehler einen Wert verschieden von 0.

#### Beenden ohne Aufräumen ####

Beendet sich ein PRogramm normal, werden zuvor alle Puffer geleert, alle Dateien geschlossen und die mit der Funktion tempfile() angelegten Dateien gelöscht. Nach dem aufräumen ruft exit(...) seinerseits _exit(...) auf, um zum KErn zurück zu kehren.

```c
#include <stdlib.h>

void _exit(int status);

```

Von POSIX vorgeschrieben, bewirkt sofortiges Beenden und Rückkehr zum KErn, ohne Aufräumen.

#### Zusätzliches Aufräumen ####

Bei regulären Beenden können benutzerdefinierte Routinen registriert und Aufgerufen werden.

```c
#include <unistd.h>

int atexit(void (*function)(void))

```

Im Fehlerfall liefert atexit(...) einen Wert ungleich 0

### Umgebungsvariablen ###

Die Liste der Umgebungsvariablen ist, wie  die Argumentliste (argv), ein Array aus Zeichenketten. Diese Nullterminiert, wie die Liste selbst.  
Durch Deklaration der globalen Variablen 
```c
extern char **environ; 
```
kann auf die Umgebungsvariablen zugegriffen werden. Die Variablenbelegnung sind Strings der Form name=Wert.