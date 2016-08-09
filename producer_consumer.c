#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void main()
{
 int ch,n,c1=0,c2=0,produce[23],consume[23];

 printf("Enter Stack Size :  ",n);
 scanf("%d",&n);
 while(1)
 {
   
   printf("\tProducer Stack (Stack Size : %d  \n",n);
   display(c1,produce);
   printf("\nConsumer Stack (Stack Size : %d  \n",n);
   display(c2,consume);
   printf("\nCHOICES\n 1.Producer\n2.Consumer\n 3. Exit \nEnter your choice :  ");
   scanf("%d",&ch);
   switch(ch)
   {
    case 1:
   if(c1==n)
    printf("Produer stack is FULL.So Producer goes to SLEEP\n");
   else
   {
   c1++;
   printf("\tEnter PRODUCE item is :");
   scanf("%d",&produce[c1]);
   }
   break;

    case 2:
   if(c2==n)
      printf("Consumer Stack is FULL.So it goes to SLEEP!..........\n\tReset the Consumer Stack\n",c2=0);
   else if(c1==0)
     printf("\tProducer stack is EMPTY\n");
   else
    {
           c2++;
    consume[c2]=produce[c1];
    printf("\t\tCONSUME one item");
    c1--;
    }
   break;

    case 3:
   exit(0);

    default:
   printf("\tIt is Wrong choice,Please enter correct choice!............\n"); 
    } 
   
  }
} 
display(int c,int stack[])
 {
  int i;
  printf("\n\n");
  if(c==0)
  printf("\tStack is EMPTY\n\t\t(Now It is sleeping)");
  else
  for(i=1;i<=c;i++)
  printf("\t%d",stack[i]);
  printf("\n\n");
  }

