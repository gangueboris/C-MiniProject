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
    else printf("The dict is full\n");
}