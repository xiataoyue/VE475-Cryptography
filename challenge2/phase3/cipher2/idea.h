#ifndef CIPHER2_IDEA_H
#define CIPHER2_IDEA_H

#include <cstdint>
#include <iostream>
#include <string>
#include <cstdlib>
#include <bitset>
using namespace std;
typedef bitset<128> k_type;

//uint16_t sub_keys[52];
//uint16_t inv_sub_keys[52];

uint16_t add(uint16_t m, uint16_t k);
uint16_t inv_add(uint16_t k);
uint16_t multi(uint16_t m, uint16_t k);
uint16_t exgcd(uint16_t a, uint16_t b);
uint16_t inv_multi(uint16_t x);
uint16_t *get_sub_key(const uint8_t key[16]);
uint16_t *get_inv_sub_key(const uint16_t sub[52]);

uint8_t *encode(const uint8_t m[8], const uint8_t key[16]);
uint8_t *decode(const uint8_t m[8], const uint8_t key[16]);


#endif //CIPHER2_IDEA_H
