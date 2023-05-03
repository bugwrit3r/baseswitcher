#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convertToBinary(unsigned n)
{
    if (n > 1)
        convertToBinary(n >> 1);

    printf("%d", n & 1);
}
int main(int argc, char **argv) {

  int base = 0;
  char *tail = NULL;
  if( argc != 4) {
    printf("No / Not enough / Wrong arguments supplied!\n");
    printf("Usage:\n-i(nput) [d(ecimal), h(exadecimal), b(inary)] (number in that base)\n");
    return 1;
  } else if (strcmp(argv[1], "-i") && ( strcmp(argv[2], "d") || strcmp(argv[2], "h") || strcmp(argv[2], "b") )) {
    printf("No / Not enough / Wrong arguments supplied!\n");
    printf("Usage:\n-i(nput) [d(ecimal), h(exadecimal), b(inary)] (number in that base)\n");
    return 1;
  }

  if( !strcmp(argv[2], "d") ) {
   base = 10;
  }else if ( !strcmp(argv[2], "h") ) {
    base = 16;
  }else if ( !strcmp(argv[2], "b") ) {
    base = 2;
  }
  long test = strtol(argv[3], &tail, base);
  printf("Decimal: %ld\n", test);
  printf("Hexadecimal: %lX\n", test);
  printf("Binary: ");
  convertToBinary(test);
  printf("\n");
    return 0;
}
