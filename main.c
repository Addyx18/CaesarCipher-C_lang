#include "cipher.h"

int main() {


     printf("_________                                      _________ .__       .__                  \n");
    printf("\\_   ___ \\_____    ____   ___________ _______  \\_   ___ \\|__|_____ |  |__   ___________ \n");
    printf("/    \\  \\/\\__  \\ _/ __ \\ /  ___/\\__  \\\\_  __ \\ /    \\  \\/|  \\____ \\|  |  \\_/ __ \\_  __ \\\n");
    printf("\\     \\____/ __ \\\\  ___/ \\___ \\  / __ \\|  | \\/ \\     \\___|  |  |_> >   Y  \\  ___/|  | \\/\n");
    printf(" \\______  (____  /\\___  >____  >(____  /__|     \\______  /__|   __/|___|  /\\___  >__|   \n");
    printf("        \\/     \\/     \\/     \\/      \\/                \\/   |__|        \\/     \\/       \n");

    printf("\n\n\033[1;32m================   Welcome to Caesar Cipher (Encryption/ Decryption)   ================\033[0m\n\n");
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
                printf("Encrypted text: %s\n", output);
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
                    printf("Decrypted text: %s\n", output);
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

