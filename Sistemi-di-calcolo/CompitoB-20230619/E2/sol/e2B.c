#include "../e2B.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int getBalanceMovements(const char* fname, int min, int max, int * bal) {
	int op=0, num=0;
	char buf[256];
	FILE * f = fopen(fname, "r");
	if (f==NULL) goto CLEANUP;

	char * c = fgets(buf, 256, f);
	while (c!=NULL) {
		char * str = strtok(c, "|");
		if (atoi(str)>=min && atoi(str)<=max) {
			num++;
			str = strtok(NULL, "|");
			char sign = str[0];
			str = strtok(NULL, "|");
			op = atoi(str);
			if (sign=='-') op = op * -1;
			*bal = *bal + op;
		}
		c = fgets(buf, 256, f);
	}
	if (ferror(f)) goto CLEANUP;
	fclose(f);
	return num;
CLEANUP:
	return -1;
}