//
// Created by James Xia on 2021/6/7 0007.
//

#include "aes.h"

void sub_bytes(uint8_t bytes[16]) {
    for(int i = 0; i < 16; i++) {
        bytes[i] = sbox[bytes[i]];
    }
}

void inv_sub_bytes(uint8_t bytes[16]) {
    for(int i = 0; i < 16; i++) {
        bytes[i] = inv_sbox[bytes[i]];
    }
}

void shift_rows(uint8_t bytes[16]) {
    uint8_t temp1, temp2, temp3;

    //second row shift
    temp1 = bytes[1];
    bytes[1] = bytes[5];
    bytes[5] = bytes[9];
    bytes[9] = bytes[13];
    bytes[13] = temp1;

    //third row shift
    temp1 = bytes[2];
    temp2 = bytes[6];
    bytes[2] = bytes[10];
    bytes[6] = bytes[14];
    bytes[10] = temp1;
    bytes[14] = temp2;

    //fourth row shift
    temp1 = bytes[3];
    temp2 = bytes[7];
    temp3 = bytes[11];
    bytes[3] = bytes[15];
    bytes[7] = temp1;
    bytes[11] = temp2;
    bytes[15] = temp3;
}

void inv_shift_rows(uint8_t bytes[16]) {
    uint8_t temp1, temp2, temp3;

    //second row
    temp1 = bytes[1];
    bytes[1] = bytes[13];
    bytes[13] = bytes[9];
    bytes[9] = bytes[5];
    bytes[5] = temp1;

    //third row
    temp1 = bytes[2];
    temp2 = bytes[6];
    bytes[2] = bytes[10];
    bytes[6] = bytes[14];
    bytes[10] = temp1;
    bytes[14] = temp2;

    //fourth row
    temp1 = bytes[3];
    temp2 = bytes[7];
    temp3 = bytes[11];
    bytes[11] = bytes[15];
    bytes[15] = temp1;
    bytes[3] = temp2;
    bytes[7] = temp3;
}

uint8_t multi_two(uint8_t x) {
    if(x >= 0x80) {
        return (uint8_t) ((x << 1) ^ 0x1b);
    }
    else
        return (x << 1);
}

uint8_t multi_three(uint8_t x) {
    return (multi_two(x) ^ x);
}

uint8_t multi_four(uint8_t x) {
    return (multi_two(multi_two(x)));
}

uint8_t multi_eight(uint8_t x) {
    return (multi_two(multi_two(multi_two(x))));
}

uint8_t multi_nine(uint8_t x) {
    return (multi_eight(x) ^ x);
}

uint8_t multi_b(uint8_t x) {
    return (multi_eight(x) ^ multi_two(x) ^ x);
}

uint8_t multi_d(uint8_t x) {
    return (multi_eight(x) ^ multi_four(x) ^ x);
}

uint8_t multi_e(uint8_t x) {
    return (multi_eight(x) ^ multi_four(x) ^ multi_two(x));
}

void mix_columns(uint8_t bytes[16]) {
    uint8_t temp[4];
    int count = 0;
    for(int i = 0; i < 16; i+=4) {
        temp[0] = multi_two(bytes[i]) ^ multi_three(bytes[i + 1]) ^ bytes[i + 2] ^ bytes[i + 3];
        temp[1] = bytes[i] ^ multi_two(bytes[i + 1]) ^ multi_three(bytes[i + 2]) ^ bytes[i + 3];
        temp[2] = bytes[i] ^ bytes[i + 1] ^ multi_two(bytes[i + 2]) ^ multi_three(bytes[i + 3]);
        temp[3] = multi_three(bytes[i]) ^ bytes[i + 1] ^ bytes[i + 2] ^ multi_two(bytes[i + 3]);

        for(int j = 0; j < 4; j++) {
            bytes[j + count] = temp[j];
        }
        count += 4;
    }
}

