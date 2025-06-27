#include <stdio.h>
#include <string.h>

// warning: this is just a toy function and should by no means be
// consider secure to buffer overflows, which may cause security breaches

void print_concat(const char* s[], int n){
    char buf[512];
    *buf=0;
    int i;
    for (i=0; i<n; ++i) strcat(buf, s[i]);
    puts(buf);
}
