#include <stdio.h>
#include <math.h>

int binary_to_decimal(int num){
  int decimal = 0, i = 0;
    while (num != 0)
    {
        int rem = num % 10;
        num /= 10;
        decimal += rem * pow(2, i);
        ++i;
    }
    return decimal;
}

int main(int argc, char **argv){
  int num = 1011; // 11
  int decimal = binary_to_decimal(num);
  printf("The decimal number is %d\n", decimal);
  return 0;
}
  
