class IntStackElement{
  int element;
  IntStackElement *prev;
public:
  IntStackElement(){};
  void SetElement(int _element);
  int GetElement ();
  IntStackElement* GetPrev();
  void SetPrev(IntStackElement* _prev);
  ~IntStackElement(){};
};

class IntStack{
  IntStackElement* top;
  int buffer;
public:
  IntStack();
  class NoMemory{};
  class Empty{};
  void Push(int _element) throw (NoMemory);
  int Pop() throw (Empty);
  void operator<<(int _element);
  int  operator>>(int& _element);
  int operator==(IntStack& _stack);
  IntStackElement* GetTop();
  ~IntStack();
};
