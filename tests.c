#include "cipher.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>


char* getRandomString() {
    int lower = 1;
    int upper = 100;
    size_t length = (rand() % (upper - lower + 1)) + lower;

    char* randomString = (char*)malloc(sizeof(char) * (length + 2));    
    if (randomString == NULL) {
        perror("Memory Allocation Failed");
        return NULL;
    }

    for (size_t j = 0; j < length; j++) {
        randomString[j] = (rand() % 26) + 'a';
    }
    randomString[length] = '\n';
    randomString[length + 1] = '\0';

    return randomString; 
}

int main(int argc, char** argv) {
    srand(time(NULL));

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <number_of_lines> <key>\n", argv[0]);
        return -1;
    }

    FILE* inputFilePtr = fopen("input.txt", "w");
    if (inputFilePtr == NULL) {
        perror("Error opening input file");
        return -1;
    }

    FILE* encryptedFilePtr = fopen("output.txt", "w");
    if (encryptedFilePtr == NULL) {
        perror("error in opening file");
        fclose(inputFilePtr);
        return -1;
    }

    for (int i = 0; i < atoi(argv[1]); i++) {
        char* string = getRandomString();
        if (string != NULL) {
            fprintf(inputFilePtr, "%s", string);
            fprintf(encryptedFilePtr, "%s", encrypt(string, atoi(argv[2])));
            free(string);
        }
    }

    fclose(inputFilePtr);
    fclose(encryptedFilePtr);
    
    sleep(1);

    inputFilePtr = fopen("input.txt", "r");
    if (inputFilePtr == NULL) {
        perror("Error reopening input file");
        return -1;
    }

    encryptedFilePtr = fopen("output.txt", "r");
    if (encryptedFilePtr == NULL) {
        perror("Error reopening output file");
        fclose(inputFilePtr); 
        return -1;
    }

    char line1[INPUT_SIZE];
    char line2[INPUT_SIZE];
    int line_num = 1;

    while (fgets(line1, sizeof(line1), inputFilePtr) && fgets(line2, sizeof(line2), encryptedFilePtr)) {
        if (strcmp(line1, decrypt(line2, atoi(argv[2]))) != 0) {
            printf("\033[1;31mDifference found at line %d:\nFile1: %sFile2: %s\033[0m\n", line_num, line1, line2);
        } else {
            printf("\033[1;32m[Passed %d]\033[0m\n", line_num);
        }
        line_num++;
    }

    fclose(inputFilePtr);
    fclose(encryptedFilePtr);

    return 0;
}

