#include<stdio.h>
#include<stdlib.h>

/****************************************
 * define how to read lines or characters
 * from files outside.
 * **************************************/

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

void read_a_line(FILE *fp) {
	while((c=fgetc(fp))!=EOF) {
		printf("%c", c);
	}
}

