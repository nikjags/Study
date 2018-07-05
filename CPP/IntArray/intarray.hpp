#include <ostream>

//Array
class IntArray
{
public:
  friend std::ostream &operator<<(std::ostream &_ostream, const IntArray &_array);

public:
  //Element of array
  class Element
  {
  public:
    friend class IntArray;
    friend std::ostream &operator<<(std::ostream &_ostream, const IntArray::Element &_element);
    friend std::ostream &operator<<(std::ostream &_ostream, const IntArray &_array);

  private:
    //Pointers to prev and next element in array
    Element *low, *high;
    //Value of current element
    int element;

  public:
    //Add element to left
    Element(int _element, IntArray::Element *_high);
    //Add element to right
    Element(IntArray::Element *_low, int _element);

    //Return pointer to prev element
    IntArray::Element *Low();
    //Return pointer to next element
    IntArray::Element *High();
    //Return value fo current element
    int getElement();

    //Destroy element and reset pointers to prev/next elements in neighboring elements
    ~Element();
  };

private:
  //Pointers to first and last elements in array
  IntArray::Element *low, *high;
  //Size of array (Numbers of elements)
  int size;
  //Index of first and last elements in array
  int lowIndex, highIndex;

public:
  //Empty array
  IntArray();
  //Empty array with specific first index
  IntArray(int _lowIndex);
  //Copy constructor
  IntArray(IntArray &_array);
  //Specific array
  IntArray(int _lowIndex, int _count, int _element);

  //Return index of first element in array
  int Low();
  //Return index of last element in array
  int High();
  //Return size of array (Numbers of elements)
  int Size();

  //Return value of element with specific index in array
  int Fetch(int _index);
  //Set value of element with specific index in array
  void Store(int _index, int _element);

  //Add element to left side of array
  void AddL(int _element);
  //Add element to right side of array
  void AddH(int _element);
  //Remove element from left side of array
  int RemL();
  //Remove element from right side of array
  int RemH();

  //Fetch + Store
  int &operator[](int _index);
  //RemL
  int operator--();
  //RemH
  int operator--(int);

  //Free memory from array
  ~IntArray();
};

//AddL
IntArray &operator+(int _element, IntArray &_array);
//AddH
IntArray &operator+(IntArray &_array, int _element);

//Print array
std::ostream &operator<<(std::ostream &_ostream, const IntArray &_array);
//Print element of array
std::ostream &operator<<(std::ostream &_ostream, const IntArray::Element &_element);
