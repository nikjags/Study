  struct stack_element{
    int element;
    struct stack_element *prev;
  };
  struct _stack{
    struct stack_element *top;
    int buffer;
  };
  typedef struct _stack *stack;


stack create_stack();
int push(stack _stack, int _element);
int pop(stack _stack);
void delete_stack(stack _stack);
