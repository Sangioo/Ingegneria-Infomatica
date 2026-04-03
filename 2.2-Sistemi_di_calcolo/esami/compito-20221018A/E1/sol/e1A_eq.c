#include "../e1A.h"

char* str_to_upper(const char* s) {
    char* res = NULL;
    if (s == NULL) goto E;
    res = strdup(s); 
    char* copy = res;
L:
    if (*copy == 0) goto E;
    char c = toupper(*copy); 
    *copy = c;
    copy++;
    goto L;
E:
    return res;
}
