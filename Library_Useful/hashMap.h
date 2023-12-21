#ifndef HASH_MAP_H
#define HASH_MAP_H
# define N 5

typedef struct{
 char* tuple[N][2]; 
}hash;

//Function get_len
int get_len(char* value);

// Function get_hash --> convert the key to index
int get_hash(char* key);

// Function add value
void add(char* key, char* val);

// free function 
void get_free();

// get a value function
char* get(char* key);

//delete function
void del();

extern hash dict[N];
#endif
