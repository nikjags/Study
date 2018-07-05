#include "stack.hpp"
#include <new>
#include <stdio.h>


void IntStackElement::SetElement (int _element){
  element = _element;
}

int IntStackElement::GetElement (){
  return element;
}

IntStackElement* IntStackElement::GetPrev(){
  return prev;

}

void IntStackElement::SetPrev(IntStackElement* _prev){
  prev = _prev;  
}

  




IntStack::IntStack (){
  top = 0;     
}

IntStack::~IntStack (){
  while(top){
    Pop();
  }

}


void IntStack::Push (int _element) throw (NoMemory){
  IntStackElement *ptr;
  try{
    ptr = new IntStackElement;
  }
  catch(std::bad_alloc){
    throw NoMemory();
  }
  ptr->SetElement(_element);
  ptr->SetPrev(top);
  top=ptr;
  return;
}



int IntStack::Pop() throw (Empty){
  int PopedEl;
  IntStackElement *ptr;
  
  if(!top){
    throw Empty();
  }
   
  PopedEl=top->GetElement();
  ptr = top->GetPrev()
  delete top;
  top=ptr;
  
  return PopedEl;

}


void IntStack::operator<<(int _element){
  Push(_element);
}

int  IntStack::operator>>(int& _element){
  return  _element=Pop();
}

int IntStack::operator==(IntStack& _stack ){
  IntStackElement *ptr1,*ptr2;
  ptr1=top;
  ptr2=_stack.top;
  while(ptr1!=0 || ptr2!=0){
    if( (ptr1->GetElement()!=ptr2->GetElement()) || (ptr1==0 && ptr2!=0) || (ptr1!=0 && ptr2==0)){
      return 0;
    }
    ptr1=ptr1->GetPrev();
    ptr2=ptr2->GetPrev();
  }
  return 1;
}


