#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int i[10000000], j = 10;
int main(int argc, char* argv[]) {
    static char *k = "hello";
    int *p = malloc(sizeof(int));
    free(p);
    printf("&i=%p|&j=%p|&main=%p|&argc=%p|",&i,&j,&main,&argc);
    printf("&k=%p|k=%p|&p=%p|p=%p\n",&k,k,&p,p);
    pause();
    return 0;
}