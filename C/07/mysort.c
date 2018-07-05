#include <stdio.h>
//Сортировка вставками
int mysort(int array[], int N)
{
  int i, j;
  int loc, newEl;

  if (N<1)
    return 1;

  for (i = 1; i < N; i++)
  {
    //
    newEl = array[i];
    /*loc - номер правого крайнего отсортированного элемента
      (в начале считаем, что a[0] уже отсортирован */ 
    loc = i-1;
    //ищем место элемента newEl, считая наибольшим отсортированным a[loc]
    while (loc >= 0 && array[loc] > newEl)
    {
      //сдвигаем все элементы на 1 вправо
      array[loc+1] = array[loc];
      loc = loc - 1;
    }
    //вставляем newEl на его законное место.
    array[loc+1] = newEl;
  }   
  return 0;
}
