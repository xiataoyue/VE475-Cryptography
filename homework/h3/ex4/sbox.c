//
// Created by James Xia on 2021/6/7 0007.
//
#include <stdio.h>
#include <stdint.h>

const int c[8] = {1, 1, 0, 0, 0, 1, 1, 0};

int num_bits(uint16_t x) {
    int count = 0;
    while(x > 0){
        x >>= 1;
        count ++;
    }
    return count;
}

int diff(uint16_t x, uint8_t y) {
    return num_bits(x) - num_bits(y);
}

uint8_t divide(uint16_t x, uint8_t y, uint8_t *r) {
    uint8_t result = 0;
    int dis = diff(x, y);
    while(dis >= 0) {
        result = (1 << dis) | result;
        x = x ^ (y << dis);
        dis = diff(x, y);
    }
    *r = x;
    return result;
}

uint8_t multiply(uint8_t x, uint8_t y) {
    if(x == 0 || y == 0) return 0;
    int result = y;
    int temp = y;

    uint8_t r = x % 2;
    x = x / 2;
    if(r == 0) result = 0;

    while(x != 0) {
        r = x % 2;
        x = x / 2;

        if(temp >> 7 == 0) temp = (temp << 1);
        else temp = (temp << 1) ^ 0x11b;

        if(r) result = result ^ temp;
    }
    return result;
}

uint8_t extended(uint16_t x, uint8_t y) {
    uint8_t x0 = 1, y0 = 0, x1 = 0, y1 = 1;
    uint8_t temp1, temp2;

    while(y != 0) {
        temp1 = y;
        //printf("y-for: %#x ", y);
        uint8_t q = divide(x, y, &y);
        //printf("q: %#x ", q);
        //printf("%#x ", y);
        x = temp1;
        temp1 = x1;
        temp2 = y1;
        x1 = x0 ^ multiply(x1, q);
        y1 = y0 ^ multiply(y1, q);
        x0 = temp1;
        y0 = temp2;
        //printf("x0: %#x ", x0);
        //printf("y0: %#x ", y0);
    }
    return y0;
}

uint8_t transform(uint8_t x) {
    int b[8];
    for(int i = 0; i < 8; i++) {
        b[i] = (x >> i) & 0x1;
    }

    int trans[8];
    for(int i = 0; i < 8; i++) {
        trans[i] = b[i] ^ b[(i + 4) % 8] ^ b[(i + 5) % 8] ^ b[(i + 6) % 8] ^
                   b[(i + 7) % 8] ^ c[i];
    }

    uint8_t result = 0;
    for(int i = 0; i < 8; i++) {
        result += (trans[i] << i);
    }
    return result;
}

void transform_all(uint8_t *x){
    for(int i = 1; i < 256; i++) {
        uint8_t temp = i;
        x[i] = transform(extended(0x11b, temp));
    }
    x[0] = 0x63;
}

int main(){
    uint8_t daf = 0xf8;
    uint8_t x = 0x10;
    uint8_t r;
    uint8_t y = divide(0x10, 0xb, &r);
    uint8_t z = extended(0x11b, 0x2);
    uint8_t sbox[0x100];
    transform_all(sbox);
    printf("%#x\n", z);
    printf("%#x\n", transform(0x1));

    for(int i = 0; i < 256; i++) {
        printf("0x%02x, ", sbox[i]);
        if(i % 16 == 15) printf("\n");
    }
    printf("\n");
    uint8_t inv_sbox[0x100];
    for(int i = 0; i < 256; i++) {
        inv_sbox[sbox[i]] = i;
    }
    for(int i = 0; i < 256; i++){
        printf("0x%02x, ", inv_sbox[i]);
        if(i % 16 == 15) printf("\n");
    }
}
