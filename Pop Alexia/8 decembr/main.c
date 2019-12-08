#include <stdio.h>
#include <stdlib.h>
typedef struct Item
{
    char itemName[30];
    int quantity;
    float price, totalAmount ;
} item;
float getTotalAmount(struct Item item)
{
    item.totalAmount=item.price*(float)item.quantity;
    return (item.totalAmount);
}
int main()
{
    struct Item item;
    float tamount;
    printf("Introduce the name of the product \n");
    scanf("%s",&item.itemName);
    printf("Introduce the quantity of the product \n");
    scanf("%d",&item.quantity);
    printf("Introduce the price of one piece \n");
    scanf("%f",&item.price);
    tamount=getTotalAmount(item);
    printf("Total price of al quantities is %f",tamount);

    return 0;
}
