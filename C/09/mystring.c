#include <stdio.h>

int stringlength(char *string)
{
 int i;

 i=0;

 while (string[i] != '\0') {
    i++;
}
 return i;
} 


int stringcompare(char *string01, char *string02)
{
  int k;

  k=0;
  while ((string01[k] == string02[k]) && (string01[k] != '\0') && (string02[k] != '\0'))
    {
    k++;    
    }
    if (string01[k]==string02[k]){
      return 0;
    }
    if (string01[k]>string02[k]){ 
        return 1;
    }
    if (string01[k]<string02[k]){
	return -1;
    }
}
  
 
int stringswap(char *string01, char *string02)
{
  int i,in;
  char s;

  i=0;

  if (stringlength(string01)>stringlength(string02))
    in=stringlength(string01);  
  else
    in=stringlength(string02);
  
  for (i=0;i<=in;i++){
      s=string01[i];
      string01[i]=string02[i];
      string02[i]=s;
      }
  return 0;
}