void inv_mix_columns(uint8_t bytes[16]) {
    uint8_t temp[4];
    int count = 0;
    for(int i = 0; i < 16; i+=4) {
        temp[0] = multi_e(bytes[i]) ^ multi_b(bytes[i + 1]) ^ multi_d(bytes[i + 2]) ^ multi_nine(bytes[i + 3]);
        temp[1] = multi_nine(bytes[i]) ^ multi_e(bytes[i + 1]) ^ multi_b(bytes[i + 2]) ^ multi_d(bytes[i + 3]);
        temp[2] = multi_d(bytes[i]) ^ multi_nine(bytes[i + 1]) ^ multi_e(bytes[i + 2]) ^ multi_b(bytes[i + 3]);
        temp[3] = multi_b(bytes[i]) ^ multi_d(bytes[i + 1]) ^ multi_nine(bytes[i + 2]) ^ multi_e(bytes[i + 3]);

        for(int j = 0; j < 4; j++) {
            bytes[j + count] = temp[j];
        }
        count += 4;
    }
}

uint8_t *tk_copy(const uint8_t x[16]) {
    uint8_t *copy = malloc(16 * sizeof(uint8_t));
    for(int i = 0; i < 16; i++) {
        copy[i] = x[i];
    }
    return copy;
}

uint8_t **key_expansion(const uint8_t key[16]) {
    uint8_t **round_key = malloc(11 * sizeof(uint8_t *));
    round_key[0] = tk_copy(key);

    for(int i = 1; i < 11; i++) {
        round_key[i] = malloc(16 * sizeof(uint8_t));
    }

    for(int i = 1; i < 11; i++) {
        round_key[i][0] = round_key[i - 1][0] ^ sbox[round_key[i - 1][13]] ^ Rcon[i];
        round_key[i][1] = round_key[i - 1][1] ^ sbox[round_key[i - 1][14]] ^ 0x00;
        round_key[i][2] = round_key[i - 1][2] ^ sbox[round_key[i - 1][15]] ^ 0x00;
        round_key[i][3] = round_key[i - 1][3] ^ sbox[round_key[i - 1][12]] ^ 0x00;
        for(int j = 4; j < 16; j++) {
            round_key[i][j] = round_key[i - 1][j] ^ round_key[i][j - 4];
        }
    }
    return round_key;
}

void free_key(uint8_t **key) {
    for(int i = 0; i < 11; i++) {
        free(key[i]);
    }
    free(key);
}

void add_round_key(uint8_t message[16], const uint8_t key[16]) {
    for(int i = 0; i < 16; i++) {
        message[i] ^= key[i];
    }
}

uint8_t *encode(const uint8_t message[16], const uint8_t key[16]){
    uint8_t *bytes = tk_copy(message);
    uint8_t **round_key = key_expansion(key);
    add_round_key(bytes, round_key[0]);

    for(int i = 1; i <= 9; i++) {
        sub_bytes(bytes);
        shift_rows(bytes);
        mix_columns(bytes);
        add_round_key(bytes, round_key[i]);
    }

    sub_bytes(bytes);
    shift_rows(bytes);
    add_round_key(bytes, round_key[10]);
    free_key(round_key);
    uint8_t *result = tk_copy(bytes);
    free(bytes);
    return result;
}

uint8_t *decode(const uint8_t cipher[16], const uint8_t key[16]){
    uint8_t *bytes = tk_copy(cipher);
    uint8_t **round_key = key_expansion(key);
    add_round_key(bytes, round_key[10]);

    for(int i = 1; i <= 9; i++) {
        inv_shift_rows(bytes);
        inv_sub_bytes(bytes);
        add_round_key(bytes, round_key[10 - i]);
        inv_mix_columns(bytes);
    }

    inv_shift_rows(bytes);
    inv_sub_bytes(bytes);
    add_round_key(bytes, round_key[0]);
    free_key(round_key);
    uint8_t *result = tk_copy(bytes);
    free(bytes);
    return result;
}