#include<stdio.h>
#include<stdlib.h>
#include"mystring.h"

int main(){

  char* *str=NULL;
  int i,j;
  i=-1;
  do{
    str=realloc(str,sizeof(char*)*((++i)+1));
    str[i]=mygetstring();
    if (str[i]== NULL)
      {
	printf("NOT ENOUGH MEMORY! \n");
	for (j=0;j<=i;j++)
	  {
	    free (str[j]);	    
	  }
	free(str);
	return 0;
      }
  }
  while((stringlength(str[i])) != 0);

  printf("SOURCE STRINGS:\n");
  for(j=0;j<i;j++){
    printf("%s\n",str[j]);
  }


  mysortstr02(str,i);

  printf("SORTED STRINGS:\n");
  for(j=0;j<i;j++){
    printf("%s\n",str[j]);
    fflush(stdout);
    free(str[j]);
  }
  
  return 0;
}
