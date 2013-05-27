#include<stdio.h>
#include<stdlib.h>
#include"../header/read_files.h"

typedef struct binary_tuple {
	char *value;
	unsigned int id;
}binary_tuple_instance;

struct binary_tuple bin_tuples[1000];

int main(int argc, char *argv[]) {

	FILE *read_sourcecode_file_pointer;
	char c; 

	if(argc==1) {
		printf("Error: missing argument\n");
		exit(1);
	}

	else if(argc==2) {

		/**************************
		 * open a file from the 
		 * outside.
		 *************************/
		if(!(read_sourcecode_file_pointer=fopen(argv[1], "r"))) {
			printf("Error openning file\n");
			exit(1);
		}
	

		while((c=fgetc(read_sourcecode_file_pointer))!=EOF) {
			printf("%c", c);
		}

		if(fclose(read_sourcecode_file_pointer)) {
			printf("Error closing file\n");
			exit(1);
		}
	}

	else {
		printf("Error: too many arguments!\n");
	}

	return 0;
}
