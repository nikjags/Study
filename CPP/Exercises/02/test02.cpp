#include <stdio.h>
#include "stack.hpp"

int main(){
  int i,j;

  IntStack ExampleStack;

  for(i=1;i<=20;i++){
    ExampleStack.Push(i);
    printf("Element on top: %d\n",ExampleStack.Pop());
    ExampleStack.Push(i);
  }
  printf("\n\n");
  j=1;
  while(j=ExampleStack.Pop){
    if (!j){
      return 0;
    }
    printf("Poped element = %d\n",j);
  }

}
