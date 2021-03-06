#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <libgen.h>
#include <getopt.h>

struct myparam {
  unsigned char x:1, y:1, z:1;
  unsigned char val;
};

int main(int argc, char *argv[])
{
  //printf("opterr: %d, now set to 0.\n", opterr);
  //opterr = 0;

  printf("bitfeld: %d\n", sizeof(struct myparam)*8);
 
  struct myparam param = {0}; 


  struct option longOpts[] = {
    {"xcoord", required_argument, NULL, 'x'},
    {"ycoord", optional_argument, NULL, 'y'},
    {"zcoord", optional_argument, NULL, 'z'}};

  int longidx = 0;

  //accepts short and long options, 
  //the short ones and the long ones should require same optional arguments
  int opt = 0;
  while( (opt = getopt_long(argc, argv, "x:y::z::", longOpts, &longidx)) != -1 )
  {
     printf("%c\n", opt);
     switch(opt)
     {
       case 'x':
        param.x = 0x01;
        if( optarg ) param.val += atoi(optarg);
        break;
       case 'y':
        param.y = 1;
        if( optarg ) param.val += atoi(optarg);
        break;
       case 'z':
        param.z = 1;
        if( optarg ) param.val += atoi(optarg);
        break;
       default:
       case 0:
        printf("%s -x[0-9]+ -y -z\n", basename(argv[0]));
        //abort();
     }
  }

  printf("%X\n", param);
  return EXIT_SUCCESS;
}
