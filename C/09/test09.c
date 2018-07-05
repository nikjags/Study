#include <stdio.h>
#include "mystring.h"
#include "mysortstr.h"

int main()
{
  int i,n;
  char s[15][81];

  
  n=15;
  printf("Введите количество строк (не больше 15): ");

  scanf("%d",&n);
  
  if (n<=0)
    {
      printf("Некорректное значение N \n");
      printf("\n \n");
    }



  printf("ENTER ALL %d STRINGS:\n",n);
  for (i=0;i<n;i++)
    {
    printf("%d: ",i+1);
    scanf("%s",s+i);
    }

  mysortstr01(s,n);

  printf("\n");

  printf("SORTED STRINGS:\n");
  for (i=0;i<n;i++)
    {
    printf("string[%02d] = %s\n",i+1, s[i]);
    }



  return 0;

  }

