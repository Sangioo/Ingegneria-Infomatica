#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "auxiliary.h"


void test1();
void test2();
void test3();
void test4();
void test5();

int main() {
	srand(time(NULL));
	
	test1();
	test2();
	test3();
	test4();
	test5();
}
