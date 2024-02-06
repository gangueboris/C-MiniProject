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

int create_account(client* storage, int* nb){ //client
    char bufferName[N];
    char bufferFirstName[N];
    char identifier[N];
    int balance;
    int password;
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
    
    // Identification
    printf("Enter your identifient: ");
    fgets(identifier, N, stdin);
    identifier[strcspn(identifier,"\n")] = '\0';
    storage[*nb].identifier = malloc(strlen(identifier)+1);
    strcpy(storage[*nb].identifier,identifier);

    // Balance
    printf("Enter your balance please: ");
    scanf(" %d",&balance); // scanf read just the input and left "\n"
    getchar(); //  Consume the newline character (\n) left in the input buffer by the previous scanf()
    storage[*nb].balance = balance;

    // password
    printf("Enter your password please: ");
    scanf("%d",&password);
    getchar();
    storage[*nb].password = password;

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
        printf("Customer Identifer: %s \n",customer.identifier);
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
        storage[i].password = storage[i+1].password;
        storage[i].identifier = storage[i+1].identifier;
    }
    (*top)--;
}
int verificationOptionRegister(client* storage, int nbre){
    char identifier[100];
    int pwd;
    printf("Enter your identifier: ");
    fgets(identifier, sizeof(identifier) - 1, stdin);  
    identifier[strcspn(identifier, "\n")] = '\0';
    printf("Enter your password: ");
    scanf("%d",&pwd);
    for (int i = 0; i < nbre; i++){
        if (!strcmp(storage[i].identifier,identifier) && pwd == storage[i].password){
            return i;
        }
    }
    return -1;

}

int verificationOptionTransfer(client* storage, int nbre){
    char bufferName[100];
    char bufferFirstName[100];
    int pwd;
    printf("Enter the recipient's namee : ");
    fgets(bufferName, sizeof(bufferName) - 1, stdin);  // Use sizeof to prevent buffer overflow
    getchar();
    bufferName[strcspn(bufferName, "\n")] = '\0';
    printf("Enter the recipient's First name: ");
    fgets(bufferFirstName, sizeof(bufferFirstName) - 1, stdin);  // Use sizeof to prevent buffer overflow
    bufferFirstName[strcspn(bufferFirstName, "\n")] = '\0';
    getchar();
    /*
    printf("Enter your password: ");
    scanf("%d",&pwd);
    */
    for (int i = 0; i < nbre; i++){
        printf("name: %s\n",storage[i].name);
        printf("firstname: %s\n",storage[i].firstName);
        printf("buffername: %s\n",bufferName);
        printf("bufferfirstname: %s\n",bufferFirstName);

        if (!strcmp(storage[i].name, bufferName) && !strcmp(storage[i].firstName, bufferFirstName)){
            return i;
        }
    }
    return -1;
}


// Transfer

void transfer(client* storage,int nbre){
    int id, ids;
    int amount;
    char dest[50];
    // verification of the source
    id = verificationOptionRegister(storage, nbre);
    printf("id:%d\n",id);
    printf("Enter the amount to send: ");
    scanf("%d",&amount);

    // Make verification --> if is avalable to send
    if(amount > storage[id].balance) printf("Not enough money in your balance !!!\n");
    else{
        ids = verificationOptionTransfer(storage,nbre);
        printf("ids:%d\n",ids);
       if(ids!= -1){
            storage[ids].balance += amount;
            storage[id].balance -= amount;
            printf("Transfer success !!\n");
       }
       else{
        printf("Error: Account not found !!!\n");
       }
    }

    
    
    
}