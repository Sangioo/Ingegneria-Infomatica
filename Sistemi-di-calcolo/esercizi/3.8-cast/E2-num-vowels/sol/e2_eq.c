int is_vowel(char c); // restituisce 0/1

int num_vowels(char *s) {
    char *b = s;
    int di = 0;
L:  if (*b == 0) goto E;
    int a = *b; // integer promotion
    a = is_vowel(a); 
    di = di + a;
    b++;
    goto L;
E:  a = di;
    return a;
}
