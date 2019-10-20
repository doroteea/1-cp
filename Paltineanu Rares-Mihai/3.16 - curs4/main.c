/**Given two strings of n and m integer elements,  compute:
a) The string that contains all the elements belonging to both strings.
b)The string of all the elements of the two given strings, written once.
c) The string of the elements from the first string, without the elements that are also in the second string.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read(char s1[200], char s2[200], int n, int m)
{
    for(int i = 0; i < n; i++)
    {
        scanf("%c", &s1[i]);
    }
    s1[n] = '\0';

    getchar();

    for(int i = 0; i < m; i++)
    {
        scanf("%c", &s2[i]);
    }
    s2[m] = '\0';
}

int searchChar(char s[200], char a, int k)
{
    int ct = 0;
    for(int i = 0; i < k; i++)
    {
        if(s[i] == a)
        {
            ct++;
        }
    }
    return ct;
}

void newStringA(char s1[200], char s2[200], char s3[400], int n, int m, int *l)
{
    char v[200];
    int w, a = 0;
    for(int i = 0; i < m; i++)
    {
        w = 0;
        if(strchr(s1, s2[i]) != NULL && strchr(v, s2[i]) == NULL)
        {
            w = searchChar(s1, s2[i], n) + searchChar(s2, s2[i], m);
            for(int j = 0; j < w; j++)
            {
                s3[*l] = s2[i];
                (*l)++;
            }
            v[a] = s2[i];
            a++;
        }
    }
    s3[*l] = '\0';
}

void newStringB(char s1[200], char s2[200], char s4[200], int *k)
{
    for(char a = 1; a < 127; a++)
    {
        if(strchr(s1, a) != NULL && strchr(s2, a) != NULL)
        {
            s4[*k] = a;
            (*k)++;
        }
    }
    s4[*k] = '\0';
}

void newStringC(char s1[200], char s2[200], char s5[200], int n, int m, int *p)
{
    for(int i = 0 ; i < n; i++)
    {
        if(strchr(s2, s1[i]) == NULL)
        {
            s5[*p] = s1[i];
            (*p)++;
        }
    }
    s5[*p] = '\0';
}

int main()
{
    int n, m, k = 0, l = 0, p = 0;
    char s1[200], s2[200], s3[400], s4[200], s5[200];
    printf("Read n and m: ");
    scanf("%d %d", &n, &m);
    getchar();
    printf("Read the strings: ");
    read(s1, s2, n, m);

    /// a !!!!!!!!!!!!!!!!!
    newStringA(s1, s2, s3, n, m, &l);
    printf("The string that contains all the elements belonging to both strings is: %s\n", s3);

    /// b !!!!!!!!!!!!!!!!!
    newStringB(s1, s2, s4, &k);
    printf("The string of all the elements of the two given strings, written once is:%s\n", s4);

    /// c !!!!!!!!!!!!!!!!!
    newStringC(s1, s2, s5, n, m, &p);
    printf("The string of the elements from the first string, without the elements that are also in the second string is:%s\n", s5);
    return 0;
}
