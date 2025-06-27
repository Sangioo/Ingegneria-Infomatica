#include <stdio.h>
#include <string.h>

void print_concat(const char* s[], int n){
    char buf[512];
    char* edi = buf;
    const char** esi = s;
    int ebx = n;
    int ebp = 0;

    *edi=0;
L:  if (ebp>=ebx) goto E;
    strcat(edi, esi[ebp]);
    ebp++;
    goto L;
E:  puts(edi);
}
