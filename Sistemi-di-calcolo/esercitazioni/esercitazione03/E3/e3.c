int comp(const void* xv, const void* yv) {
    int* x = (int*)xv; // nota: in IA32 gli indirizzi non hanno tipo
    int* y = (int*)yv; // e sono semplicemente dei numeri senza segno
    return *x - *y;
}