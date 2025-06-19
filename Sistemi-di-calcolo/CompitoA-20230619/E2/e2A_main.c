#include "e2A.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int score, trials;

static void test(const char* file, const int expected_min, const int expected_max, const float expected_avg, const int expected_num) {
    trials++;
    int min=0, max=0, num=0;
    float avg=0.0;
    num = examStats(file, &min, &max, &avg);
    printf("Test %d: \"", trials);
    printf("%d|%d|%d|%.2f", num, min, max, floorf(avg * 100) / 100);
    printf("\" [corretto: %d|%d|%d|%.2f]\n", expected_num, expected_min, expected_max, expected_avg);
    int ok = num==expected_num
             &&
             min==expected_min
             &&
             max==expected_max
             &&
             floorf(avg * 100) / 100==expected_avg;
    score += ok;
}

int main() {
    test("appello1.txt", 18, 29, 22.90, 11);
    test("appello2.txt", 19, 30, 24.09, 11);
    test("appello3.txt", 0, 0, 0.0, 0);
    test("appello4.txt", 20, 20, 20.0, 8);
    test("appello5.txt", 0, 0, 0.0, 0);
    test("appello20.txt", 0, 0, 0.0, -1);

    printf("Report: %d/%d\n", score, trials);

    return EXIT_SUCCESS;
}
