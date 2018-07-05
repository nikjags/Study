#include <stdio.h>

int main()
{
  int i;
  float i1,i2,in,in1,in2;


  in2=0;
  in1=5.0/8.0;
  printf ("x01 =%10.3f\n",in2);
  printf ("x02 =%10.3f\n",in1); 

  //for

  for (i=3;i<=20; i++){
      in=in1/2.0+0.75*in2;
      printf("x%02d",i);
      printf(" =%10.3f\n",in);
      in2=in1;
      in1=in;

    }

   
  printf("\n"); 
  printf("\n");
  
  //do-while
  i=3; 
  in2=0;
  in1=5.0/8.0;
  printf ("x01 =%10.3f\n",in2);
  printf ("x02 =%10.3f\n",in1);
  do{
      in=in1/2.0+0.75*in2;
      printf("x%02d",i);
      printf(" =%10.3f\n",in);
      in2=in1;
      in1=in;
      i++;
  
 } while (i<=20);

   printf("\n"); 
   printf("\n");

   i=3; 
   in2=0;
   in1=5.0/8.0;
   printf ("x01 =%10.3f\n",in2);
   printf ("x02 =%10.3f\n",in1);
   //while
   while (i<=20){
      in=in1/2.0+0.75*in2;
      printf("x%02d",i);
      printf(" =%10.3f\n",in);
      in2=in1;
      in1=in;
      i++;
  }
  printf("\n");

}
