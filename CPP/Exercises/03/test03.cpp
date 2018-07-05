#include <stdio.h>
#include "stack.hpp"

/*  int Lets_Pop(IntStack Stack){
    int a;
    try{
     a=Stack.Pop();
    }
    catch(IntStack::Empty){
      printf("Stack is empty.\n");    
    }
    return a;
  }

  void Lets_Push(IntStack Stack, int j){
    try{
      Stack.Push(j);
    }
    catch(IntStack::NoMemory){
      printf("Not enough memory for push in stack.\n");
    }
    return;
  }
*/


int main(){
  int i,j;

  IntStack ExampleStack;

  j=0;
  for(i=1;i<=20;i++){
    try{
      ExampleStack.Push(i);
      printf("Element in top: %d\n",ExampleStack.Pop());
      ExampleStack.Push(i);
    }
    catch(IntStack::Empty){
      printf("Stack is empty.\n");
    }
    catch(IntStack::NoMemory){
      printf("Not enough memory for push in stack.\n");
    }
  }
  printf("\n\n");
  j=0;
  for(;;){
    try{
      j=ExampleStack.Pop();
    }
    catch(IntStack::Empty){
      printf("Stack is empty.\n");
      return 0;
    }
    printf("Poped element: %d\n",j);
  }
}
