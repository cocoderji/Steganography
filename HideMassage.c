/*
porpuse : Hide a text message in an image
Author  : Satyam Patel
Date    : 09/04/17
Prameter: InputImage.pgm “Message to hide” , Filename 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ImageOperation.h"

void main(int argc,char*argv[])
{
struct data *detail=readimage(argv[1]);

char *cMessage=argv[2];
int  a3,i=0,j,n,l=1,k=0,a1=0,iMessage[100000],iBinary[100000],cTemp1,cTemp2,cTemp3,cTemp4;;

n=strlen(cMessage);
if(7*n > detail->iHeight*detail->iWidth)
{
    printf("You can only enter less than : %d Characters !",(detail->iHeight*detail->iWidth/7)-10);
}
else
{
for(i=0;i<n;i++)
{
    iMessage[i]=cMessage[i];
}
for(i=0;i<n;i++)
{
    for(j=0;j<7;j++)
    {
        if(iMessage[i]%2==0)
        {
            iBinary[l]=0;
            iMessage[i]=iMessage[i]/2;
        }
        else
        {
            iBinary[l]=1;
            iMessage[i]=iMessage[i]/2;
        }
        l++;
    }
}
for(i=0;i<detail->iHeight;i++)
{
    for(j=0;j<detail->iWidth;j++)
    {
        detail->cImageOut[i][j]=detail->cImage[i][j];
    }
}
l=1;
        for (i = 0; i<detail->iHeight; i++)
        {
            for (j = 0; j<detail->iWidth;j++ )
			{
                if(i+j<7*n)
                {
                if(iBinary[l]==0 && (detail->cImageOut[i][j]%2)==1)
                {
                         detail->cImageOut[i][j]=detail->cImageOut[i][j]+1;
                }
                if(iBinary[l]==1 && (detail->cImageOut[i][j]%2)==0)
                {
                     detail->cImageOut[i][j]=detail->cImageOut[i][j]+1;
                }
                l++;
                }
            }
        }
detail->cImageOut[detail->iHeight-1][detail->iWidth-1]=n;

writeImage(argv[1],detail);
printf("\nDone!\n");
}
}
