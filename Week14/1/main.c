#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

void sig_handler(int sig);
int main(){
    char c;
    signal(SIGINT, (void *)sig_handler);
    while(read(STDIN_FILENO,&c,1)!=0)
        write(STDOUT_FILENO,&c,1);
    return 0;
}

void sig_handler(int sig) {
    char *sig_msg = "Interrupt signal has been received\n";
    write(STDOUT_FILENO,sig_msg,strlen(sig_msg));
    exit(EXIT_SUCCESS);
}
