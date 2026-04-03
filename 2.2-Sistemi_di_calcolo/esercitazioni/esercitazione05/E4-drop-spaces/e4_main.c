#include <stdio.h>
#include <string.h>

void drop_spaces(char* text);

int score, trials;


void test(char* text, char* corretto) {
    trials++;
    drop_spaces(text);
    printf("Test %d: %s [corretto: %s]\n", trials, text, corretto);
    score += strcmp(text, corretto) == 0;
}

int main() {
    
    char s1[] = " Under a Blood Red Sky ";
    char s2[] = "Seventh Son of a Seventh Son ";
    char s3[] = "Twenty Something";
    char s4[] = "Beethoven Concerto fuer Violin  Op. 61";

    test(s1, "UnderaBloodRedSky");
    test(s2, "SeventhSonofaSeventhSon");
    test(s3, "TwentySomething");
    test(s4, "BeethovenConcertofuerViolinOp.61");

    printf("Risultato: %d/%d\n", score, trials);

    return 0;
}
