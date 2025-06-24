void factorial(int n, int* result) {
    *result=n;
    while(--n){
        *result *= n;
    }
    return;
}
