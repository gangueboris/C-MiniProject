#ifndef HASH_MAP_H
#define HASH_MAP_H
# define N 10

typedef struct{
 char* tuple[N][2]; 
}hash;

//Function get_len
int get_len(char* value);

// Function get_hash --> convert the key to index
int get_hash(char* key);

// Function add value
void add(char* key, char* val);

void get_free();

extern hash dict[N];
#endif
