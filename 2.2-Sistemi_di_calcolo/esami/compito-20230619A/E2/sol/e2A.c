#include "../e2A.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int examStats(const char* fname, int * min, int * max, float * avg) {
	int num = 0, sum = 0;
	char buf[256];
	FILE * f = fopen(fname, "r");
	if (f==NULL) goto CLEANUP;

	*min=31, *max=17;
	char * c = fgets(buf, 256, f);
	while (c!=NULL) {
		char * str = strtok(c, "-");
		str = strtok(NULL, "-");
		str = strtok(NULL, "-");
		int voto = atoi(str);
		if (voto>17) {
			num++;
			sum = sum + voto;
			if (voto > *max) *max = voto;
			if (voto < *min) *min = voto;
		}
		c = fgets(buf, 256, f);
	}
	if (num>0)
		*avg = (1.0 * sum) / num;
	else {
		*max = 0;
		*min = 0;
		*avg = 0.0;
		if (ferror(f)) goto CLEANUP;
	}
	fclose(f);
	return num;
CLEANUP:
	return -1;
}
