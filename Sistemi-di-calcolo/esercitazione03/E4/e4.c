char *my_strcpy(char *dest, const char *src) {
    int i = 0;
    while (dest[i] != '\0' || src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    return dest;
}
