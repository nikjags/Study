#include<stdio.h>
#include"mysortstr.h"

int main(){
  int i;
  char *arr[12];


  arr[0] ="SDds";
  arr[1] ="Adsasd";
  arr[2] ="12331312";
  arr[3] ="fasdeewa";
  arr[4] =" t43r3";
  arr[5] ="123sdgfsd";
  arr[6] ="111222233";
  arr[7] ="111122223";
  arr[8] ="dsfsd f";
  arr[9] ="sdfrwea";
  arr[10]="awerare";
  arr[11]="axerhae";



  mysortstr02(arr,12);

  printf("SORTED STRINGS:\n");
  for (i=0;i<12;i++){
    printf("string[%02d] = %s\n",i+1, arr[i]);
  }

  return 0;
}
  
