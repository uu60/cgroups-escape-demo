//
// Created by 杜建璋 on 2024/2/6.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("Switching user...\n");
    system("su -c 'echo Switching user >> /var/log/journal.log'");

    printf("Adding user/group...\n");
    system("unshare --user --map-root-user bash -c 'groupadd demo_group && useradd -G demo_group demo_user && echo Adding user/group >> /var/log/journal.log'");

    printf("Triggering sync...\n");
    system("sync && echo Triggering sync >> /var/log/journal.log");

    printf("Triggering exception...\n");
    int *ptr = NULL;
    *ptr = 10;  // null pointer exception

    return 0;
}