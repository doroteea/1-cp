#include "stock.h"

int main()
{
    FILE *f;
    f=fopen("stock1.dat","r");
    FILE *g;
    g=fopen("stock2.dat","r");
    FILE *h;
    h=fopen("stock.dat","w");

    int n=0,m=0,k=0;
    stocks *company1=readStocks(&n,f);
    stocks *company2=readStocks(&m,g);

    fputs("Products from both companies are:",h);
    fputs("\n",h);
    stocks *commonStocks=commonStock(n,m,company1,company2,&k);
    printStock(k,commonStocks,h);

    fputs("Products after price change are:",h);
    fputs("\n",h);
    commonStocks=changePrice(commonStocks);
    printStock(k,commonStocks,h);
    return 0;
}
