char *my_strcat(char *dest, const char *src) {
    int len_src = 0, len_dest = 0;

    while(src[len_src]) len_src++;
    while(dest[len_dest]) len_dest++;

    for (int i = 0; i < len_src; i++) {
        dest[i + len_dest] = src[i];
    }
    dest[len_src + len_dest] = '\0';

    return dest;
}
