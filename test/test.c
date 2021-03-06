#include "syscall.h"
#include "stdio.h"
#include "stdlib.h"

int main(int argc, char** argv){
	char in[20];
	int filedesc = 0;
	int readdesc = 0;
	int returncode = 0;

	printf("=== File System Test ===\n");
	printf("Testing console in/out...\n");
	readline(in, 20);
	printf("%s \n", in);
	printf("Done.\n\n");

	printf("Testing file create...\n");
	//system call create
	filedesc = creat("a.txt");
	printf("Created file %d\n", filedesc);
	if (filedesc == -1) {
		printf("ERROR: not created.\n");
		return -1;
	}
	printf("Done.\n\n");

	printf("Testing file close... \n");
	if (close(filedesc) == -1){
		printf("ERROR: did not close properly.\n");
		return -1;
	}
	printf("Done.\n\n");

	printf("Testing file open...\n");
	//system call open
	filedesc = open("a.txt");
	printf("Opened file %d\n", filedesc);
	if (filedesc == -1) {
		printf("ERROR: not opened.\n");
		return -1;
	}
	printf("Done.\n\n");

	printf("Testing file write...\n");
	returncode = write(filedesc, "TEST WRITE", 10);
	printf("Write returned with: %d\n", returncode);
	if (returncode == -1){
		printf("ERROR: did not write");
		return -1;
	}
	printf("Testing file write again...\n");
	returncode = write(filedesc + 4, "The boogieman came around", 25);
	printf("Write returned with: %d\n", returncode);
	printf("Done.\n\n");

	printf("Testing file read...\n");
	readdesc = open("b.txt");
	if (readdesc == -1) {
		printf("ERROR: not opened.\n");
		return -1;
	}
	read(readdesc, in, 10);
	printf("Read string: %s\n", in);
	printf("Testing read again...\n");
	read(readdesc, in, -10);
	printf("Read string: %s\n", in);
	printf("Done.\n");

	printf("Testing unlink before close...\n");
	printf("Unlinking...\n");
	returncode = unlink("a.txt");
	if (returncode == -1){
		printf("ERROR: did not unlink.\n");
		return -1;
	}
	printf("Closing...\n");
	if (close(filedesc) == -1){
		printf("ERROR: did not close properly.\n");
		return -1;
	}
	printf("Done.\n\n");
	
	printf("===       END        ===\n");
	return 0;
}
