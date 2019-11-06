#include <stdio.h>
#include <stdlib.h>

int main()
{
    float *row1=(float*)malloc(sizeof(float)*6);
    float *row2=(float*)malloc(sizeof(float)*5);
    float *row3=(float*)malloc(sizeof(float)*11);
    float generator=0.6;
    int i,sir3=0;
    for(i=0; i<6; i++)
    {
        row1[i]=generator;
        generator=generator+0.6;
    }
    generator=0.3;

    for(i=0; i<5; i++)
    {
        row2[i]=generator;
        generator=generator+0.3;
    }
    int sir1=0,sir2=0;
    if(row1[0]<row2[0])
        row3[sir3++]=row1[sir1++];
    else
        row3[sir3++]=row2[sir2++];
    while(sir1<6 && sir2<5)
    {
        if(row1[sir1]<row2[sir2] )
        {
            if(row3[sir3-1]!=row1[sir1])
            {
                row3[sir3++]=row1[sir1++];
            }
            else
            {
                sir1++;
            }
        }
        else if(row2[sir2]<=row1[sir1]  )
        {
            if(row3[sir3-1]!=row2[sir2])
            {
                row3[sir3++]=row2[sir2++];
            }
            else
            {
                sir2++;
            }
        }
    }

    if(sir1<6-1)
    {
        for(int p=sir1; p<6; p++)
        {
            row3[sir3++]=row1[p];
        }
    }
    if(sir2<5-1)
    {
        for(int p=sir2; p<5; p++)
        {
            row3[sir3++]=row2[p];
        }
    }
    for(i=0; i<sir3; i++)
    {
        printf("%f ",row3[i]);
    }
    return 0;
}
