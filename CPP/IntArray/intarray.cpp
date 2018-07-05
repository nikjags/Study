#include "intarray.hpp"

//Element of array
//Add element to left
IntArray::Element::Element(int _element, IntArray::Element *_high)
{
  //Define properties
  low = 0;
  element = _element;
  high = _high;

  //Set pointer for high element to this element
  if (_high)
    _high->low = this;
};

//Add element to right
IntArray::Element::Element(IntArray::Element *_low, int _element)
{
  //Define properties
  low = _low;
  element = _element;
  high = 0;

  //Set pointer for low element to this element
  if (_low)
    _low->high = this;
};

//Return pointer to prev element
IntArray::Element *IntArray::Element::Low()
{
  return low;
};

//Return pointer to next element
IntArray::Element *IntArray::Element::High()
{
  return high;
};

//Return value fo current element
int IntArray::Element::getElement()
{
  return element;
};

//Destroy element and reset pointers to prev/next elements in neighboring elements
IntArray::Element::~Element()
{
  if (low)
    low->high = high;

  if (high)
    high->low = low;
};

//Array
//Empty array
IntArray::IntArray()
{
  low = 0;
  high = 0;
  size = 0;
  lowIndex = 1;
  highIndex = 0;
};

//Empty array with specific first index
IntArray::IntArray(int _lowIndex)
{
  low = 0;
  high = 0;
  size = 0;
  lowIndex = _lowIndex;
  highIndex = _lowIndex - 1;
};

//Copy constructor
IntArray::IntArray(IntArray &_array)
{
  //Element for copy
  IntArray::Element *element;

  //Default properties
  low = 0;
  high = 0;
  size = 0;

  //Cope properties
  lowIndex = _array.lowIndex;
  highIndex = _array.lowIndex - 1;

  //First element
  element = _array.low;

  //Copying
  while (element)
  {
    AddH(element->element);
    element = element->high;
  };
};

//Specific array
IntArray::IntArray(int _lowIndex, int _count, int _element)
{
  int i;

  //Default properties
  low = 0;
  high = 0;
  size = 0;

  //Define indexes
  lowIndex = _lowIndex;
  highIndex = _lowIndex - 1;

  //Add elements
  for (i = 0; i < _count; i++)
    AddH(_element);
};

//Return index of first element in array
int IntArray::Low()
{
  return lowIndex;
};

//Return index of last element in array
int IntArray::High()
{
  return highIndex;
};

//Return size of array (Numbers of elements)
int IntArray::Size()
{
  return size;
};

//Return value of element with specific index in array
int IntArray::Fetch(int _index)
{
  IntArray::Element *element;
  int i;

  if (_index > ((lowIndex + highIndex) >> 1))
  {
    //First element
    element = low;

    //Find element with specific index
    for (i = lowIndex; i < _index; i++)
      element = element->high;
  }
  else
  {
    //First element
    element = high;

    //Find element with specific index
    for (i = highIndex; i > _index; i--)
      element = element->low;
  };

  return element->element;
};

//Set value of element with specific index in array
void IntArray::Store(int _index, int _element)
{
  IntArray::Element *element;
  int i;

  if (_index > ((lowIndex + highIndex) >> 1))
  {
    //First element
    element = low;

    //Find element with specific index
    for (i = lowIndex; i < _index; i++)
      element = element->high;
  }
  else
  {
    //First element
    element = high;

    //Find element with specific index
    for (i = highIndex; i > _index; i--)
      element = element->low;
  };

  //Set new value of element
  element->element = _element;

  return;
};

//Add element to left side of array
void IntArray::AddL(int _element)
{
  //Create new element
  low = new IntArray::Element(_element, low);

  //Change index of left element in array
  if (size)
    lowIndex--;
  else
  {
    highIndex = lowIndex;
    high = low;
  };

  //Change size of array
  size++;
};

//Add element to right side of array
void IntArray::AddH(int _element)
{
  //Create new element
  high = new IntArray::Element(high, _element);

  //Change index of left element in array
  if (size)
    highIndex++;
  else
  {
    highIndex = lowIndex;
    low = high;
  };

  //Change size of array
  size++;
};

//Remove element from left side of array
int IntArray::RemL()
{
  IntArray::Element *elementHigh;
  int element;

  //Remove element
  elementHigh = low->high;
  element = low->element;
  delete low;
  low = elementHigh;

  //Change size and indexes
  size--;

  if (size)
    lowIndex++;
  else
  {
    highIndex = lowIndex - 1;
    high = 0
  };

  return element;
};

//Remove element from right side of array
int IntArray::RemH()
{
  IntArray::Element *elementLow;
  int element;

  //Remove element
  elementLow = high->low;
  element = high->element;
  delete high;
  high = elementLow;

  //Change size and indexes
  size--;

  if (size)
    highIndex--;
  else
  {
    highIndex = lowIndex - 1;
    low = 0;
  };

  return element;
};

//Fetch + Store
int &IntArray::operator[](int _index)
{
  IntArray::Element *element;
  int i;

  if (_index > ((lowIndex + highIndex) >> 1))
  {
    //First element
    element = low;

    //Find element with specific index
    for (i = lowIndex; i < _index; i++)
      element = element->high;
  }
  else
  {
    //First element
    element = high;

    //Find element with specific index
    for (i = highIndex; i > _index; i--)
      element = element->low;
  };

  return element->element;
};
//RemL
int IntArray::operator--()
{
  return RemL();
};

//RemH
int IntArray::operator--(int)
{
  return RemH();
};

//Free memory from array
IntArray::~IntArray()
{
  while (high)
    RemH();
};

//AddL
IntArray &operator+(int _element, IntArray &_array)
{
  _array.AddL(_element);

  return _array;
};

//AddH
IntArray &operator+(IntArray &_array, int _element)
{
  _array.AddH(_element);

  return _array;
};

//Print array
std::ostream &operator<<(std::ostream &_ostream, const IntArray &_array)
{
  IntArray::Element *element;
  int elementIndex;

  _ostream << "ARRAY START" << std::endl;

  element = _array.low;
  elementIndex = _array.lowIndex;

  if (_array.size)
  {
    //Show elements
    while (element)
    {
      _ostream << '[' << elementIndex << "] = " << *element << std::endl;
      element = element->high;
      elementIndex++;
    };
  }
  else
    _ostream << "EMPTY" << std::endl;

  _ostream << "ARRAY END";
};

//Print element of array
std::ostream &operator<<(std::ostream &_ostream, const IntArray::Element &_element)
{
  _ostream << _element.element;
};
