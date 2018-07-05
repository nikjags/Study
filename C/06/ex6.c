#include <stdio.h>

int main()
{

  int a16,a10,i;

  a16 = 0x01020304;
 
  for (i = 0; i < 4; i++)
  {
   printf("Byte %d: %02x\n", i, *((char*)&a16 + i));
  }
  printf("\n");


  a10=16909060;
  // a10=a16;
  // printf("%d\n",a10);
  for (i = 0; i < 4; i++)
  {
   printf("Byte %d: %02d\n", i, *((char*)&a10 + i));
  }
  return 0;
  //Результат не изменился.
}
