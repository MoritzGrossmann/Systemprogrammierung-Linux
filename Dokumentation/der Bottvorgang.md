# Der Bootvorgang #

## dmesg ##

- Auslesen des Logs vom Bootvorgang

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
    - 

## Logfiles ##

Die meisten logs befinden sich unter **/var/log**

### syslogd ###

- logging Deamon
- schreibt normalerweise in **/var/log/messages**
- neuer dings in Datenbank, wird abgefragt mit **joernalctl**

### journalctl ###

> **moritz@Latitude-E5520 ~ $** journalctl