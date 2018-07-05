#include<stdio.h>
#include<stdlib.h>

int stringlength(char *string){
  int i;
  i=0;
  while (*(string+i)!='\0'){
    i++;}
  return i;}

int stringcompare(char *string01, char *string02){
  int i;
  i=0;

  while(*(string01+i)==*(string02+i)&&*(string01+i)!='\0'&&*(string02+i)!='\0'){
    i++;}

  if (*(string01+i)=='\0'){
    if (*(string02+i)=='\0'){
      return 0;}
    else{return -1;}}
    else if (*(string01+i)<*(string02+i))
      {return -1;}
    else{return 1;}}

int stringswap(char *string01, char *string02){
  int i;
  char l;

  i=0;
  if (stringlength(string01)>stringlength(string02)){
    while(*(string01+i)!='\0'){
      l=*(string01+i);
      *(string01+i)=*(string02+i);
      *(string02+i)=l;
      i++;};
    *(string02 + i) = '\0';}
    else{
       while(*(string02+i)!='\0'){
	l=*(string01+i);
	*(string01+i)=*(string02+i);
	*(string02+i)=l;
	i++;};
       *(string01 + i) = '\0';}
    return 0;
}

int mysortstr01(char array[][81], int n){
  int i,j;

  for (j=0;j<(n-1);j++){
    for (i=0;i<(n-1);i++){
      if (stringcompare((char*)array+(i*81),(char*)array+((i+1)*81))==1){
	  stringswap((char*)array+(i*81),(char*)array+((i+1)*81));}
	}
    }
    
  return 0;}

int mysortstr02(char* array[], int n){
  int i,j;
  char* l;

  for (j=0;j<(n-1);j++){
    for (i=0;i<(n-1);i++){
      if (stringcompare(array[i],array[i+1])==1){
	l=array[i];
	array[i]=array[i+1];
	array[i+1]=l;}}}

  return 0;}



 char* mygetstring(){
   int n=0;
   char ch, *str=(char*)malloc(sizeof(char)),*str1;

   while((ch=getchar()) != '\n'){
     str[n]=ch;
     str1=str;
     str=realloc(str,((++n)+1)*sizeof(char));
     if(str==NULL)
       {
	free(str1);
       return NULL;
       }
   }
   str[n]='\0';
   return str;
 }

