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

> **moritz@Latitude-E5520 / $** ls</br>
> bin   cdrom  etc   initrd.img      lib    lib64       media  opt   root  sbin  sys  usr  vmlinuz</br>
> boot  dev    home  initrd.img.old  lib32  lost+found  mnt    proc  run   srv   tmp  var  vmlinuz.old</br>

## /bin ##

- die wichtigsten Programme

## /dev ##

- Gerätedateien

### Bsp.: Festplatten ###

#### Nach Pfad ####

> **moritz@Latitude-E5520 / $** ls /dev/disk/by-path/</br>
> pci-0000:00:1f.2-ata-1  pci-0000:00:1f.2-ata-1-part1  pci-0000:00:1f.2-ata-1-part2  pci-0000:00:1f.2-ata-1-part3  pci-0000:00:1f.2-ata-2

#### Nach UUID ####

> **moritz@Latitude-E5520 / $** ls /dev/disk/by-uuid/</br>
> 4e7490ec-7fce-4ceb-9699-0ff40076a767  e9aca507-c962-4381-a934-8a93bbda37a0  F3C6-8EC8

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