#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

pid_t Fork(void) {
  pid_t pid;

  if((pid=fork()) <0){
      printf("Fork Error\n");
      exit(1);
  }
  return pid;
}


int main(){
  int input, times, i=0;
  pid_t pid= Fork();

  printf("Enter an integer: ");
  scanf("%d",&input);
  printf("Enter the number of times to execute parent and child processes, respectively: ");
  scanf("%d",&times);


    if(pid==0) {
      /*child process*/
        for(int i=0;i<times;i++)
      printf("Child: x=%d\n",++input);
    }
    else {
    /*Parent process */
      for(int i=0;i<times;i++){
      printf("Parent: x=%d\n",--input);
    }
    }
}
