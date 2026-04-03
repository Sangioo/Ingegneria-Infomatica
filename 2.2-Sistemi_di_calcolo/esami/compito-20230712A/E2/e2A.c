#include "e2A.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int countVowels(const char* s) {
    int count = 0;
    while (*s) {
        if (*s == 'a' || *s == 'e' || *s == 'i' || *s == 'o' || *s == 'u' ||
            *s == 'A' || *s == 'E' || *s == 'I' || *s == 'O' || *s == 'U')
            count++;
        s++;
    }
    return count;
}

int vowelcount(const char** s, int n) {
    if (s == NULL || n == 0) return -1;

    int sum = 0;
    for (int i = 0; i < n; i++) {
        int pid = fork();
        if (pid == 0) {
            int res = countVowels(s[i]);
            exit(res);
        } else {
            int status;
            wait(&status);

            if (WIFEXITED(status)) {
                sum += WEXITSTATUS(status);
            }
        }
    }

    return sum;
}