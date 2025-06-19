#include "e2B.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int score, trials;

static void test(const char* file, const int day_min, const int day_max, const int expected_bal, const int expected_num) {
    trials++;
    int bal=0, num=0;
    num = getBalanceMovements(file, day_min, day_max, &bal);
    printf("Test %d: \"", trials);
    printf("%d|%d", num, bal);
    printf("\" [corretto: %d|%d\n", expected_num, expected_bal);
    int ok = num==expected_num
             &&
             bal==expected_bal;
    score += ok;
}

int main() {
    test("balance1.txt", 1, 31, 620, 12);
    test("balance1.txt", 16, 17, 56, 2);
    test("balance1.txt", 31, 31, 0, 0);
    test("balance2.txt", 1, 31, 620, 12);
    test("balance2.txt", 16, 17, 56, 2);
    test("balance100.txt", 16, 17, 0, -1);

    printf("Report: %d/%d\n", score, trials);

    return EXIT_SUCCESS;
}
