#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "hashMap.h"
# define N 10

hash dict[N];

int main(){
   //int a = get_hash("22d");
  // printf("the %d",a);
  char* b = "Hello_world";
  char* c = "228d2Boris";
  char* d = "LeetCode";
  char* e = "ABCDEF";
  int bb = get_len(b);
  printf("bb len is :%d\n",bb);
   int h = get_hash(b);
   printf("YHJe value of h is :%d\n",h);
   add(b,c);
   printf("YHJe value of h is :%d\n",h+10);
    add(b,b);

 // add(c,b);
  
   
   for(int i = 0; i < N; i++){
    printf(" key: %s  value %s",dict[i].tuple[i][0], dict[i].tuple[i][1]);    
    }
   //get_free();
  printf("YHJe value of h is :%d\n",h); 
  
  
  
 //free(b);
 
    
   return 0;
}