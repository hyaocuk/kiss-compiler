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
		fprintf(stderr, "Error: missing argument\n");
		exit(1);
	}

	else if(argc==2) {

		/**************************
		 * open a file from the 
		 * outside.
		 *************************/
		if(!(read_sourcecode_file_pointer=fopen(argv[1], "r"))) {
			fprintf(stderr, "Error openning file\n");
			exit(1);
		}
	

		read_config_file("conf/kiss-compiler.conf");
		/*while((c=fgetc(read_sourcecode_file_pointer))!=EOF) {
			printf("%c", c);
		}*/

		if(fclose(read_sourcecode_file_pointer)) {
			fprintf(stderr, "Error closing file\n");
			exit(1);
		}
	}

	else {
		fprintf(stderr, "Error: too many arguments!\n");
		exit(1);
	}

	return 0;
}
