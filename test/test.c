#include "syscall.h"
#include "stdio.h"
#include "stdlib.h"

int main(int argc, char** argv){
	char in[20];
	int filedesc = 0;
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
	//system call create
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
	printf("Done.\n\n");

	printf("Testing unlink before close...\n");
	returncode = unlink("a.txt");
	if (returncode == -1){
		printf("ERROR: did not unlink.");
		return -1;
	}
	printf("Now close the file. \n");
	if (close(filedesc) == -1){
		printf("ERROR: did not close properly.\n");
		return -1;
	}
	printf("Done.\n\n");

	printf("===       END        ===\n");
	return 0;
}
