#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "e1.h"

int score, trials;

void setup_filds(){
    int fd[2];
    int res = pipe(fd);    // create pipe that will link stderr fd[1]) -> stdin (fd[0])
    if (res == -1) {
        perror("error in pipe");
        exit(EXIT_FAILURE);
    }
    res = close(0);    // close stdin
    if (res == -1) {
        perror("error in close(0)");
        exit(EXIT_FAILURE);
    }
    res = dup(fd[0]);   // now stdin reads from the pipe
    if (res == -1) {
        perror("error in dup(fd[0])");
        exit(EXIT_FAILURE);
    }
    res = close(2);    // close stderr
    if (res == -1) {
        perror("error in close(0)");
        exit(EXIT_FAILURE);
    }
    res = dup(fd[1]);   // now stderr writes to the pipe, while stdout remains untouched
    if (res == -1) {
        perror("error in dup(fd[1])");
        exit(EXIT_FAILURE);
    }
}

void free_args(char* argv[]) {
    while (*argv) free(*argv++);
}

void print_args(char* argv[]) {
    while (*argv) printf("[%s] ", *argv++);
    if (*argv==NULL) printf("[NULL]");
}

int same_args(char* argv1[], char* argv2[]) {
    while (*argv1 && *argv2) if (strcmp(*argv1++, *argv2++)) return 0;
    return *argv1==NULL && *argv2 == NULL;
}

void test(char* cmd_line, char* argv_ok[]) {
    trials++;
    char* argv[MAX_TOKENS];
    fprintf(stderr, "%s", cmd_line);
    get_cmd_line(argv);

    printf("Calcolato: ");
    print_args(argv);
    printf(" [Corretto: ");
    print_args(argv_ok);
    printf("]\n");

    score += same_args(argv, argv_ok);
    free_args(argv);
}


int main() {
    setup_filds();

    char* argv1[MAX_TOKENS] =  { "ls", "-l", NULL };
    test("ls -l\n", argv1);

    char* argv2[MAX_TOKENS] =  { "top", NULL };
    test("top\n", argv2);

    char* argv3[MAX_TOKENS] =  { NULL };
    test("\n", argv3);

    char* argv5[MAX_TOKENS] =  { "valgrind", "--tool=memcheck", "./e1", NULL  };
    test("valgrind --tool=memcheck ./e1\n", argv5);

    printf("Risultato: %d/%d\n", score, trials);
    return EXIT_SUCCESS;
}
