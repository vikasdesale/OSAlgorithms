struct scheduling
{
char name[10];
int pt,tat,wt,at,flag,remain;
}p[10],temp[10];
void fcfs();
void rr();
void main()
{
clrscr();
//fcfs();
rr();
getch();
}
void fcfs()
{
int fcnt=0;
int scnt=0;
int i,n;
 printf("Enter no of process :");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
 printf("\n Enter process name :");
 scanf("%s",p[i].name);
 printf("\n Enter burst time :");
 scanf("%d",&p[i].pt);
 }
 for(i=0;i<n;i++)
 {
  p[i].wt=fcnt;
  fcnt+=p[i].pt;
  p[i].tat=fcnt;
  printf("%s ->",p[i].name);

 }
 fcnt=0;
 scnt=0;
 printf("\n pname \t pat \t pbt  \t ptt\n ");
 for(i=0;i<n;i++)
 {
   printf(" %s \t %d \t %d  \t %d  \n",p[i].name,p[i].wt,p[i].pt,p[i].tat);
   fcnt=fcnt+p[i].wt;
   scnt=scnt+p[i].tat;
 }
 printf("\n Average waiting time %d   tat   %d",fcnt/n,scnt/n);
}

void rr()
{
 int n,i,j,tq;

 int fcnt=0;
 int scnt=0;
 printf("Ente the number of process : ");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  printf("\n Enter process name :");
  scanf("%s",p[i].name);
  printf("\n Enter burst time :");
  scanf("%d",&p[i].pt);
 p[i].flag=0;
  p[i].remain=p[i].pt;
 }
 printf("Enter tq :");
 scanf("%d",&tq);
 fcnt=0;
 scnt=0;
 while(1)
 {
 for(i=0;i<n;i++)
 {
 if(p[i].flag==0)
 {
 if(p[i].remain<=tq)
 {
  // p[i]wt=scnt;
   scnt+=p[i].remain;
   p[i].wt=scnt-p[i].pt;
   p[i].tat=scnt;
   p[i].flag=1;
   fcnt++;
   printf("-- %s --> ",p[i].name);
 }
 else
 {
 p[i].remain-=tq;
  scnt=scnt+tq;
  printf("--%s -->",p[i].name);
 }
 }
 }
 if(fcnt==n)
 break;
 }

 scnt=0;
 fcnt=0;
 printf(" \n pname \t pbt \t pwt \t \ptat \n");
 for(i=0;i<n;i++)
 {
 printf(" %s \t %d \t %d \t %d \n",p[i].name,p[i].pt,p[i].wt,p[i].tat);
    fcnt=fcnt+p[i].wt;
    scnt=scnt+p[i].tat;
    }

    printf("\n  Avg  awt  %d   avg tat %d ",fcnt/n,scnt/n);
}
