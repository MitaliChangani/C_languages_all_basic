#include <stdio.h>

int main() {
  int x = 5;
  int y = 3;
  
  // Returns 0 (false) because 5 is neither less than or equal to 3
  printf("%d", x <= y);
  return 0;
}