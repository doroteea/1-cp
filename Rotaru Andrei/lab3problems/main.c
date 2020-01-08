#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define pi 3.14

int main()
{
///1

    float z,x,y;
    printf("3.1: Input x and y\n");
    scanf("%f %f",&x,&y);
    z=pow(x,y);
    printf("z=%f\n\n",z);

///3
    double angleDeg, angleRad;
    printf("angle[in degrees]=");
    scanf("%lf", &angleDeg);
    angleRad=angleDeg*pi/180.0;
    printf("sin(%f)=%f cos(%f)=%f tan(%f)=%f\n\n", angleDeg, sin(angleRad),angleDeg, cos(angleRad), angleDeg, tan(angleRad));

///4
    int year;
    printf("3.4: Input an integer representing a year\n");
    scanf("%d",&year);
    if(year>=1600&&year<=4900)
    {
        if(year%4==0)
        {
            printf("%d is bissextile\n\n",year);
        }
        else
        {
            printf("%d is not bissextile\n\n",year);
        }
    }
    else
    {
        printf("%d is not between 1600 and 4900\n\n",year);
    }
///5
    float x1,f;
    printf("3.5: Input a real number x1 and compute the value for function\n");
    scanf("%f",&x1);
    if(x1<-2)
    {
        f=x1*x1-7*x1+4;
    }
    else if(x1==-2)
    {
        f=0;
    }
    else
    {
        f=x1*x1+5*x1-2;
    }
    printf("f(%f)=%f\n\n",x1,f);

///14
    float height,age,W_male,W_female;
    char sex;
    printf("3.14: Input sex(m/f), height(cm) and age(years) of person\n");
    scanf("%c %f %f",&sex,&height,&age);
    W_male=50+0.75*(height-150)+(age-20)/4;
    W_female=W_male-10;
    if (sex=='m')
    {
        printf("Ideal weight for a male is %f",W_male);
    }
    else if(sex=='f')
    {
        printf("Ideal weight for a female is %f",W_female);
    }
    return 0;
}
