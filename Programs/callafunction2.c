#include <stdio.h>

// Create a function (myFunction)
void myFunction() {
  printf("Some text in myFunction\n");
  myOtherFunction(); // call myOtherFunction
}

// Create another function (myOtherFunction)
void myOtherFunction() {
  printf("Hey! Some text in myOtherFunction\n");
}

int main() {
  myFunction(); // call myFunction
  return 0;
}