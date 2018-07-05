#include <stdio.h>

int main()
{
  int n,i,number;
  int ai,sum;


  printf("SOURCE DATA:\n");
  printf ("Enter nature value: \n");
  printf("n = ");
  scanf("%d",&n);

  sum=0;
  number=0;
  printf("Enter sequence:\n");
  //for
  for (i=1;i<=n; i++){
    if (n<1)
      break;
    printf("a%02d: ",i);
    scanf("%d",&ai);
    if (ai>=0)
      sum=sum+ai;
    else
      number=number+1;
    }
  printf("\n");
  printf("RESULT:\n");
  printf("Sum of positive elements   : %d\n",sum);
  printf("Number of negative elements: %d\n",number);

  printf("\n");  printf("");
  
  printf("SOURCE DATA:\n");
  printf ("Enter nature value: \n");
  printf("n = ");
  scanf("%d",&n);

  sum=0;
  number=0;
  i=1;
  printf("Enter sequence:\n");
  //do-while
  do {
    if ( n<1)
      break;
    printf("a%02d: ",i);
    scanf("%d",&ai);
    if (ai>=0)
      sum=sum+ai;
    else
      number=number+1;
    i++;
  }while (i <= n);
  printf("\n");
  printf("RESULT:\n");
  printf("Sum of positive elements   : %d\n",sum);
  printf("Number of negative elements: %d\n",number);

  printf("\n");


  printf("SOURCE DATA:\n");
  printf ("Enter nature value: \n");
  printf("n = ");
  scanf("%d",&n);

  sum=0;
  number=0;
  i=1;
  printf("Enter sequence:\n");
  //while
  while (i <= n) {
    if ( n<1)
      break;
    printf("a%02d: ",i);
    scanf("%d",&ai);
    if (ai>=0)
      sum=sum+ai;
    else
      number=number+1;
    i++;
  }
  printf("\n");
  printf("RESULT:\n");
  printf("Sum of positive elements   : %d\n",sum);
  printf("Number of negative elements: %d\n",number);

}
