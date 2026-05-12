// Vigenere Cipher
// Programmed by Siddarth A S 212224040316
#include <stdio.h>
#include <string.h>


void vigenereEncrypt(char text[], const char key[]) {
    int textLen = strlen(text);
    int keyLen = strlen(key);

    for (int i = 0; i < textLen; i++) {
        char c = text[i];

        
        if (c >= 'A' && c <= 'Z') {
            text[i] = ((c - 'A' + key[i % keyLen] - 'A') % 26) + 'A';
        }

        
        else if (c >= 'a' && c <= 'z') {
            text[i] = ((c - 'a' + key[i % keyLen] - 'A') % 26) + 'a';
        }
    }
}


void vigenereDecrypt(char text[], const char key[]) {
    int textLen = strlen(text);
    int keyLen = strlen(key);

    for (int i = 0; i < textLen; i++) {
        char c = text[i];

        
        if (c >= 'A' && c <= 'Z') {
            text[i] = ((c - 'A' - (key[i % keyLen] - 'A') + 26) % 26) + 'A';
        }

        
        else if (c >= 'a' && c <= 'z') {
            text[i] = ((c - 'a' - (key[i % keyLen] - 'A') + 26) % 26) + 'a';
        }
    }
}

int main() {
    const char *key = "KEY"; 

    char message[] = "Thisisasecretmessagefromsiddarth."; 

    
    vigenereEncrypt(message, key);
    printf("Encrypted Message: %s\n", message);

    
    vigenereDecrypt(message, key);
    printf("Decrypted Message: %s\n", message);

    return 0;
}
