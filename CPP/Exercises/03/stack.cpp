#include "stack.hpp"
#include <new>


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
  ptr = top->GetPrev();
  delete top;
  top=ptr;
  
  return PopedEl;

}
