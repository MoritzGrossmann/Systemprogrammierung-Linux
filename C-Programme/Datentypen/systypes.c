#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <signal.h>
#include <sys/time.h>
#include <sys/resource.h>

int main (int argc, char **args) {
printf("Typ\t\t Groesse [Byte]\n");
printf("---------------------------------------------------\n");
printf("caddr_t\t\t%lu\n",      sizeof (caddr_t));
    printf("clock_t\t\t%lu\n",      sizeof (clock_t));
    printf("dev_t\t\t%lu\n",        sizeof (dev_t));
    printf("fd_set\t\t%lu\n",       sizeof (fd_set));
    printf("fpos_t\t\t%lu\n",       sizeof (fpos_t));
    printf("gid_t\t\t%lu\n",        sizeof (gid_t));
    printf("ino_t\t\t%lu\n",        sizeof (ino_t));
    printf("mode_t\t\t%lu\n",       sizeof (mode_t));
    printf("nlink_t\t\t%lu\n",      sizeof (nlink_t));
    printf("off_t\t\t%lu\n",        sizeof (off_t));
    printf("pid_t\t\t%lu\n",        sizeof (pid_t));
    printf("ptrdiff_t\t%lu\n",      sizeof (ptrdiff_t));
    printf("rlim_t\t\t%lu\n",       sizeof (rlim_t));
    printf("sig_atomic_t\t%lu\n",   sizeof (sig_atomic_t));
    printf("sigset_t\t%lu\n",       sizeof (sigset_t));
    printf("size_t\t\t%lu\n",       sizeof (size_t));
    printf("ssize_t\t\t%lu\n",      sizeof (ssize_t));
    printf("time_t\t\t%lu\n",       sizeof (time_t));
    printf("uid_t\t\t%lu\n",        sizeof (uid_t));
    printf("wchar_t\t\t%lu\n",      sizeof (wchar_t));
    return 0;
}
