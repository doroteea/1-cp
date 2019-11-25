/**
A lorry can carry at most m kilograms.
The name of the materials, the amounts in kilograms, and the price per kilo are known.
Find a load composition such a way the value of the load is maximum.

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {

    char *materials;
    int price;
    int kilo;

} lorry;

void initialize(lorry *c, int n) {

    for(int i = 0; i < n; i++) {

        c[i].materials = (char *)malloc(60);

    }

}

void read(lorry *c, int n) {

    for(int i = 0; i < n; i++) {
        getchar();

        printf("Read the material: ");
        gets(c[i].materials);

        printf("Read the price: ");
        scanf("%d", &c[i].price);

        printf("Read the kilograms: ");
        scanf("%d", &c[i].kilo);
        printf("\n");
    }

}

void sort(lorry *c, int n) {

    lorry aux;
    bool gata = false;

    while(!gata) {

        gata =true;

        for(int i = 0; i < n - 1; i++) {

            if(c[i].price < c[i + 1].price) {

                aux = c[i];
                c[i] = c[i + 1];
                c[i + 1] = aux;
                gata = false;

            }

        }

    }

}

int maximumLoad(lorry *v, int n, int kilo) {

    int load = 0;
    int i = 0;

    while(kilo > 0 && i < n) {

        if(kilo <= v[i].kilo) {

            load += kilo * v[i].price;
            kilo = 0;


        } else {

            kilo -= v[i].kilo;
            load += v[i].kilo * v[i].price;

        }

        i++;

    }

    return load;
}

int main() {

    int mKilo, nrOfMaterials;

    printf("Enter the number of kilograms: ");
    scanf("%d", &mKilo);

    printf("Enter the number of materials: ");
    scanf("%d", &nrOfMaterials);

    lorry *carry = (lorry *)malloc(sizeof(lorry) * nrOfMaterials);

    initialize(carry, nrOfMaterials);

    read(carry, nrOfMaterials);

    sort(carry, nrOfMaterials);

    printf("%d", maximumLoad(carry, nrOfMaterials, mKilo));
    return 0;
}
