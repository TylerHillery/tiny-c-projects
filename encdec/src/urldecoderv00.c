#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int hex_value(char c) {
    if ('0' <= c && c <= '9') return c - '0';
    c = (char)tolower((unsigned char)c);
    if ('a' <= c && c <= 'f') return c - 'a' + 10;
    return -1;
}

int main() {
    char c, a, b;
    while ( (c = getchar()) != EOF) {
        if (c == '%') {
            a = getchar(); 
            b = getchar();
            printf("%c", (hex_value(a) << 4) + hex_value(b));
        } else {
            putchar(c);
        }
    }
}