#include<stdio.h>
#include<conio.h>
struct process
{
 //int p_id;
  int max[3];
  int allocated[3];
  int need[3];
  int run;
};
void main()
{
struct process p[5];
int avail_res[3];
int i,j;
int temp_res[3];
int success[3];
//int res=0;
int run=0;
int dead_lock=0;
clrscr();
for(i=0;i<4;i++)
 {
 p[i].run=0;
  printf("\n Process %d \n",i+1);
  printf("Enter allocated resources :");
  for(j=0;j<3;j++)
  {
  scanf("%d",&p[i].allocated[j]);
  }
   printf("Enter max  resources :");
  for(j=0;j<3;j++)
  {
  scanf("%d",&p[i].max[j]);
  }
   printf("Enter needed resources :");
  for(j=0;j<3;j++)
  {
  scanf("%d",&p[i].need[j]);
  }
}

printf("Enter the available resources :");
for(i=0;i<3;i++)
{
  scanf("%d",&avail_res[i]);
}
printf("\n Safe sequence  :  ");
for(i=0;i<4&&run<4;i++)
 {
   if(p[i].need[0]<=avail_res[0]&&p[i].need[1]<=avail_res[1]&&p[i].need[2]<=avail_res[2])
   {
      if(p[i].run==0)
      {
       for(j=0;j<3;j++)
       {
	avail_res[j]=avail_res[j]+p[i].allocated[j];
	temp_res[j]=p[i].allocated[j]+p[i].need[j];

	if(temp_res[j]>p[i].max[j])
	{
       //	printf("\nMax resource limit reached ...Deadlock occured...Given process sequence is not safe sequence : \n");

	break;
	 }
	 else
	 {
	  success[j]=1;
	 }
	 }
	 if(success[0]==1&&success[1]==1&&success[2]==1)
	 {

	   printf(" P%d ",i+1);

	    p[i].run=1;
	 run++;
	 i=0;
	 }


	 }
       else
       {
    //   printf("Dead lock occured :");
       }


   }


 }




getch();

}