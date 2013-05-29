#include<stdio.h>
#include<stdlib.h>

/****************************************
 * "read_files.h"
 * defines how to read lines or characters
 * from files outside.
 ****************************************/

struct identifier_table {
	char *value;
	unsigned int id;
}identifier_table_instance;

struct identifier_table identifier_table_array[50];

struct reserved_table {
	char *reserved_name;
	char *value;
	unsigned int id;
}reserved_table_instance;

struct reserved_table reserved_table_array[20];

char c;
char line_buffer[100];

int i;

void allocation() {
	for(i=0; i<50; i++) {
		identifier_table_array[i].value = (char *)malloc(100);
	}
	for(i=0; i<20; i++) {
		reserved_table_array[i].reserved_name = (char *)malloc(20);
		reserved_table_array[i].value = (char *)malloc(20);
	}
}

void read_config_file(char *path_to_config) {
	FILE *config_file_pointer;

	if(!(config_file_pointer=fopen(path_to_config, "r"))) {
		printf("Error openning configure file!\n");
		exit(1);
	}

	while((c=fgetc(config_file_pointer))!=EOF) {
		printf("%c", c);
	}

	if(fclose(config_file_pointer)) {
		printf("Error closing configure file!\n");
		exit(1);
	}
}

void free_space() {
	for(i=0; i<50; i++) {
		free(identifier_table_array[i].value);
	}
	for(i=0; i<20; i++) {
		free(reserved_table_array[i].reserved_name);
		free(reserved_table_array[i].value);
	}
}

