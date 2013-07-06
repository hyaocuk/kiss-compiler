#include<stdio.h>
#include<stdlib.h>

/****************************************
 * "read_files.h"
 * defines how to read lines or characters
 * from files outside.
 ****************************************/

struct operator_table {
	char operator_name[5];
	char value[20];
	char id[5];
}operator_table_instance;

struct operator_table operator_table_array[50];

struct reserved_table {
	char reserved_name[10];
	char value[20];
	char id[5];
}reserved_table_instance;

struct reserved_table reserved_table_array[20];

struct separator_table {
	char separator_name[5];
	char value[20];
	char id[5];
}separator_table_instance;

struct separator_table separator_table_array[5];

/**************************************************************/
char c;
char token[15];
//char *word_pointer = word;
/* count letters in a word */
int letter_count;
/* count the reserved word */
int reserved_count = 0;
/* count the operator */
int operator_count = 0;
/* count the separator */
int separator_count = 0;

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
		while(strcmp("#operator#", reserved_table_array[reserved_count].reserved_name)!=0) {
			printf("reserved name: %s\n", reserved_table_array[reserved_count].reserved_name);
			while(c==' ') {
				c = fgetc(config_file_pointer);
			}
			fscanf(config_file_pointer, "%s", reserved_table_array[reserved_count].id);
			printf("reserved id: %s\n", reserved_table_array[reserved_count].id);
			while(c==' ') {
				c = fgetc(config_file_pointer);
			}
			fscanf(config_file_pointer, "%s", reserved_table_array[reserved_count].value);
			printf("reserved value: %s\n", reserved_table_array[reserved_count].value);
			while(c==' ') {
				c = fgetc(config_file_pointer);
			}
			reserved_count += 1;
			if(reserved_count>20) {
				fprintf(stderr, "Error in conf file, numbers of reserved words exceed!\n");
				exit(1);
			}
			fscanf(config_file_pointer, "%s", reserved_table_array[reserved_count].reserved_name);
		}

		fscanf(config_file_pointer, "%s", operator_table_array[operator_count].operator_name);
		while(strcmp("#operator#", reserved_table_array[reserved_count].reserved_name)==0 && strcmp("#separator#", operator_table_array[operator_count].operator_name)!=0) {
			printf("operator name: %s\n", operator_table_array[operator_count].operator_name);
			while(c==' ') {
				c = fgetc(config_file_pointer);
			}
			fscanf(config_file_pointer, "%s", operator_table_array[operator_count].id);
			printf("operator id: %s\n", operator_table_array[operator_count].id);
			while(c==' ') {
				c = fgetc(config_file_pointer);
			}
			fscanf(config_file_pointer, "%s", operator_table_array[operator_count].value);
			printf("operator value: %s\n", operator_table_array[operator_count].value);
			while(c==' ') {
				c = fgetc(config_file_pointer);
			}
			operator_count += 1;
			if(operator_count>50) {
				fprintf(stderr, "Error in conf file, numbers of operators exceed!\n");
				exit(1);
			}
			fscanf(config_file_pointer, "%s", operator_table_array[operator_count].operator_name);
		}

		fscanf(config_file_pointer, "%s", separator_table_array[separator_count].separator_name);
		while(strcmp("#separator#", operator_table_array[operator_count].operator_name)==0 && fgetc(config_file_pointer)!=EOF) {
			printf("separator name: %s\n", separator_table_array[separator_count].separator_name);
			while(c==' ') {
				c = fgetc(config_file_pointer);
			}
			fscanf(config_file_pointer, "%s", separator_table_array[separator_count].id);
			printf("separator id: %s\n", separator_table_array[separator_count].id);
			while(c==' ') {
				c = fgetc(config_file_pointer);
			}
			fscanf(config_file_pointer, "%s", separator_table_array[separator_count].value);
			printf("separator value: %s\n", separator_table_array[separator_count].value);
			while(c==' ') {
				c = fgetc(config_file_pointer);
			}
			separator_count += 1;
			if(separator_count>5) {
				fprintf(stderr, "Error in conf file, numbers of separators exceed!\n");
				exit(1);
			}
			fscanf(config_file_pointer, "%s", separator_table_array[separator_count].separator_name);
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

