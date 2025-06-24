#include <stdio.h>

int is_vowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int num_vowels(char *s);

int main() {
    int res = num_vowels("this is a test string for you and me");
    printf("%u\n", res); // deve stampare 10
    return 0;
}
