int count_substrings(const char* s, const char* sub) {
    int len_s = 0, len_sub = 0, count = 0;
    char* s1 = (char*)s;
    while (*s1) {
        len_s++;
        s1++;
    }

    char* s2 = (char*)sub;
    while (*s2){
        len_sub++;
        s2++;
    }

    int flag = 0;
    for (int i=0; i<len_s-len_sub+1; i++) {
        flag = 1;
        for (int j=0; j<len_sub; j++) {
            if (s[j+i] != sub[j])
                flag = 0;
        }
        if (flag) count++;
    }
    return count;
}
