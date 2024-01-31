#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include "header.h"
#define N 100

//- Creation of an account
// In need a place to store accounts

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
void displayCustomer(client customer){
    printf("Customer Name: %s\n",customer.name);
    printf("Customer FirstName: %s\n",customer.firstName);
    printf("Customer Balance: %d \n",customer.balance);
}

// display all customer
void displayAllCustomer(client*storage, int nbreCustomer){
    for(int i = 0; i < nbreCustomer ; i++){
        displayCustomer(storage[i]);
        printf(".............................\n");
    }
}

// Delete an account 
void deleteAccount(client* storage,int id){
    storage[id].name = NULL;
    storage[id].firstName = NULL;
    storage[id].balance = 0;
}

//delete opticon
int deleteOption(client* storage, int nbre){
    char bufferName[100];
    char bufferFirstName[100];
    int balance;
    printf("Enter your name: ");
    fgets(bufferName,N,stdin);
    bufferName[strcspn(bufferName,"\n")] = '\0';
    printf("Enter your First name: ");
    fgets(bufferFirstName,N,stdin);
    bufferFirstName[strcspn(bufferFirstName,"\n")] = '\0';
    printf("Enter your balance: ");
    scanf(" %d",&balance);
    getchar();

    for(int i = 0; i < nbre; i++){
        if(strcmp(storage[i].name,bufferName) == 0 && strcmp(storage[i].firstName,bufferFirstName) == 0 && storage[i].balance == balance){
            return i;
        }
    }
    return -1;
}


