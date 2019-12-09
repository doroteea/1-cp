#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int MAX_LENGTH = 200;

typedef struct
{
    char *code;
    char *name;
    char *measure;
    int amount;
    int price;
} items;
