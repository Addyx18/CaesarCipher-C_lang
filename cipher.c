#include "cipher.h"

bool haveKey = false;

bool isNumber(const char* str) {
    if(*str == '\0') return false;
    if(*str == '+' || *str == '-') str++;
    if(strlen(str)>0)
    { 
        while(*str) {
            if(!isdigit(*str)) return false;
            str++;
        }
        return true;
    }
    return false;
}

void take_input(char* buffer, size_t size) {
    if(fgets(buffer, size, stdin)) {
        size_t len = strlen(buffer);

        if(len > 0 && buffer[len-1] == '\n') {
            buffer[len-1] = '\0';
        }
        else {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }
    }
}

void userInput(char* buffer, size_t size) {

    while(true) {
        memset(buffer, 0, size);
        take_input(buffer, size); 
        if(strcmp(buffer, YES) == 0) {
            haveKey = true; 
        }
        else if(strcmp(buffer, NO) != 0) {
            puts("Enter valid input");
            printf("Do you have the key? (type \'yes\' or \'no\' ): ");
            continue;
        }
        break;
    }
}

char* decrypt(char* buffer, int key) {
    key = key % 26;
    size_t size = strlen(buffer);
    char* output = (char*)malloc(sizeof(char) * (size + 1));

    if (output == NULL) {
        perror("Memory Allocation Failed");
        return NULL;
    }

    for (size_t i = 0; i < size; i++) {
        if (islower(buffer[i])) {
            output[i] = ((buffer[i] - 'a' - key + 26) % 26) + 'a';
        } 
        else if (isupper(buffer[i])) {
            output[i] = ((buffer[i] - 'A' - key + 26) % 26) + 'A';
        } 
        else {
            output[i] = buffer[i];
        }
    }

    output[size] = '\0';
    return output;
}

void decrypt_brute(char* buffer) { // Brute forcing
    for(int i = 1; i<=25; i++) {
        char* output = decrypt(buffer, i);
        if(output != NULL) {
            printf("%s\n", output);
            free(output);
        }
    }
}

char* encrypt(char* buffer, int key) {
    key = key % 26;
    size_t size = strlen(buffer);
    char* output = (char*)malloc(sizeof(char) * (size + 1));

    if (output == NULL) {
        perror("Memory Allocation Failed");
        return NULL;
    }

    for (size_t i = 0; i < size; i++) {
        if (islower(buffer[i])) {
            output[i] = ((buffer[i] - 'a' + key) % 26) + 'a';
        } 
        else if (isupper(buffer[i])) {
            output[i] = ((buffer[i] - 'A' + key) % 26) + 'A';
        } 
        else {
            output[i] = buffer[i];
        }
    }

    output[size] = '\0';
    return output;
}


int keyInput() {
    char buffer[SIZE] = {0};

    while(true) {
        printf("Enter key: ");
        memset(buffer, 0, SIZE);
        take_input(buffer, SIZE); 
        if(!isNumber(buffer)){
            puts("Enter valid input..");
            continue;
        }
        break;
    }
    return atoi(buffer);
}

int choiceInput() {
    char buffer[SIZE] = {0};
    puts("");
    while(true) {
        printf("Enter your choice: ");
        memset(buffer, 0, SIZE);
        take_input(buffer, SIZE); 
        if(!isNumber(buffer)){
            puts("Enter valid input..");
            continue;
        }
        int tmp = atoi(buffer);
        if(tmp > 3 || tmp < 1){
            puts("Enter valid input..");
            continue;
        }
        break;
    }
    return atoi(buffer);
}
