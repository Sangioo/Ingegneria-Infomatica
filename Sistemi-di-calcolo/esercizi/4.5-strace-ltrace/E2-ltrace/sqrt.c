#include <math.h>
#include <stdio.h>

double f(double x){
    return sqrt(x);
}

int main() {
    double y = f(2.0);
    printf("%f\n", y);
    return 0;
}
