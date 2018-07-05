#include "stack.hpp"


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
  do{
    Pop();
  } while(Pop());

}


void IntStack::Push (int _element){
  IntStackElement *ptr;
  if(!_element){
    return;
  };
  ptr = new IntStackElement;
  ptr->SetElement(_element);
  ptr->SetPrev(top);
  top=ptr;
  return;
}




int IntStack::Pop(){
  int PopedEl;
  IntStackElement *ptr;
  
  if(!top) {
    return 0;
  }
  
  PopedEl=top->GetElement();
  ptr = top->GetPrev();
  delete top;
  top=ptr;
  
  return PopedEl;

}
