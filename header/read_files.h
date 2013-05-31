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
char word[100];
char *word_pointer = word;
/* count letters in a word */
int letter_count;
/* count the reserved word */
int reserved_count;
/* sign bit of whether it's a reserved word area */
int reserved_sign;

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

void clear_word() {
	for(i=0; i<100; i++) {
		word[i] = '\0';
	}
	letter_count = 0;
}

void read_config_file(char *path_to_config) {
	FILE *config_file_pointer;

	if(!(config_file_pointer=fopen(path_to_config, "r"))) {
		fprintf(stderr, "Error openning configure file!\n");
		exit(1);
	}

	while((c=fgetc(config_file_pointer))!=EOF) {
		printf("%c", c);
		while(c!=' ' && c!='\n') {
			clear_word();
			word[letter_count] = c;
			letter_count += 1;
			c = fgetc(config_file_pointer);
		}
		word[letter_count] = '\0';
		if(strcmp("#reserved#", word)==0) {
			reserved_sign = 1;
		}
		else {
			reserved_sign = 0;
		}

		while(c==' ' || c=='\n') {
			c = fgetc(config_file_pointer);
		}
		ungetc(c, config_file_pointer);

		if(reserved_sign==1) {
			while(c!=' ' && c!='\n') {
				clear_word();
				word[letter_count] = c;
				letter_count += 1;
				c = fgetc(config_file_pointer);
			}
			word[letter_count] = '\0';
			if(strcmp("#non-reserved#", word)==0)

			while(c!=' ') {
				clear_word();
				word[letter_count] = c;
				letter_count += 1;
				c = fgetc(config_file_pointer);
			}
			word[letter_count] = '\0';
			strcpy(reserved_table_array[].reserved_name, word);

			while(c==' ' || c=='\n') {
				c = fgetc(config_file_pointer);
			}
			ungetc(c, config_file_pointer);

			while(c!=' ') {
				clear_word();
				word[letter_count] = c;
				letter_count += 1;
				c = fgetc(config_file_pointer);
			}
			word[letter_count] = '\0';
			strcpy(reserved_table_array[].id, word);

			while(c==' ' || c=='\n') {
				c = fgetc(config_file_pointer);
			}
			ungetc(c, config_file_pointer);

			while(c!=' ' && c!= '\n') {
				clear_word();
				word[letter_count] = c;
				letter_count += 1;
				c = fgetc(config_file_pointer);
			}
			word[letter_count] = '\0';
			strcpy(resreved_table_array[].value, word);
		}
	}

	if(fclose(config_file_pointer)) {
		fprintf(stderr, "Error closing configure file!\n");
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

