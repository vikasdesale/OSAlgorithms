#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<dir.h>
#include<stdlib.h>
char fn2[20];
main()
{
 int c;
clrscr();
 do
{
 printf("\n\t\tMain Menu\n-------------------------------\n");
 printf("1.Copy a File\n2.Move a File\n3.Exit\n");
 scanf("%d",&c);
 switch(c)
 {
 case 1:
   copy_file();
    break;
 case 2:
   move_file();
    break;
 case 3:
   exit(0);
 }
 }
 while(c<=3);
 getch();
 return 0;
}
copy_file()
{
 FILE *f1,*f2;
 char ch,s[10],fn1[20];
 int a;
 printf("\nAre u see the privious files(1/0)?");
 scanf("%d",&a);
 if(a==1)
 print_file();
 printf("Enter the source file name:");
 scanf("%s",&fn1);
 printf("Enter the Destination file name:");
scanf("%s",&fn2);
 f1=fopen(fn1,"r");
 if(f1==NULL)
 printf("Can't open the file");
 else 
{
  f2=fopen(fn2,"w");
  while((ch=getc(f1))!=EOF)
  putc(ch,f2);
  printf("One File Copied");
  fclose(f2);
 }
  fclose(f1);
  return 0;
 }
 move_file()
 {
 FILE *f1,*f2;
 char ch,s[10],fn1[20];
 int a;
 printf("\nAre u see the privious files(1/0)?");
scanf("%d",&a);
 if(a==1)
 print_file();
 printf("Enter the source file name:");
 scanf("%s",&fn1);
 printf("Enter the Destination file name:");
 scanf("%s",&fn2);
 f1=fopen(fn1,"r");
 if(f1==NULL)
 printf("Can't open the file");
 else 
{
  f2=fopen(fn2,"w");
  while((ch=getc(f1))!=EOF)
  putc(ch,f2);
  printf("One File moved");
  fclose(f2);
  remove(fn1);
}
  fclose(f1);
  return 0;
}
 print_file()
 {
  struct ffblk ffblk;
  int d,p=0;
  char ch;
  d=findfirst("*.*",&ffblk,0);
  while(!d)
  {
  printf("%s\n",ffblk.ff_name);
  d=findnext(&ffblk);
  p=p+1;
  if(p>=20)
  {
   printf("Press any key to continue");
   getchar();
   p=0;
  }
 }
 return 0;
}



