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