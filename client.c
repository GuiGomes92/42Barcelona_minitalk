#include <stdio.h>
#include <stdlib.h>

#include <signal.h>
#include <sys/types.h>

void handle_sigtstp(int sig) {
    printf("Stop not allowed\n");
}

int main(void) {
    struct sigaction sa;

    sa.sa_handler = &handle_sigtstp;
    sa.sa_flags = SA_RESTART;
    sigaction(SIGTSTP, &sa, NULL);

    int pid = 0;
    printf("Introduce the PID: ");
    scanf("%d", &pid);
    return 0;
} 