#include <stdio.h>

int main()
{
  float cel,far;
  int i;
  printf("+-----------+------------+\n");
  printf("|     F     |     C      |\n");
  printf("+-----------+------------+\n");
  for (i=0;i<=15; i++){
      cel=i*10;
      far= (5.0/9.0)*(cel-32.0);
      printf("|%11.2f", cel);
      printf("|%12.2f",far);
      printf("|\n");
    }    
  printf("+-----------+------------+\n");

  printf("\n"); 

  i=0; 
  printf("+-----------+------------+\n");
  printf("|     F     |     C      |\n");
  printf("+-----------+------------+\n");
  do{
      cel=i*10;
      far= (5.0/9.0)*(cel-32.0);
      printf("|%11.2f", cel);
      printf("|%12.2f",far);
      printf("|\n");
      i++;

  } while (i<=15);
  printf("+-----------+------------+\n");

  printf("\n");

  i=0; 
  printf("+-----------+------------+\n");
  printf("|     F     |     C      |\n");
  printf("+-----------+------------+\n");
  while (i<=15){
      cel=i*10;
      far= (5.0/9.0)*(cel-32.0);
      printf("|%11.2f", cel);
      printf("|%12.2f",far);
      printf("|\n");
      i++;
  }
  printf("+-----------+------------+\n");




}


