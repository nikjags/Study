#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

  struct stack_element{
    int element;
    struct stack_element *prev;
  };
  struct _stack{
    struct stack_element *top;
    int buffer;
  };
  typedef struct _stack *stack;




//Создание стека
stack create_stack(){

  stack st;

  st = malloc(sizeof(struct _stack));
  if (!st)
    {
      return NULL;
    }
  st->top = NULL;
  
  return st;
}    


//Вталкивание элемента в стек
int push(stack _stack, int _element){
  struct stack_element* buf;

  if (!_element){
    return -1;
  }
  if(!_stack){
    return -1;
  }
  
  buf=malloc(sizeof(struct stack_element));
  if(!buf){
    return -1;
  }
  
  buf->prev = _stack->top;
  buf->element = _element;
  _stack->top = buf;

  return 0;
  }

//Выталкивание элемента из стека
int pop(stack _stack){
  struct stack_element* buf;

  if ((!_stack) || (!_stack->top)){
    return 0;
  }
  buf= _stack->top;
  _stack->buffer = buf->element;
  _stack->top = buf->prev;
  free(buf);
  return _stack->buffer;
} 

//Удаление стека
void delete_stack(stack _stack){
  
  struct stack_element* buf;

  if(!_stack){
    return;
  }
  buf = _stack->top;
  while (buf)
    {
      _stack->top=_stack->top->prev;
      free(buf);
      buf=_stack->top;
    }
  free(_stack);
  return;
};

