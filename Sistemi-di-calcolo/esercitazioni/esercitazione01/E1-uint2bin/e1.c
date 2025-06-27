// Inserire la soluzione qui...
void uint2bin(unsigned x, char bin[32]) {
    for (int i = 31; i >= 0; i--) {
        if (x & 1)
            bin[i] = '1';
        else
            bin[i] = '0';
        x >>= 1;
    }
}
