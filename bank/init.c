#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include "header.h"
#define N 50

//- Creation of an account
// In need a place to store accounts

void expand(client** storage, int* capacity){
    *capacity *= 2;
    client* temp = realloc(*storage, *capacity * sizeof(client));
    if (temp == NULL) {
        printf("Memory not allocated \n");
        return;
    }
    *storage = temp;
    temp = NULL;
}

int create_account(client* storage, int* nb) { //client
    char bufferName[N];
    char bufferFirstName[N];
    int balance;
    //Name
    printf("Enter your name please: ");
    fgets(bufferName,N,stdin);
    bufferName[strcspn(bufferName, "\n")] = '\0';
    storage[*nb].name = malloc(strlen(bufferName)+1);
    strcpy(storage[*nb].name,bufferName);

    // First Name
    printf("Enter your first name please: ");
    fgets(bufferFirstName,N,stdin); //fgets() read all input calling operation including "\n"
    bufferFirstName[strcspn(bufferFirstName, "\n")] = '\0'; // indexOfwordsearch = strcspn(wordsearch,serchingWord)
    storage[*nb].firstName = malloc(strlen(bufferFirstName)+1);
    strcpy(storage[*nb].firstName,bufferFirstName);

    // Balance
    printf("Enter your balance please: ");
    scanf(" %d",&balance); // scanf read just the input and left "\n"
    getchar(); //  Consume the newline character (\n) left in the input buffer by the previous scanf()
    storage[*nb].balance = balance;
    //Update account
    (*nb)++ ;
    return 0;
}


// Display a customer
void displayCustomer(const client customer){
    if(customer.name == NULL){
        printf("Account doesn't exist\n");
    }
    else{
        printf("\nCustomer Name: %s\n",customer.name);
        printf("Customer FirstName: %s\n",customer.firstName);
        printf("Customer Balance: %d€ \n",customer.balance);
    }
   
}

// display all customer
void displayAllCustomer(const client* storage, int nbreCustomer) {
    if (nbreCustomer > 0){ 
        for (int i = 0; i < nbreCustomer; i++) {
            displayCustomer(storage[i]);
            printf(".............................\n");
        }
    }
    else {
        printf("No accounts to display.\n");
    }
}


void deleteAccount(client* storage,int*top, int position){ 
    //theck if position is out of bound
    if(position < 0 || position == *top){
        printf("Error: Invalid index.\n");
        return;
    }
    for(int i = position; i < *top-1; i++){
        storage[i].name = storage[i+1].name;
        storage[i].firstName = storage[i+1].firstName;
        storage[i].balance = storage[i+1].balance;
    }
    (*top)--;
}

int verificationOption(client* storage, int nbre){
    char bufferName[100];
    char bufferFirstName[100];
    printf("Enter your name: ");
    fgets(bufferName, sizeof(bufferName) - 1, stdin);  // Use sizeof to prevent buffer overflow
    bufferName[strcspn(bufferName, "\n")] = '\0';
    printf("Enter your First name: ");
    fgets(bufferFirstName, sizeof(bufferFirstName) - 1, stdin);  // Use sizeof to prevent buffer overflow
    bufferFirstName[strcspn(bufferFirstName, "\n")] = '\0';
    for (int i = 0; i < nbre; i++){
        if (strcmp(storage[i].name, bufferName) == 0 && strcmp(storage[i].firstName, bufferFirstName) == 0) {
            return i;
        }
    }
    return -1;
}


//  Menu