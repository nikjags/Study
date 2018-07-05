#include <stdio.h>
#include "stack.hpp"

int main(){
  int i,j,example_int;

  IntStack ExampleStack,ExampleStack2,ExampleStack3,ExampleStack4;

  j=0;
  for(i=1;i<=20;i++){
    try{
      ExampleStack<<i;
      printf("Element in top: %d\n",ExampleStack>>example_int);
      ExampleStack  << i;
      ExampleStack2 << i;
    }
    catch(IntStack::Empty){
      printf("Stack is empty.\n");
    }
    catch(IntStack::NoMemory){
      printf("Not enough memory for push in stack.\n");
    }
  }
  
  printf("Let's compare ExampleStack and ExampleStack2(they are equal):\n");
  if(ExampleStack == ExampleStack2){
    printf("Stacks are equal\n");
  }
  else{
    printf("Stack aren't equal\n");
  }
  
  ExampleStack << i;
  printf("Let's compare ExampleStack3 and ExampleStack4 (they aren't equal):\n");  
  ExampleStack3<<2;
  if(ExampleStack == ExampleStack2){
    printf("Stacks are equal\n");
  }
  else{
    printf("Stack aren't equal\n");
  } 
  
  return 0;
}
