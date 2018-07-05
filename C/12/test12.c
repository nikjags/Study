#include <stdio.h>
#include <stdlib.h>
#include"mystring.h"

int main(int argc, char* argv[]){

  int i,n,j,k_a,k_d,k_u,k_wrong,unic;
  char* *str=NULL;

  
  j=0;
  k_wrong=0;
  k_a=0;
  k_d=0;
  k_u=0;

  /*  for (i=1;i<argc;i++){
    printf("%s\n",argv[i]);
  }
  */

  if(argc>1){
    for (n=1;n<argc;n++){
      if(argv[n][0]!='-'){
	k_wrong++;
	break;
      }
      else{
	j++;
        while(argv[n][j]!='\0'){
	  if( (argv[n][j]!='a')&&(argv[n][j]!='u')&&(argv[n][j]!='d') ){
	    k_wrong++;
	    break;
	  }
	  if(argv[n][j]=='a'){
	    k_a++;
	  }
	  if(argv[n][j]=='d'){
	    k_d++;
	  }
	  if(argv[n][j]=='u'){
	    k_u++;
	  }
	  j++;
	}
      }
      j=0;
    }
  }
  if(argc==1){
    k_a=1;
  }
  if((k_u==1)&&(k_a==0)&&(k_d==0)){
    k_a++;
  }

  /*
  printf("k_wrong = %d \n",k_wrong);
  printf("k_a     = %d \n",k_a);
  printf("k_u     = %d \n",k_u);
  printf("k_d     = %d \n",k_d);
  */
  

  if(k_wrong>0||k_a>1||k_u>1||k_d>1||((k_a==1)&&(k_d==1))){
       	printf("Usage:\n");
	printf("  mysort [options]\n");
	printf("     options:\n");
	printf("        -a --- sort ascending\n");
	printf("        -d --- sort descending;\n");
	printf("        -u --- unique sorting.\n");
        return 1;   
  }



  //Ввод строк 
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



  //Выводим полученные строки на  экран
  printf("SOURCE STRINGS:\n");
  for(j=0;j<i;j++){
    printf("%s\n",str[j]);
  }


  mysortstr02(str,i);

  //  printf("sddasdads\n");

  printf("\nSORTED STRINGS:\n");

  //Вывод строк по возрастанию (k_a = 1) и, если (k_u = 1), вывод уникальных строк
  if(k_a==1){
    printf("%s\n",str[0]);
    fflush(stdout);
    for(j=1;j<i;j++){
      if(k_u==1 && j>0){
	for (n=j-1;n>0;n--){
	  if(stringcompare(str[j],str[n])==0){
	    unic=1;
	    break;    	
	  }
	}
	if(unic==0 && k_u==1){
	  printf("%s\n",str[j]);
	  fflush(stdout);
	}
      }
      if(k_u==0){
	printf("%s\n",str[j]);
	fflush(stdout);
      }
      unic=0;
   }
  }

  //Вывод строк по убыванию (k_d = 1) и, если (k_u = 1), вывод уникальных строк
  if(k_d==1){
    for(j=i-1;j>=1;j--){
      if(k_u==1){
	for (n=j-1;n>=0;n--){
	  if(stringcompare(str[j],str[n])==0){
	    unic=1;
	    break;    	
	  }
	}
	if(unic==0 && k_u==1){
	  printf("%s\n",str[j]);
	  fflush(stdout);
	}
      }
      if(k_u==0){
	printf("%s\n",str[j]);
	fflush(stdout);
      }
      unic=0;
    }
    printf("%s\n",str[0]);
    fflush(stdout);
  }


  //Освобождаем память
    for(j=0;j<i;j++){
      free(str[j]);
    }
  return 0;
 
}
