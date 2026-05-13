#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main() {

    int fd;
    pid_t pid;

    pid = fork();

    if(pid == 0) {

        printf("Child PID: %d\n", getpid());

        fd = open("attendance.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);

        write(fd, "Child attended\n", 16);

        close(fd);
    }

    else {

        wait(NULL);

        printf("Parent PID: %d\n", getpid());

        fd = open("attendance.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);

        write(fd, "Parent attended\n", 17);

        close(fd);
    }

    return 0;
}