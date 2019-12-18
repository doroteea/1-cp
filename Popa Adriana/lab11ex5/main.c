#include "directory.h"

int main()
{
    directory *d=readDirectory();
    printDirectory(d);
    directory *a=sortByName(d);
    printDirectory(a);
    directory *b=sortByDate(d);
    printDirectory(b);
    return 0;
}
