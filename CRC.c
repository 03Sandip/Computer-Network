#include<stdio.h>
void main()
{
int i,j,k;
int dw[10],div[4],crc[3],dw1[10];
printf("\n Enter the data word- ");
for(i=0;i<10;i++)
{
scanf("%d",&dw[i]);
dw1[i]=dw[i];
}
printf("\n Enter the divisor- ");
for(i=0;i<4;i++)
{
scanf("%d",&div[i]);
}
for(i=10;i<14;i++){
 dw[i]=0;
}
for(i=0;i<10;i++)
{
k=i;
if(dw[i]==1)
for(j=0;j<4;j++)
{
 if(dw[k]==div[j]){
 dw[k]=0;
 crc[j]=0;
 }
 else{
 dw[k]=1;
 crc[j]=1;
 }
 k++;
}
}
printf("\n crc=");
for(i=0;i<4;i++)
{
printf("%d",crc[i]);
}
printf("\n message to send- ");
for(i=0;i<10;i++)
{
printf("%d",dw1[i]);
}
for(i=0;i<4;i++)
{
printf("%d",crc[i]);

}
printf("\n");}