#include <stdio.h>
#include "mystring.h"

int main(){
 int i;
 char string01[80],string02[80];

 
 printf("Enter string for stringlength:");
 gets(string01);

 printf("stringlength result:%d\n",stringlength(string01));

 printf("Enter string01 for stringcompare:");
 gets(string01);
 printf("Enter string02 for stringcompare:");
 gets(string02);

 printf("stringcompare result:%d\n",stringcompare(string01,string02));
 
 printf("Enter string01 for stringswap:");
 gets(string01);
 printf("Enter string02 for stringswap:");
 gets(string02);

 stringswap(string01,string02);

 printf("string01 after stringswap:%s\n",string01);
 printf("string02 after stringswap:%s\n",string02);

}
