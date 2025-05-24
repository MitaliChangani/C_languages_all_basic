#include <stdio.h>

enum Level {
  LOW,     //0
  MEDIUM,  //1
  HIGH     //1
};
  
int main() {
  // Create an enum variable and assign a value to it
  enum Level myVar = MEDIUM;
 
  // Print the enum variable
  printf("%d", myVar);
  
  return 0;
}