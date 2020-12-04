#include <unistd.h>
#include <fcntl.h>

int main() {
    int i;
    char c;
    int fd1, fd2;
    fd1 = open("foo.txt", O_RDONLY);
    fd2 =open("output.txt", O_CREAT | O_WRONLY, S_IRUSR);
    while(read(fd1, &c, 1)!=0)
        write(fd2, &c, 1);
    close(fd1);
    close(fd2);
    
    return 0;
}