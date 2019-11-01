#include <iostream>

using namespace std;
void swap2(int &i, int &j)// nu se salveaza swapul
{
    int aux=i;
    i=j;
    j=aux;
}
int main()
{
    int a=8,b=9;
   swap2(a,b);
   cout<<a<<"  "<<b;
    return 0;
}
