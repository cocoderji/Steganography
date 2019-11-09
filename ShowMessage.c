/*
porpuse :  Given an input image, which has a text hidden in it this program decrypts the text message.
Author  : Satyam Patel
Date    : 09/04/17
Prameter: InputImage.pgm 
*/
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include"ImageOperation.h"
#include<math.h>

void main(int argc,char*argv[])
{
struct data *detail=readimage(argv[1]);

int a3,i=0,j,n,a,b,l=1,k=0,Ascii,iMessage[100000],iBinary[100000];

n = detail->cImage[detail->iHeight-1][detail->iWidth-1];

for(i=0;i<detail->iHeight;i++)
{
    for(j=0;j<detail->iWidth;j++)
    {


        if(l-1<7*n)
        {
             if(detail->cImage[i][j]%2==0)
            {
                iBinary[l]=0;
              }
            else
            {
                iBinary[l]=1;
             }
        }
        l++;
    }
}
l=0;
Ascii=0;
for(i=0;i<7*n;i++)
{
    Ascii=Ascii+iBinary[i+1]*pow(2,k);
    k++;
    if((i+1)%7==0)
    {
        iMessage[l]=Ascii;
        l++;
        k=0;
        Ascii=0;
    }
}
printf("\nMessage is :");
for(i=0;i<n;i++)
{
    printf("%c",iMessage[i]);
}
printf("\n");
}
