#include "e2A.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int score, trials;

static char * getOutput(const char * filename) {
    char * buf = (char *) malloc (4096 * sizeof(char));
    FILE *fp;
    char cmd[19];
    sprintf(cmd, "tr '\n' ' ' < %s", filename);

    if ((fp = popen(cmd, "r")) == NULL) {
        printf("Error opening pipe!\n");
        return NULL;
    }
    if (fgets(buf, 4095, fp) == NULL) buf = "";

    if (pclose(fp)) {
        printf("Command not found or exited with error status\n");
        return NULL;
    }

    return buf;
}
student * newStudent(char * surname, char * name, int mark, student * next){
    student * out = (student *) malloc(sizeof(student));
    strncpy(out->surname, surname, 20);
    out->surname[19] = 0;
    strncpy(out->name, name, 20);
    out->surname[19] = 0;
    out->mark = mark;
    out->next = next;
    return out;
}
student * init(){
    student * G = newStudent("Neri", "Sara", 31, NULL);
    student * F = newStudent("Azzurra", "Giorgia", 30, G);
    student * E = newStudent("Viola", "Anna", 22, F);
    student * D = newStudent("Bianchi", "Alberto", 22, E);
    student * C = newStudent("Verdi", "Francesca", 18, D);
    student * B = newStudent("Marrone", "Gianni", 0, C);
    student * A = newStudent("Rossi", "Mario", 0, B);
    return A;
}

static void test(int num, const char * correct, const char * filename) {
    trials++;
    student * list = init();
    student * ret = 0;
    getStudents(filename, list, num);
    int ok = strcmp(correct, getOutput(filename)) == 0;
    printf("Test %d: %s\n", trials, ok ? "OK" : "errore");
    score += ok;
}

int main() {
    test(0, "Rossi Mario - 0 Marrone Gianni - 0 Verdi Francesca - 18 Bianchi Alberto - 22 Viola Anna - 22 Azzurra Giorgia - 30 Neri Sara - 31 ", "A.txt");
    test(18, "Verdi Francesca - 18 Bianchi Alberto - 22 Viola Anna - 22 Azzurra Giorgia - 30 Neri Sara - 31 ", "B.txt");
    test(21, "Bianchi Alberto - 22 Viola Anna - 22 Azzurra Giorgia - 30 Neri Sara - 31 ", "C.txt");
    test(25, "Azzurra Giorgia - 30 Neri Sara - 31 ", "D.txt");
    test(31, "Neri Sara - 31 ", "E.txt");
    test(99, "", "F.txt");

    printf("Risultato: %d/%d\n", score, trials);

    return EXIT_SUCCESS;
}
