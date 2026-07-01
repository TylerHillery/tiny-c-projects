#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strappend(char *dest, char *src) {
    size_t dest_len = strlen(dest);
    size_t src_len = strlen(src);

    dest[dest_len] = ' ';
    for (size_t i = 0; i < src_len; i++) {
        dest[dest_len + i + 1] = src[i]; 
    }
    dest[dest_len + src_len + 1] = '\0';
    return dest;
}

int main(void) {
    char s1[32] = "This is another";
    char s2[] = "fine mess!";
    char *s3;

    s3 = strappend(s1 ,s2);
    printf("%s\n", s3);
    return EXIT_SUCCESS;
}