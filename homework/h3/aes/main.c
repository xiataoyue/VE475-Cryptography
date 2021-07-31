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
    uint8_t message[16] = {0x0f, 0x15, 0x14, 0x06, 0x06, 0x06, 0x07, 0x08, 0x19, 0x13, 0x0d, 0x0b, 0x35, 0x16, 0x3c, 0x0d};;


    //randomly generate plaintext and key
    srand(time(0));
    //for(int i = 0; i < 16; i++) {
        //message[i] = (uint8_t) (rand() % 256);
        //key[i] = (uint8_t) (rand() % 256);
    //}

    uint8_t key[16] = {0x16, 0x19, 0x16, 0x08, 0x16, 0x19, 0x0d, 0x0e, 0x16, 0x19, 0x8, 0x37, 0x35, 0x3c, 0x36, 0x34};
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

    return 0;
}
