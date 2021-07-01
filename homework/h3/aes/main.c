#include <stdio.h>
#include "aes.h"
#include <time.h>

void print_message(uint8_t x[16]){
    for(int i = 0; i < 16; i++) {
        printf("%02x", x[i]);
    }
    printf("\n");
}

int compare(const uint8_t origin[16], const uint8_t *final) {
    for(int i = 0; i < 16; i++){
        if(origin[i] != final[i]) return 0;
    }
    return 1;
}

int main() {
    uint8_t message[16];
    uint8_t key[16];

    //randomly generate plaintext and key
    srand(time(0));
    for(int i = 0; i < 16; i++) {
        message[i] = (uint8_t) (rand() % 256);
        key[i] = (uint8_t) (rand() % 256);
    }
    uint8_t key1[16] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
    uint8_t **round = key_expansion(key1);
    printf("Plaintext: ");
    print_message(message);
    printf("Key: ");
    print_message(key);

    //encode the message into ciphertext using key
    uint8_t *cipher = encode(message, key);
    printf("Ciphertext: ");
    print_message(cipher);

    //decode the ciphertext into original message
    uint8_t *decipher = decode(cipher, key);
    printf("Text after decoding: ");
    print_message(decipher);

    //compare the text after decoding and the original plaintext to check correctness
    if(compare(message, decipher))
        printf("Successfully encoded and decoded!\n");
    else
        printf("Decoding failed.\n");

    free(cipher);
    free(decipher);
    for(int i = 0; i < 16; i++) {
        printf("0x%02x, ", round[1][i]);
    }
    for(int i = 0; i < 11; i++){
        free(round[i]);
    }
    free(round);
    return 0;
}
