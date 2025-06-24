void remove_space(char* text);

void drop_spaces(char* text) {
    while (*text) {
        if (*text == ' ') {
            remove_space(text);
        } else {
            text++;
        }
    }
}

void remove_space(char* text) {
    while(*text) {
        *text = *(text+1);
        text++;
    }
}
