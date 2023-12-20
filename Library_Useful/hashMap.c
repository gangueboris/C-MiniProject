#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100 // Definition of the length of my htable
// NB: On utilise un tableau tab[5][4] si l'on sais que l'on va l'initialiser directement = {{},{}} sinon  on fait un malloc surtout quand on vuet mettre  des valeus dans unb tab a travers un boucle dans un tableau 



int* tab[N];
// key to index
typedef struct{
   int value;
   char key[256] ;
}keyLvalue;

keyLvalue dict[N];

int get_hash(char value[256]){
    int h = 0 ;
    int vl = strlen(value);
    for(int i = 0; i < vl; i++){
        h += (int)value[i];
    }
    return h % N ;
}

// adding the value to the index case
void add(char key[256], int val) {
    int h = get_hash(key);
    strcpy(dict[h].key, key);
    dict[h].value = val;
}

// Getting of the value
int get(char key[256]) {
    int h = get_hash(key);
    return dict[h].value;
}

// Delete function
void delete(char key[256]){
    int h = get_hash(key);
    strcpy(dict[h].key ,"NULL");
    dict[h].value = 0;
}

// getkeys function
char** get_keys(keyLvalue dict[N]){
    char** keys = malloc(N * sizeof(char*));
    for(int i = 0 ; i < N; i++){
        keys[i] = malloc(256*sizeof(char));
        strcpy(keys[i],dict[i].key);  
    } 
    return keys ;
}
int* get_values(keyLvalue dict[N], int* size) {
        int* values = malloc(N * sizeof(int));
        int count = 0;

        for (int i = 0; i < N; i++) {
            if (dict[i].value != 0) {
                values[count] = dict[i].value;
                count++;
            }
        }

        *size = count;
        return values;
}


// Delete fonction , a return value function, a return item function ,a return key function

int main(){
    char** keys;
    int* values;
    add("apple",5);
    add("banana",3);
    add("Boris",27784515);

    printf("Value  : %d\n", get("apple"));
    printf("Value  : %d\n", get("banana"));
    printf("Value : %d\n", get("Boris"));
    //delete("Boris");
    //add("BorisRolande","Hello_world");
    printf("Value : %d\n", get("Boris"));
    keys = get_keys(dict);
    values = get_values(dict);
    for(int i = 0; i < N; i++){
        printf(" %d",values[i]);
       
    }

    for(int i = 0 ; i < N; i++) free(keys[i]);  
    free(keys);
    free(values);
    return 0;
}