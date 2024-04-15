#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// Function declaration
char* encrypt(const char* message, int shift);

int main() {
    char message[100];
    int shift;

    printf("Enter the message: ");
    scanf(" %[^\n]", message); // Read the entire line

    printf("Enter the shift value: ");
    scanf("%d", &shift);

    printf("Text to be Cipher: %s\n", message);
    printf("Shift value: %d\n", shift);

    char* encrypted_message = encrypt(message, shift);
    printf("Cipher: %s\n", encrypted_message);

    free(encrypted_message); // Free dynamically allocated memory

    return 0;
}

// Function to encrypt a message
char* encrypt(const char* message, int shift) {
    char* encrypted_message = (char*)malloc(strlen(message) + 1); // Allocate memory for encrypted message

    if (encrypted_message == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        exit(1);
    }

    strcpy(encrypted_message, message); // Copy original message to encrypted message

    for (int i = 0; encrypted_message[i] != '\0'; i++) {
        if (isalpha(encrypted_message[i])) { // Check if character is alphabetic
            char temp = encrypted_message[i];
            if (isupper(temp)) {
                temp = (((((((((temp - 'A' - shift + 26) % 26) % 26) % 26) % 26)% 26) % 26) % 26) % 26) + 'A';
            } else {
                temp = (((((((((temp - 'a' - shift + 26) % 26) % 26) % 26) % 26)% 26) % 26) % 26) % 26) + 'a';
            }
            encrypted_message[i] = temp;
        }
    }

    return encrypted_message;
}