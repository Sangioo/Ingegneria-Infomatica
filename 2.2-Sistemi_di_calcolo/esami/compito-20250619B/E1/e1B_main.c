#include <stdio.h>
#include <string.h>
#include "e1B.h"

static int tests = 0;

int abs_diff(int a, int b) {
    return a > b ? a - b : b - a;
}

unsigned char is_valid_move(mossa* m) {
    int r1 = m->coord_in[0];
    int c1 = m->coord_in[1];
    int r2 = m->coord_fin[0];
    int c2 = m->coord_fin[1];

    int dr = abs_diff(r1, r2);
    int dc = abs_diff(c1, c2);

    if (r1 < 1 || r1 > 8 || r2 < 1 || r2 > 8 || c1 < 1 || c1 > 8 || c2 < 1 || c2 > 8) {
        return 0;  // coordinate fuori dalla scacchiera
    }

    if (strcmp(m->name, "re") == 0) {
        return (dr <= 1 && dc <= 1 && (dr != 0 || dc != 0));
    } else if (strcmp(m->name, "regina") == 0) {
        return (dr == dc || dr == 0 || dc == 0);
    } else if (strcmp(m->name, "torre") == 0) {
        return (dr == 0 || dc == 0);
    } else if (strcmp(m->name, "alfiere") == 0) {
        return (dr == dc);
    } else if (strcmp(m->name, "cavallo") == 0) {
        return (dr == 2 && dc == 1) || (dr == 1 && dc == 2);
    } else if (strcmp(m->name, "pedone") == 0) {
        return (r2 == r1 + 1) && (c1 == c2);
    }

    return 0; // pezzo non riconosciuto
}

// Funzione per creare una nuova mossa
mossa* nuova_mossa(const char* name, int r1, int c1, int r2, int c2, mossa* head) {
    mossa* m = malloc(sizeof(mossa));
    strncpy(m->name, name, 8);
    m->name[7] = '\0';
    m->coord_in[0] = r1;
    m->coord_in[1] = c1;
    m->coord_fin[0] = r2;
    m->coord_fin[1] = c2;
    m->next = head;
    return m;
}

int test(mossa* head, unsigned char expected) {
    tests += 1;
    unsigned char res;
    res = check(head);
    int out = 0;
    if (res == expected)
        out = 1;
	printf("Test %d: \"%d\" [atteso: \"%d\"] => %s\n", tests, res, expected, out ? "OK" : "errore");
    return out;
}

void libera_lista(mossa* head) {
    while (head) {
        mossa* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int score = 0;

    // NOTE: funziona solo con stringhe senza simboli
    mossa* head1 = NULL;
    head1 = nuova_mossa("cavallo\0", 2, 1, 4, 2, head1);
    head1 = nuova_mossa("pedone\0", 2, 2, 3, 2, head1);
    head1 = nuova_mossa("pedone\0", 2, 2, 4, 2, head1);  // mossa non valida
    head1 = nuova_mossa("re\0", 5, 5, 7, 7, head1); // mossa non valida
    head1 = nuova_mossa("re\0", 4, 4, 5, 5, head1);
    head1 = nuova_mossa("regina\0", 1, 1, 8, 8, head1);

    mossa* head2 = NULL;

    mossa* head3 = NULL;
    head3 = nuova_mossa("cavallo\0", 2, 1, 4, 2, head3);
    head3 = nuova_mossa("pedone\0", 2, 2, 3, 2, head3);
    head3 = nuova_mossa("re\0", 4, 4, 5, 5, head3);
    head3 = nuova_mossa("regina\0", 1, 1, 8, 8, head3);

    mossa* head4 = NULL;
    head4 = nuova_mossa("pedone\0", 2, 2, 4, 2, head4);  // mossa non valida
    head4 = nuova_mossa("cavallo\0", 2, 1, 4, 2, head4);
    head4 = nuova_mossa("pedone\0", 2, 2, 3, 2, head4);
    head4 = nuova_mossa("re\0", 5, 5, 7, 7, head4); // mossa non valida
    head4 = nuova_mossa("re\0", 4, 4, 5, 5, head4);
    head4 = nuova_mossa("regina\0", 1, 1, 8, 8, head4);

    mossa* head5 = NULL;
    head5 = nuova_mossa("pedone\0", 2, 2, 4, 2, head5);  // mossa non valida

    mossa* head6 = NULL;
    head6 = nuova_mossa("regina\0", 1, 1, 8, 8, head6);

    score += test(head1, 0);
    score += test(head2, 1);
    score += test(head3, 1);
    score += test(head4, 0);
    score += test(head5, 0);
    score += test(head6, 1);
    
    printf("Punteggio: %d/%d\n", score, tests);
 
    libera_lista(head1);
    libera_lista(head2);
    libera_lista(head3);
    libera_lista(head4);
    libera_lista(head5);
    libera_lista(head6);

    return score;
}