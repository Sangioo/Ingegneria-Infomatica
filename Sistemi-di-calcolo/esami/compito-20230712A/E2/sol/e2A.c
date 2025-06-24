#include "../e2A.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <ctype.h>

void check_error(int res, char* msg) {
    if (res != -1) return;
    perror(msg);
    exit(EXIT_FAILURE);
}

int vowelcount(const char** s, int n) {

    if (s == NULL || n == 0) {
        return -1;
    }

    int totalVowels = 0;

    for (int i = 0; i < n; i++) {
        pid_t pid = fork();
        check_error(pid,"Error in Fork");
        if (pid == 0) {
            // Processo figlio
            const char* str = s[i];
            int vowels = 0;
            int len = strlen(str);
            
            for (int j = 0; j < len; j++) {
                char ch = tolower(str[j]);
                if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                    vowels++;
                }
            }
            
            exit(vowels);
        }
    }

    for (int i = 0; i < n; i++) {
        int status;
	    while(wait(&status) > 0){
			if(WIFEXITED(status)){
				totalVowels += WEXITSTATUS(status);
			}
	    }
    }

    return totalVowels;
}
