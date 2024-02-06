#ifndef BANK_H
#define BANK_H

typedef struct {
       char* name; 
       char* firstName;
       int balance;
}client;

void expand(client** storage, int* capacity);

int create_account(client* storage, int* nb);

void displayCustomer(client customer);

void displayAllCustomer(const client*storage, int nbreCustomer);

void deleteAccount(client* storage,int*top, int position);

int verificationOption(client* storage, int nbre);



#endif