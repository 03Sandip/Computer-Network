#include<stdio.h>
#include<string.h>
void main()
{
 char big=0;
 int i,c[10]={0}, n,pos; 
 printf("Enter the number of coefficients less than 10: ");
 scanf("%d",&n);
 printf("Enter the coefficients of x");
 printf("\n");
 for(i=0; i<n; i++){
 scanf("%d",&pos);
 if(big<pos){
 big=pos;
 }
 c[pos]=1;
 }
 printf("\nThe Divisor in Binary is: ");
 for(i=big; i>=0; i--){
 printf("%d",c[i]);
 }
 printf("\n");
 }
