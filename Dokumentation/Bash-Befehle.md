# Bash-Befehle #

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

> **moritz@Latitude-E5520 ~ $** ps</br>
> PID TTY          TIME CMD</br>
> 11983 pts/0    00:00:00 bash</br>
> 13709 pts/0    00:00:00 ps</br>

> **moritz@Latitude-E5520 ~ $** ps -a</br>
> PID TTY          TIME CMD</br>
> 13211 tty1     00:00:00 bash</br>
> 13733 pts/0    00:00:00</br>

> **moritz@Latitude-E5520 ~ $** ps -aux</br>
> USER       PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND</br>
> root         1  0.0  0.0 119984  6184 ?        Ss   09:41   0:01 /sbin/init splash</br>
> root         2  0.0  0.0      0     0 ?        S    09:41   0:00 [kthreadd]</br>
> ...</br>
> root     13264  0.0  0.0  17492  1820 tty3     Ss+  10:10   0:00 /sbin/agetty --noclear tty3 linux</br>
> root     13268  0.0  0.0  17492  1828 tty4     Ss+  10:10   0:00 /sbin/agetty --noclear tty4 linux</br>
> root     13271  0.0  0.0  17492  1824 tty5     Ss+  10:10   0:00 /sbin/agetty --noclear tty5 linux</br>
> moritz   13378  6.8  2.0 3374780 168872 ?      Sl   10:11   0:18 /home/moritz/.dropbox-dist/dropbox-lnx.x86_64-36.4.22/dropbox</br>
> moritz   13582 11.6  2.4 3877292 194824 ?      SLl  10:13   0:17 evolution</br>
> moritz   13778  0.0  0.0  38992  3496 pts/0    R+   10:15   0:00 ps -aux</br>

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
