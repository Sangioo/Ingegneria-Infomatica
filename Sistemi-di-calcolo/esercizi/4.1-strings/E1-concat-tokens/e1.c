#include <stdlib.h>
#include <string.h>

#define DELIM ", "

char* f(const char* s) {
	char s1[strlen(s) + 1];
	strncpy(s1, s, strlen(s));
	s1[strlen(s)] = '\0';

	char tmp[strlen(s) + 1];
	tmp[0] = '\0';

	char* token = strtok(s1, DELIM);
	while (token) {
		strcat(tmp, token);
		token = strtok(NULL, DELIM);
	}

	char* out = (char *) malloc(strlen(tmp) + 1);
	strncpy(out, tmp, strlen(tmp));
	out[strlen(out)] = '\0';
	return out;
}
