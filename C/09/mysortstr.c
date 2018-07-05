#include"mystring.h"

int mysortstr01(char array[][81], int n)
{
  int i,j;

  for (i=0;i<n;i++){
    for (j=0;j<n;j++){
      if (stringcompare(array[i],array[j])==-1)
      {
	  stringswap(array[i],array[j]);
      }
    }
  }
    
  return 0;
}
