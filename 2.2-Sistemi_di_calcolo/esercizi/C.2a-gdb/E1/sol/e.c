void factorial(int n, int* result) {
    *result=1;
    while(n){
        *result *= n--;
    }
    return;
}
