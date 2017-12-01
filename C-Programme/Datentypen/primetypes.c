#include <stdio.h>
#include <limits.h>
#include <float.h>

int main (int argc, char **args) {
    printf("int \t\t %lu     von %d bis %d \n", sizeof (int)*8, INT_MIN, INT_MAX);
    printf("long \t\t %lu     von %ld bis %ld \n", sizeof (long)*8, LONG_MIN, LONG_MAX);
    printf("short \t\t %lu     von %d bis %d \n", sizeof (short)*8, SHRT_MIN, SHRT_MAX);
    printf("char \t\t %lu      von %d bis %d \n", sizeof (char)*8, SCHAR_MIN, SCHAR_MAX);
    printf("float \t\t %lu     von %f bis %f \n", sizeof (float)*8, FLT_MIN, FLT_MAX);
    printf("double \t\t %lu     von %f bis %f \n", sizeof (double)*8, DBL_MIN, DBL_MAX);
    return 0;
}