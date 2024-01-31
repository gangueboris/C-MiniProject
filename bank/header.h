#ifndef BANK_H
#define BANK_H

typedef struct {
       char* name; 
       char* firstName;
       int balance;
}client;

int create_account();

void displayCustomer(client customer);

void displayAllCustomer(client*storage, int nbreCustomer);

void deleteAccount(client* storage,int id);
int deleteOption(client* storage, int nbre);



#endif