// convert decimal to binary

#include <stdio.h>


int main() {
  int n, dec=0;
  long int bin = 0;
  int rem, i = 1;
  printf("Enter a decimal number: ");
  scanf("%d", &n);
  dec=n;
  printf("\nReverse Order:");
  while (n!=0) {
    rem = n % 2;
    n /= 2;
    bin += rem * i;
    i *= 10;
    printf("%d",rem);
  //  printf("2|%d-%d \n __\n",n,rem);
  }
  printf("\n*******************************\n");
  printf("%d in decimal =  %ld in binary", dec, bin);
  printf("\n*******************************\n");
  return 0;
}
