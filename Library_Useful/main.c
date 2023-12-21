#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "hashMap.h"
# define N 5

hash dict[N];

int main(){
   //int a = get_hash("22d");
   // printf("the %d",a);
   char* b = "22ddd";
   char* c = "dd2d2";
   char* d = "LeetCode";
   char* e ;
   int bb = get_len(b);
   printf("bb len is :%d\n",bb);
   int h = get_hash(b);
   printf("YHJe value of h is :%d\n",h);
   add(b,c);
   add(b,d); 
   add(c,"Hello_world");// h of bis equal to h of c
  

   
   for(int i = 0; i < N; i++){
   printf("key: %s  value %s\n",dict[i].tuple[i][0], dict[i].tuple[i][1]);    
   }
   //get_free();
   printf("YHJe value of h is :%d\n",h); 
   // e = dict[h].tuple[h][1];
  
   e = get(c);
   printf("I got the value: %s\n",e);




   get_free();



   //free(b);

   
   return 0;
}