#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashMap.h"

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
void add(char* key, char* val) {
    int h = get_hash(key);
    int i = 0;

    // Check for collisions and find the next available slot
    while (dict[h].tuple[h][0] != NULL && strcmp(dict[h].tuple[h][0], key) != 0) {
        i++;
        h = (h + i) % N;  // Linear probing
    }

    // Check if the key already exists in the table
    if (dict[h].tuple[h][0] != NULL && strcmp(dict[h].tuple[h][0], key) == 0) {
        // Key already exists, update the value or handle accordingly
        free(dict[h].tuple[h][1]);  // Free the old value
        dict[h].tuple[h][1] = malloc(get_len(val) + 1);  // Allocate memory for the new value
        strcpy(dict[h].tuple[h][1], val);  // Copy the new value
    } else {
        // Key doesn't exist, insert the new key-value pair
        if (h < N) {
            dict[h].tuple[h][0] = malloc(get_len(key) + 1);
            dict[h].tuple[h][1] = malloc(get_len(val) + 1);
            strcpy(dict[h].tuple[h][0], key);
            strcpy(dict[h].tuple[h][1], val);
        } else {
            printf("The dict is full\n");
        }
    }
}

void get_free(){
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

// Function get the value by key entrering
char* get(char* key){
    int h = get_hash(key);
    int i = 0;
    while(strcmp(dict[h].tuple[h][0],key)!= 0){
        i++;
        h = (h+i) % N;
    }
    return dict[h].tuple[h][1];
}

// Delete function
void del(char* key){
    int h = get_hash(key);
    int i = 0;

    while(dict[h].tuple[h][0] != NULL && strcmp(dict[h].tuple[h][0],key) != 0){
        i++;
        h = (h+i) % N;
    }
    if(dict[h].tuple[h][0] != NULL && strcmp(dict[h].tuple[h][0],key) == 0){
        free(dict[h].tuple[h][0]);
        dict[h].tuple[h][0] = NULL;
        free(dict[h].tuple[h][1]);
        dict[h].tuple[h][1] = NULL;
    }
    else printf("Key '%s' not found \n", key);
}