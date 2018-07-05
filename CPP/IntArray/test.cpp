#include <iostream>
#include "intarray.hpp"

int main(int argc, char const *argv[])
{
  IntArray arrayA;
  IntArray arrayB(arrayA);
  IntArray arrayC(-2);
  IntArray arrayD(-2, 5, 0);

  int i;

  std::cout << "ARRAY A (Empty)" << std::endl << arrayA << std::endl << std::endl;
  std::cout << "ARRAY B (Empty)" << std::endl << arrayB << std::endl << std::endl;
  std::cout << "ARRAY C (Empty)" << std::endl << arrayC << std::endl << std::endl;
  std::cout << "ARRAY D (Five zeros from -2 to 2)" << std::endl << arrayD << std::endl << std::endl;

  try
  {
    std::cout << "ARRAY A (Fetch(0))" << std::endl << arrayA.Fetch(0) << std::endl << std::endl;
  }
  catch (IntArray::Empty)
  {
    std::cout << "ARRAY A (Fetch(0))" << std::endl << "EMPTY" << std::endl << std::endl;
  };

  for (i = 0; i < 4; i++)
  {
    if (i % 2)
    {
      arrayA.AddL(-i * 10);
      std::cout << "ARRAY A (ADDL(" << -i * 10 << "))" << std::endl << arrayA << std::endl  << std::endl;
    }
    else
    {
      arrayA.AddH(i * 10);
      std::cout << "ARRAY A (ADDH(" << i * 10 << "))" << std::endl << arrayA << std::endl  << std::endl;
    };
  };

  for (i = 0; i < 4; i++)
  {
    if (i % 2)
    {
      arrayC.AddL(-i * 10);
      std::cout << "ARRAY C (ADDL(" << -i * 10 << "))" << std::endl << arrayC << std::endl  << std::endl;
    }
    else
    {
      arrayC.AddH(i * 10);
      std::cout << "ARRAY C (ADDH(" << i * 10 << "))" << std::endl << arrayC << std::endl  << std::endl;
    };
  };

  for (i = 0; i < 4; i++)
  {
    if (i % 2)
    {
      std::cout << "ARRAY C (REML())" << std::endl << arrayC.RemL() << std::endl << arrayC << std::endl  << std::endl;
    }
    else
    {
      std::cout << "ARRAY C (REMH())" << std::endl << arrayC.RemH() << std::endl << arrayC << std::endl  << std::endl;
    };
  };

  try
  {
    std::cout << "ARRAY C (Fatch(0))" << std::endl << arrayC.Fetch(0) << std::endl << std::endl;
  }
  catch (IntArray::Empty)
  {
    std::cout << "ARRAY C (Catch(0))" << std::endl << "EMPTY" << std::endl << std::endl;
  };

  arrayD.Store(0, 1);
  std::cout << "ARRAY D (Stroe(0, 1))" << std::endl << arrayD << std::endl << std::endl;

  std::cout << "ARRAY D (Properties)" << std::endl
    << "LOW " << arrayD.Low() << std::endl
    << "HIGH " << arrayD.High() << std::endl
    << "SIZE " << arrayD.Size() << std::endl << std::endl;

  std::cout << "ARRAY B (Properties)" << std::endl
    << "LOW " << arrayB.Low() << std::endl
    << "HIGH " << arrayB.High() << std::endl
    << "SIZE " << arrayB.Size() << std::endl << std::endl;

  arrayA + 10;
  std::cout << "ARRAY A (++10)" << std::endl << arrayA << std::endl << std::endl;

  arrayA + 15 + 20;
  std::cout << "ARRAY A (++15++20)" << std::endl << arrayA << std::endl << std::endl;

  -10 + arrayA;
  std::cout << "ARRAY A (-10++)" << std::endl << arrayA << std::endl << std::endl;

  -20 + (-15 + arrayA);
  std::cout << "ARRAY A (-20++-15++)" << std::endl << arrayA << std::endl << std::endl;

  std::cout << "ARRAY A (*--)" << std::endl << arrayA-- << std::endl << arrayA << std::endl << std::endl;

  std::cout << "ARRAY A (--*)" << std::endl << --arrayA << std::endl << arrayA << std::endl << std::endl;

  std::cout << "ARRAY A ([])" << std::endl << (arrayA[-1] = 3) << std::endl << arrayA[-1] << std::endl << arrayA << std::endl << std::endl;

  try
  {
    std::cout << "ARRAY A ([100])" << std::endl << arrayA[100] << std::endl << std::endl;
  }
  catch (IntArray::OutOfBounds _e)
  {
    std::cout << "ARRAY A ([100])" << std::endl << "Out of bounds min " << _e.lowIndex << ", max " << _e.highIndex << ", try " << _e.index << ", size " << _e.size << std::endl << std::endl;
  };
};
