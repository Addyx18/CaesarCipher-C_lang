#include<stdio.h>
#include<time.h>
#include<ctype.h>
#include<unistd.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#define ALPHA_SIZE 26
#define INPUT_SIZE 2048 // 2KB of input
#define YES "yes"
#define NO "no"
#define SIZE 16

bool isNumber(const char* str);
void take_input(char* buffer, size_t size);
void userInput(char* buffer, size_t size);
char* decrypt(char* buffer, int key);
void decrypt_brute(char* buffer);
char* encrypt(char* buffer, int key);
int keyInput();
int choiceInput();
