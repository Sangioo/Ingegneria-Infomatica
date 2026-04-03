#include <stdio.h>
#include <string.h>
#include "e1A.h"

static int tests = 0;

short update (unsigned char turn, pokemon* attacker, short pf) {
    short res = pf;
    if (turn % attacker->countdown == 0){
        res -= attacker->main_damage;
    }else{
        res -= attacker->fast_damage;
    }
    return res;
}

char winner (short pf1, short pf2){
        if (pf1<=0 && pf2<=0)
            return 0;
        if (pf1<=0)
            return 2;
        if (pf2<=0)
            return 1;
        return -1;
}

int test(pokemon* p1, pokemon*p2, unsigned char expected) {
    tests += 1;
    unsigned char res;
    res = fight(p1,p2);
    int out = 0;
    if (res==expected)
        out = 1;
	printf("Test %d: \"%d\" [atteso: \"%d\"] => %s\n", tests, res, expected, out ? "OK" : "errore");
    return out;
}

int main() {
    pokemon eevee;
    pokemon pikachu;
    pokemon slaking;
    pokemon charizard;
    pokemon caterpie;

    eevee.pf = 270;
    eevee.fast_damage = 30;
    eevee.main_damage = 50;
    eevee.countdown = 3;
    
    pikachu.pf = 350;
    pikachu.fast_damage = 25;
    pikachu.main_damage = 40;
    pikachu.countdown = 2;

    charizard.pf = 400;
    charizard.fast_damage = 35;
    charizard.main_damage = 100;
    charizard.countdown = 4;

    slaking.pf = 500;
    slaking.fast_damage = 0;
    slaking.main_damage = 250;
    slaking.countdown = 6;

    caterpie.pf = 1;
    caterpie.fast_damage = 2;
    caterpie.main_damage = 4;
    caterpie.countdown = 2;

    int score = 0;
    score += test(&eevee, &pikachu, 2);
    score += test(&charizard, &pikachu, 1);
    score += test(&charizard, &slaking, 0);
    score += test(&charizard, &caterpie, 1); //vittoria al primo turno
    score += test(&caterpie, &caterpie, 0); //pareggio al primo turno
    
    
    printf("Punteggio: %d/%d\n", score, tests);
    return score;
}