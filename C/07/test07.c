#include <stdio.h>
#include "mysort.h"

int main()
{

  int i,N;
  int array[99];

  //Ввод N
  do
  { 
    printf("Intput N (min = 10, max =99)\n");
    printf("N = ");
    scanf("%d", &N);
    // Если  N<10 OR N>99, повторяем ввод N 
    if ((N < 10)||(N > 99))
    {
      printf("Incorrect value of N\n");
      printf("\n");
    }
  }  while ((N < 10)||(N > 99));

  //Заполнение массива
  printf("\n");
  for (i = 0; i < N; i++)
  {
    printf("array[%02d] = ", i+1);
    scanf("%d", &(array[i]));
  }

  //Сортировка методом вставки
  mysort(array, N);

  printf("\n");

  //Вывод массива
  printf("SORTED ARRAY:\n");
  for (i = 0; i < N; i++)
  {
    printf("srcarray[%02d] = %d\n", i + 1, array[i]);
  };


}
