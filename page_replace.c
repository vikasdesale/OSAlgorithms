#include<stdio.h>
int main()
{
int n,i,a[50],no,frame[10],k,j,avail,cnt=0;
float pr;
printf("\nEnter number of pages:");
scanf("%d",&n);
printf("\nEnter page numbers:");
for(i=1;i<=n;i++)
scanf("%d",&a[i]);
printf("\nEnter number of frames:");
scanf("%d",&no);
for(i=0;i<no;i++)
{
frame[i]=-1;
}
j=0; 
printf("\tReferntial String\tPage frames\n");
for(i=1;i<=n;i++)
{
printf("\t%d\t",a[i]);
avail=0;
for(k=0;k<no;k++)
if(frame[k]==a[i])
avail=1;
if(avail==0)
{
frame[j]=a[i];
j=(j+1)%no;
cnt++;
for(k=0;k<no; k++)
printf("\t %d\t", frame[k]);
}
printf("\n ");
}
printf("\nPage fault=%d",cnt);
pr=(float)cnt/(float)n;
printf ("\nPage Rate=%f",pr);
return 0;
}
 
