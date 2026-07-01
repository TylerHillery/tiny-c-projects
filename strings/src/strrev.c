#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strrev(char *s) {
    int len, i;
    char *reversed;

    len = 0;
    while (*s) {
        len++;
        s++;
    }

    printf("malloc size %zu\n", sizeof(char) * len);
    // NOTE: book has buffer overflow
    reversed = malloc(sizeof(char)*len);
    if (reversed == NULL) {
        fprintf(stderr, "unable to allocate memory\n");
        exit(EXIT_FAILURE);
    }

    s--;
    i = 0;
    while(len) {
        reversed[i] = *s;
        i++;
        len--;
        s--;
    }
    reversed[i] = '\0';
    return reversed;
}

int main() {
    char s[] = "hello";
    printf("%s strlen:%ld sizeof:%zu\n", s, strlen(s), sizeof(s));
    char *r = strrev(s);
    printf("%s strlen:%ld sizeof:%zu\n", r, strlen(r), sizeof(r));
}