#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/dir.h>
#include <sys/types.h>
#include <sys/errno.h>

#define FALSE 0
#define TRUE !FALSE

#ifndef BUF_SIZE
#define BUF_SIZE 1024
#endif


int main(int argc,char *argv[])
{
	int fd_in, fd_out, open_flags;
	mode_t file_rights;
	ssize_t num_read;
	char buffer[BUF_SIZE];

	if(argc != 3 )
		err_exit("Program requires 3 arguments. \n", argv[0]);

// Open Source and Destination files if Destination does not exist create it

	fd_in = open(argv[1], O_RDONLY);
	if(fd_in == -1)
		err_exit("Could not open source file %s", argv[1]);
	
	open_flags = O_CREAT | O_WRONLY | O_TRUNC;
	file_rights = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH | S_IWOTH;
	fd_out = open(argv[2], open_flags, file_rights);
	if(fd_out == -1)
		err_exit("Could not open destination file %s", argv[2]);
	
// Transfer data from Source to Destitation until finished or there is an error

	while((num_read = read(fd_in, buffer, BUF_SIZE)) > 0)
		if(write(fd_out, buffer, num_read) != num_read)
		{
			close(fd_in);
			close(fd_out);
			err_exit("Could not write entire buffer.");
		}
	if(num_read == -1)
		err_exit("read error");

	if(close(fd_in) == -1)
		err_exit("Error closing source file.");
	if(close(fd_out) == -1)
		err_exit("Error closing destiation file.");

	exit(EXIT_SUCCESS);
}
