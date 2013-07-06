#include<stdio.h>
#include<stdlib.h>

/****************************************
 * "read_files.h"
 * defines how to read lines or characters
 * from files outside.
 ****************************************/

struct identifier_table {
	char *value;
	char *id;
}identifier_table_instance;

struct identifier_table identifier_table_array[50];

struct reserved_table {
	char reserved_name[10];
	char value[20];
	char id[5];
}reserved_table_instance;

struct reserved_table reserved_table_array[20];

/**************************************************************/
char c;
char token[15];
//char *word_pointer = word;
/* count letters in a word */
int letter_count;
/* count the reserved word */
int reserved_count = 0;


/***************************************************************/

void read_config_file(char *path_to_config) {
	FILE *config_file_pointer;

	//allocation();

	if(!(config_file_pointer=fopen(path_to_config, "r"))) {
		fprintf(stderr, "Error openning configure file!\n");
		exit(1);
	}

	fscanf(config_file_pointer, "%s", token);
	if(strcmp("#reserved#", token)==0) {
		c = fgetc(config_file_pointer);
		fscanf(config_file_pointer, "%s", reserved_table_array[reserved_count].reserved_name);
		while(strcmp("#non-reserved#", reserved_table_array[reserved_count].reserved_name)!=0) {
			printf("reserved_name: %s\n", reserved_table_array[reserved_count].reserved_name);
			while(c==' ') {
				c = fgetc(config_file_pointer);
			}
			fscanf(config_file_pointer, "%s", reserved_table_array[reserved_count].id);
			printf("id: %s\n", reserved_table_array[reserved_count].id);
			while(c==' ') {
				c = fgetc(config_file_pointer);
			}
			fscanf(config_file_pointer, "%s", reserved_table_array[reserved_count].value);
			printf("value: %s\n", reserved_table_array[reserved_count].value);
			while(c==' ') {
				c = fgetc(config_file_pointer);
			}
			reserved_count += 1;
			fscanf(config_file_pointer, "%s", reserved_table_array[reserved_count].reserved_name);
			
		}
	}
	else {
		fprintf(stderr, "Error in conf file, missing \"#reserved#\"\n");
		exit(1);
	}

	/**************************************************************************/

	if(fclose(config_file_pointer)) {
		fprintf(stderr, "Error closing configure file!\n");
		exit(1);
	}
}

