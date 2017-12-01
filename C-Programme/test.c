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
	    
	                                                    EXIT_SUCCESS;
	                                                    }
