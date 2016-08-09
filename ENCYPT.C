/*encrption and decryption*/
#include<stdio.h>
#include<conio.h>
void main()
{
int key;
int i=0;
char data[10];
  clrscr();
  printf("Enter the key :");
  scanf("%d",&key);
  printf("\n Enter the string : ");
  scanf("%s",data);
  for(i=0;data[i]!='\0';i++)
  {
     data[i]=data[i]+key;

  }
  printf("\n Encrypted string is : %s",data);

  for(i=0;data[i]!='\0';i++)
  {
  data[i]=data[i]-key;
  }
  printf("\n Decrypted strig is : %s ",data);
   getch();
}