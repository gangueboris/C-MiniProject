#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"
#define NBRE_C 100

int main() {
    // Storage board
    client* storage;
    int verification;
    int nbre = 0;
    storage = (client*)malloc(NBRE_C * sizeof(client));
    verification = create_account(storage, &nbre);
    if(!verification) printf("Success !!!!\n");
    displayCustomer(storage[0]);

     
    return 0;
}
