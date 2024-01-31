#ifndef BANK_H
#define BANK_H

typedef struct {
       char* name; 
       char* firstName;
       int balance;
}client;

// For storing account

int create_account();
void displayCustomer(client customer);




#endif