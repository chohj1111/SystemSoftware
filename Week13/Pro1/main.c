#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
void signal_handler(int sig) {
  /*write codes to be executed when the interrupt is caught */
  printf("Caught SIGNINT!\n");
  exit(0);
}



int main(){
  /*Calls the signal handler with the corresponding function name
   when the interrupt happens*/
  signal(SIGINT, signal_handler);
  char *input;
  while(1){
    input = malloc(sizeof(char)*20);
    printf("Enter: ");
    scanf("%s",input);
    printf("Echo: %s\n",input);
    free(input);
  }
}
