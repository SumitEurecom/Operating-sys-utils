#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void sigsegv_handler(int signum) {
    printf("Page fault detected (SIGSEGV)\n");
    exit(EXIT_FAILURE);
}

int main() {
    // Set up the signal handler for SIGSEGV
    if (signal(SIGSEGV, sigsegv_handler) == SIG_ERR) {
        perror("Error setting up signal handler");
        return EXIT_FAILURE;
    }

    // Cause a page fault (accessing NULL pointer)
    int *ptr = NULL;
    printf("Attempting to access NULL pointer...\n");
    printf("%d\n", *ptr);

    // This code will not be reached if a page fault occurs
    printf("No page fault detected.\n");

    return EXIT_SUCCESS;
}
