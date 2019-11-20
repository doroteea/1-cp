#include <stdio.h>
/*For F1-F12 it outputs 0;
and for CTRL+[a list of characters] it outputs its position a=1,b=2,...,z=26,[=27,\=28,]=29*/
int main()
{
    char a;
    a=getch();
    printf("%d",a);
    return 0;
}
