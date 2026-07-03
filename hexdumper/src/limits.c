#include <limits.h>
#include <locale.h>
#include <stdio.h>

int main() {
  setlocale(LC_NUMERIC, "");

  printf("Char:\n");
  printf("\tNumber of bytes: %zu\n", sizeof(char));
  printf("\tSigned Min     : %'d\n", SCHAR_MIN);
  printf("\tSigned Max     : %'d\n", SCHAR_MAX);
  printf("\tUnsigned Max   : %'u\n", (unsigned int)UCHAR_MAX);

  printf("Short:\n");
  printf("\tNumber of bytes: %zu\n", sizeof(short));
  printf("\tSigned Min     : %'d\n", SHRT_MIN);
  printf("\tSigned Max     : %'d\n", SHRT_MAX);
  printf("\tUnsigned Max   : %'u\n", (unsigned int)USHRT_MAX);

  printf("Int :\n");
  printf("\tNumber of bytes: %zu\n", sizeof(int));
  printf("\tSigned Min     : %'d\n", INT_MIN);
  printf("\tSigned Max     : %'d\n", INT_MAX);
  printf("\tUnsigned Max   : %'u\n", UINT_MAX);

  printf("Long:\n");
  printf("\tNumber of bytes: %zu\n", sizeof(long));
  printf("\tSigned Min     : %'ld\n", LONG_MIN);
  printf("\tSigned Max     : %'ld\n", LONG_MAX);
  printf("\tUnsigned Max   : %'lu\n", ULONG_MAX);

  printf("Long Long:\n");
  printf("\tNumber of bytes: %zu\n", sizeof(long long));
  printf("\tSigned Min     : %'lld\n", LLONG_MIN);
  printf("\tSigned Max     : %'lld\n", LLONG_MAX);
  printf("\tUnsigned Max   : %'llu\n", ULLONG_MAX);
}