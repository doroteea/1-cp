#include <stdio.h>
#include <windows.h>

int main()
{
    int h=0, m=0, s=0;
    do
    {
        printf("%-0.2d:%-0.2d:%-0.2d", h, m, s);
        s++;
        if (s==60)
        {
            s=0;
            m++;
        }
        if (m==60)
        {
            m=0;
            h++;
        }

        Sleep(1000);
        system("cls");
    }while (h<24);
    return 0;
}
