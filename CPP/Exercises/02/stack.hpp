class IntStackElement{
  int element;
  IntStackElement *prev;
public:
  IntStackElement(){};
  void SetElement (int _element);
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
  void Push(int _element);
  int Pop();
  ~IntStack();
};
