#include<stdio.h> 

struct priority
{
int
num,at,bt,wt,pt; };
struct priority
a[20],temp; int i,j,n;
float sum1=0,sum2=0;

 
int main() 
{

printf("enter no.of jobs \n"); 
scanf("%d",&n);
printf("enter priority burst time\n"); 
for(i=1;i<=n;i++)
{
printf("job(%d)",i);
scanf("%d%d",&a[i].pt,&a[i].bt);
a[i].num=i;
}

for(i=1;i<=n-1;i++)
{
for(j=i+1;j<=n;j++)
{
if(a[i].pt>a[j].pt)
{
temp=a[i];
a[i]=a[j];
a[j]=temp;
}
}
}
printf("jobs priority burst_time\n"); 
for(i=1;i<=n;i++)
{
printf("\njob[%d]\t",a[i].num); 
 printf("\t%d\t%d\n",a[i].pt,a[i].bt);
}
int t=0;
printf("the gantt is \n");
for(i=1;i<(n*10);i++);
printf("-");
printf("\n");
for(i=1;i<=n;i++)
printf("job%d\t",a[i].num);
printf("\n");
for(i=1;i<(n*10);i++);
printf("-");
printf("\n");
for(i=1;i<=n;i++)
{
a[i].wt=t;
printf("%d\t",t);
t=t+a[i].bt;
}
printf("%d\n",t);
int i;
printf("jobs waiting time t.a.t\n");
printf("_____ _______ _____");
for(i=1;i<=n;i++)
{
printf("\njob[%d]\t%d\t%d",a[i].num,a[i].wt,a[i].wt+a[i].bt);
sum1+=a[i].wt;
sum2+=a[i].wt+a[i].bt;
}
printf("avg w.t=%f\n",(float)sum1/n); 
printf("avg t.a.t =%f\n",(float)sum2/n);

return 0;
}

