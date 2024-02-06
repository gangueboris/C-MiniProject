#ifndef BANK_H
#define BANK_H

typedef struct {
       char* name; 
       char* firstName;
       char* identifier;
       int balance;
       int password;
       
}client;

void expand(client** storage, int* capacity);

int create_account(client* storage, int* nb);

void displayCustomer(client customer);

void displayAllCustomer(const client*storage, int nbreCustomer);

void deleteAccount(client* storage,int*top, int position);

int verificationOptionTransfer(client* storage, int nbre);

int verificationOptionRegister(client* storage, int nbre);

void transfer(client* storage,int nbre);



#endif