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



int mysortstr02(char* array[], int n){
  int i,j;
  char* chr;

  for (j=0;j<(n-1);j++){
    for (i=0;i<(n-1);i++){
      if (stringcompare(array[i],array[i+1])==1)
	{
	  	   chr=array[i];
	           array[i]=array[i+1];
	           array[i+1]=chr;

        }
    }
  }

  return 0;
}
