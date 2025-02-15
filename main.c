#include "cipher.h"

int main() {

    puts("===========   Welcome to Caesar Cipher (Encryption/ Decryption)   ===========\n\n");

    char* inputPtr = (char*)malloc(sizeof(char) * INPUT_SIZE); 

    if(inputPtr == NULL) {
        perror("Memory Allocation Failed");
        return -1;
    }

    puts("Choose your option below: ");
    puts("1- Encrypt");
    puts("2- Decrypt");
    puts("3- Exit");

    int choice = choiceInput();
    
    switch(choice) {
        case 1:
            printf("Enter text to encrypt: ");
            take_input(inputPtr, INPUT_SIZE);
            int key = keyInput(); 
            char* output = encrypt(inputPtr, key);
            if(output != NULL) {
                printf("%s\n", output);
                free(output);
            }
            break;
        case 2:
            printf("Enter text to decrypt: ");
            take_input(inputPtr, INPUT_SIZE);
            char buffer[16] = {0}; 
            printf("Do you have the key? (type \'yes\' or \'no\' ): ");
            userInput(buffer, 16);

            if(strcmp(buffer, "yes") == 0) {
                int key = keyInput(); 
                char* output = decrypt(inputPtr, key);
                if(output != NULL) {
                    printf("%s\n", output);
                    free(output);
                }
            }
            else {
                puts("Brute forcing...");
                decrypt_brute(inputPtr); // Brute-forcing
            }
            break;
        case 3:
            puts("Exitting....");
            break;
    }

    free(inputPtr);
    return 0;
}

