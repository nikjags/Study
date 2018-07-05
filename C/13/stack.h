  struct stack_element{
    void *element;
    struct stack_element *prev;
  };
  struct _stack{
    int element_size;
    struct stack_element *top;
    void *buffer;
  };
  typedef struct _stack *stack;


stack create_stack(int _element_size);
int push(stack _stack, void *_element);
void * pop(stack _stack);
void delete_stack(stack _stack);
void print_stack(stack _stack,
		 void (*print_head)(),
		 void (*print_body)(void *_element),
		 void (*print_foot)());



void Print_head();
void Print_body(void *_element);
void Print_foot();
