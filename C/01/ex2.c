#include <stdio.h>
int main(){
  float cel,far;
  printf("Enter Farenheit: ");
  scanf("%f",&cel);
  far= (5.0/9.0)*(cel-32.0);
  printf("Celsii: ");
  printf("%4.1f\n",far);
}
