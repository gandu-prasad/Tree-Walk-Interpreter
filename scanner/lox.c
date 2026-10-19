#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void runPrompt();
void runFile(char path[]);
void error(int line,char where[], char message[]);


int main(int argc, char *argv[]) {
    if (argc > 2) {
        printf("Usage : jlox[script]\n");
        exit(64);
    } else if (argc == 2) {
        runFile(argv[1]);
    } else {
        runPrompt();
    }

    return 0;
}

void runFile(char path[]) {
    char bytes[256];

    FILE *fp = fopen(path, "r");

    if (fp == NULL) return;

    while (fgets(bytes, sizeof(bytes), fp)) {
        printf("%s", bytes);
    }
}

void error(int line, char where[], char message[]) {
     printf("[line %d ] Error %s : %s", line, where, message);
}
