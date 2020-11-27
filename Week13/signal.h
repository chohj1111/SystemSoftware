void signal_handler(int sig) {   /*write codes to be executed when the interrupt is caught */
}

/*Calls the signal handler with the corresponding function name when the interrupt happens*/
signal(SIGINT, signal_handler);

/* Unix-style error */
void unix_error(char *msg) {
    fprintf(stderr, “%s: %s\n”, msg, strerror(errno));
    exit(0);}
