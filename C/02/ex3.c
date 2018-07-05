#include <stdio.h>

int main()
{
  float cel,far;
  int i;
  for (i=0;i<=15; i++){
      cel=i*10;
      far= (5.0/9.0)*(cel-32.0);
      printf("%11.2f", cel);
      printf("%12.2f",far);
      printf("\n");
    }    


}


