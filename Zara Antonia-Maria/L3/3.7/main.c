
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    time_t timp;
    struct tm *info; ///nu stiu ce e asta e de pe google
    time(timp);
    info=localtime(&timp);
    printf("Timpul actual este %s", asctime(info));
    return 0;

    ///i give up
}
