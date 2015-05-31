#include "syscall.h"
#include "stdio.h"
#include "stdlib.h"

int main(int argc, char** argv){
	char in[10];
	readline(in, 10);
	printf("%s", in);
	return 0;
}
