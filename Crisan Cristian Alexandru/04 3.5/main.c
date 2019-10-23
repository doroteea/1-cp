#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
/*3.5. Read from the standard input a natural number, n .
Find the greatest perfect square that is less than or equal to n .
Then find the least prime number that is greater than or equal to n .
 */
char * TestPrimeNumber(int nr)
    {
        if(nr==1)
        {
            return "NO";
        }

        else
        {
            for(int d=2; d<=sqrt(nr); d++)
                if(nr%d==0)
                    return "NO";
        }
        return "YES";
    }
char * IsPerfectSquare(int nr)
{
    if(sqrt(nr)*sqrt(nr)==nr)
        {return "YES";}
    else {return "NO";}
}
int main()
{int nr;
    scanf("%d",&nr);
    if(nr>=2)
    {int d=nr;
    bool PerfSqHasNotBeenFound=true;
    while(d>=1&&PerfSqHasNotBeenFound==true)
        {if(IsPerfectSquare(d)=="YES")
        {printf("The greatest perfect square equal or smaller than %d is: %d.\n",nr,d);
        PerfSqHasNotBeenFound=false;
        }
        d--;
        }
    bool LeastPrimeNrHasNotBeenFound=true;
    d=nr;
    while(LeastPrimeNrHasNotBeenFound==true)
         {if(TestPrimeNumber(d)=="YES")
         {
             LeastPrimeNrHasNotBeenFound=false;
              printf("The least prime number equal or greater than %d is: %d.\n",nr,d);
         }
             d++;
         }

    }
    else{printf("The greatest perfect square equal or smaller than %d is: 1.\n",nr);
    printf("The least prime number equal or greater than %d is: 2.\n",nr);
    }

    return 0;
}
