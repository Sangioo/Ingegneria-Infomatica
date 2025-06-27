#include "e1.h"

void div_mod(int x, int y, int* q, int* r){
    *q = x / y;
    *r = x % y;
}
