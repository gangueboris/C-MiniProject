# include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "hashMap.h"
# define N 10

//Function get_len
int get_len(char* value){
    char c;
    int i = 0;
    do{
        c = value[i];
        i++;
    }while(c !='\0');
    return i-1; // don't take the last character '\0'
}

// Function get_hash --> convert the key to index
int get_hash(char* key){
    int h = 0;
    int len = get_len(key);
    for(int i = 0; i < len ; i++){
        h += (int)key[i];
    }
    return h % N;
}

// Function add value
void add(char* key, char* val){
    int h = get_hash(key);
    int i = 1;
    // not null ; same index(handle collision); not the same key again
    if(dict[h].tuple[h][0] != NULL && h == get_hash(dict[h].tuple[h][0]) && dict[h].tuple[h][0] != key){ //get_hash(dict[h].tuple[h][0]) = h_
        while(dict[h+i].tuple[h+i][0] != NULL) i++ ;
          h = h + i;
    }
    if(h < N){ // Handle memory leaks
        dict[h].tuple[h][0] = malloc(get_len(key));
        dict[h].tuple[h][1] = malloc(get_len(val));
        strcpy(dict[h].tuple[h][0],key);
        strcpy(dict[h].tuple[h][1],val);
    }
}

void get_free() {
    for (int i = 0; i < N; i++) {
        if (dict[i].tuple[i][0] != NULL) {
            free(dict[i].tuple[i][0]);
            dict[i].tuple[i][0] = NULL;  // Set to NULL after freeing to avoid double freeing
        }
        if (dict[i].tuple[i][1] != NULL) {
            free(dict[i].tuple[i][1]);
            dict[i].tuple[i][1] = NULL;  // Set to NULL after freeing to avoid double freeing
        }
    }
}
