#include <stdio.h>
#include <stdlib.h>

/*3.4. Using only pointers and pointer expressions, write a function to merge two vectors.
The given vectors contain real number elements, in ascending order.
The result vector must contain only the distinct elements of the two given vectors, also in ascending order*/
void ReadArray(float *Array, int dim)
{
    for(int i=0; i<dim; i++)
    {
        scanf("%f",&Array[i]);
    }

}
void DisplayArray(float *Array,int dim)
{

    for(int i=0; i<dim; i++)
    {
        printf("%.2f ",Array[i]);
    }
    printf("\n");
}
void Merge(float *FirstArray,float *SecondArray,float *ThirdArray,int FirstArrayLenght,int SecondArrayLenght,int *ThirdArrayLenght)
{
    int i=0,j=0;
    *ThirdArrayLenght=0;

    while(i<FirstArrayLenght&&j<SecondArrayLenght)
    {
        if(FirstArray[i]<SecondArray[j])
        {
            if(*ThirdArrayLenght==0)
            {
                ThirdArray[(*ThirdArrayLenght)++]=FirstArray[i];
            }
            else
            {
                if(ThirdArray[*ThirdArrayLenght-1]!=FirstArray[i])
                {
                    ThirdArray[(*ThirdArrayLenght)++]=FirstArray[i];
                }
            }
            i++;
        }
        else

            if(FirstArray[i]>SecondArray[j])
            {
                if(*ThirdArrayLenght==0)
                {
                    ThirdArray[(*ThirdArrayLenght)++]=SecondArray[j];
                }
                    else
                    {
                        if(ThirdArray[*ThirdArrayLenght-1]!=SecondArray[j])
                        {

                        ThirdArray[(*ThirdArrayLenght)++]=SecondArray[j];
                    }
                    }

                j++;
            }


            else
            {
                if(*ThirdArrayLenght==0)
                {
                    ThirdArray[(*ThirdArrayLenght)++]=FirstArray[i];
                }
                else
                {
                    if(ThirdArray[*ThirdArrayLenght-1]!=FirstArray[i])
                    {
                        ThirdArray[(*ThirdArrayLenght)++]=FirstArray[i];
                    }
                }
                i++;
                j++;
            }
        }

    while(i<FirstArrayLenght)
    {
        ThirdArray[(*ThirdArrayLenght)++]=FirstArray[i];
        i++;
    }
    while(j<SecondArrayLenght)
    {
        ThirdArray[(*ThirdArrayLenght)++]=SecondArray[j];
        j++;
    }
}
int main()
{
    int dim,dim2,dim3;

    printf("Lenght of the first array:");
    scanf("%d",&dim);
    float *a = (float*)malloc(sizeof(float)*dim);
    printf("Give the elements of the first array:");
    ReadArray(a, dim);
    printf("Lenght of the second array:");
    scanf("%d",&dim2);
    float *b=(float*)malloc(sizeof(float)*dim2);
    printf("Give the elements of the second array:");
    ReadArray(b, dim2);
    float *c=(float*)malloc(sizeof(float)*(dim+dim2));
    Merge(a,b,c,dim,dim2,&dim3);

    DisplayArray(c,dim3);






    return 0;
}
