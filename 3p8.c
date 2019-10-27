#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int convertToArab (char s[25])
{
    int l = strlen (s), nr = 0;
    int i = 0;
    while (i < l)
    {
        if (s[i] == 'I')
        {
            if (s[i + 1] != 'V' && s[i + 1] != 'X')
                nr++;
            else
            {
                if (s[i + 1] == 'V')
                    nr += 4;
                else nr += 9;
                i++;
            }
        }
        else
        {
            if (s[i] == 'V')
                nr += 5;
            else
            {
                if (s[i] == 'X')
                {
                    if (s[i + 1] != 'L' && s[i + 1] != 'C')
                         nr += 10;
                    else
                    {
                        if (s[i + 1] == 'L')
                            nr += 40;
                        else
                            nr += 90;
                        i++;
                    }
                }
                else
                {
                    if (s[i] == 'L')
                        nr += 50;
                    else
                    {
                        if (s[i] == 'C')
                        {
                            if (s[i + 1] != 'D' && s[i + 1] != 'M')
                                nr += 100;
                            else
                            {
                                if (s[i + 1] == 'D')
                                    nr += 400;
                                else nr += 900;
                                i++;
                            }
                        }
                        else
                        {
                            if (s[i] == 'D')
                                nr += 500;
                            else nr += 1000;
                        }
                    }
                }
            }
        }
        i++;
    }
    return nr;
}

int main ()
{
    char s[25];
    scanf ("%s", s);
    printf ("%d", convertToArab (s));
    return 0;
}
