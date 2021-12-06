#include <stdio.h>     
#include <pthread.h>    
#include <stdlib.h>

    int num;
    int atoi(const char *nptr);
    void *random(void *x);    


int main(int argc, char* argv[])
{
  pthread_t tid;
  pthread_attr_t attr;

  if(argc != 2){
    return -1;    
  }

  if(atoi(argv[1]) < 0){
    return -1;
  }

  pthread_attr_init(&attr);
  pthread_create(&tid, &attr, random, argv[1]);//
  pthread_join(tid, NULL);
  printf("The magic number is = %d\n", num);

    return 0;
}

  void *random(void *x){

    srand(20); 
    num = rand();
        
    pthread_exit(0);
  }