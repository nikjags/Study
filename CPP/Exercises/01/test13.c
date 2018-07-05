#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "stack.h"



int main(){

  stack st;
  int i;


  if(st=create_stack()){
    printf("Stack is created.\n\n");
  }
  else{
    printf("Stack isn't created.\n\n");
    return 0;
  }


  printf("Заполнение стека пятью элементами \n");  
  for(i=0;i<6;i++){   
    if(push(st,2*i)){
      printf("Cannot put new element in stack\n");
    }
    else{
      printf("element[%d]= %d\n",i,st->top->element);
    }
  }
        
  printf("\nУдаление верхнего элемента стека\n");
  pop(st);
  printf("Значение *buffer : %d\n", st->buffer);
    
  printf("Добавление удалённого элемента обратно в стек\n");
  if(push(st,st->buffer)){
    printf("Cannot put new element in stack\n");
  }
  else{
    printf("Элемент добавлен\n");
  }
    
  printf("Удаление стека.\n");
  delete_stack(st);
    

  return -9999;
}

