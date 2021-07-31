#include "idea.h"

uint16_t add(uint16_t m, uint16_t k) {
    uint16_t result = (m + k) % 65536;
    return result;
}

uint16_t inv_add(uint16_t k) {
    uint16_t result = 65536 - k;
    return result;
}

uint16_t multi(uint16_t m, uint16_t k) {
    uint16_t result = ((long long int)m * (long long int)k) % 65537;
    return result;
}
uint16_t exgcd(long long int a) {
    long long int m = 0, n = 1, temp;
    long long int x = 1, y = 0;
    long long int b = 65537;
    while(b){
        temp = m, m = x - a / b * m, x = temp;
        temp = n, n = y - a / b * n, y = temp;
        temp = b, b = (a % b), a = temp;
    }

    if(x < 0){
        x = 65537 + x;
    }
    else x = x % 65537;

    return (uint16_t)x;
}

uint16_t inv_multi(uint16_t x) {
    uint16_t result = exgcd(x);
    return result;
}

uint16_t *get_sub_key(const uint8_t key[16]) {
    auto *sub_key = new uint16_t [52];
    for(int i = 0; i < 52; i++) {
        sub_key[i] = 0;
    }
    k_type k;
    for(int i = 0; i < 16; i ++) {
        for(int j = 0; j < 8; j++) {
            k[8*i + j] = (key[i] >> (8 - j - 1)) - 2 * (key[i] >> (8 - j));
        }
    }
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 16; j++) {
            sub_key[i] += (k[16*i + j] << (16 - j - 1));
        }
    }
    for(int i = 0; i < 5; i++) {
        k_type temp = k >> 25;
        k = (k << 103) | temp;
        for(int j = 0; j < 8; j++) {
            for(int m = 0; m < 16; m++){
                sub_key[8*(i+1) + j] += (k[16*j + m] << (16 - m - 1));
            }
        }
    }
    k_type temp = k >> 25;
    k = (k << 103) | temp;
    for(int i = 48; i < 52; i++) {
        for(int j = 0; j < 16; j++) {
            sub_key[i] += (k[16*(i-48) + j] << (16 - j - 1));
        }
    }
    //This is used to avoid weak keys to some extent
    for(int i = 0; i < 52; i++) {
        sub_key[i] = sub_key[i] ^ 0x0dae;
    }
    return sub_key;

}

uint16_t *get_inv_sub_key(const uint16_t *sub) {
    auto *inv_sub_key = new uint16_t [52];

    //round 1
    inv_sub_key[0] = inv_multi(sub[48]);
    inv_sub_key[1] = inv_add(sub[49]);
    inv_sub_key[2] = inv_add(sub[50]);
    inv_sub_key[3] = inv_multi(sub[51]);
    inv_sub_key[4] = sub[46];
    inv_sub_key[5] = sub[47];

    for(int i = 6; i < 48; i += 6) {
        inv_sub_key[i] = inv_multi(sub[48 - i]);
        inv_sub_key[i + 1] = inv_add(sub[50 - i]);
        inv_sub_key[i + 2] = inv_add(sub[49 - i]);
        inv_sub_key[i + 3] = inv_multi(sub[51 - i]);
    }

    for(int i = 0; i < 48; i += 6) {
        inv_sub_key[i + 4] = sub[46 - i];
        inv_sub_key[i + 5] = sub[47 - i];
    }


    //round 8.5
    inv_sub_key[48] = inv_multi(sub[0]);
    inv_sub_key[49] = inv_add(sub[1]);
    inv_sub_key[50] = inv_add(sub[2]);
    inv_sub_key[51] = inv_multi(sub[3]);

    return inv_sub_key;
}

uint8_t *tk_copy(const uint16_t x[4]) {
    auto *result = new uint8_t [8];
    for(int i = 0; i < 4; i ++) {
        uint16_t temp1 = x[i];
        uint16_t temp2 = x[i];
        result[2*i] = (temp1 >> 8);
        result[2*i + 1] = temp2 - temp2 / 256 * 256;
    }
    return result;
}

uint8_t *encode(const uint8_t m[8], const uint8_t key[16]) {
    uint16_t me[4];
//    cout << "plain: ";
    for(int i = 0; i < 4; i ++) {
        me[i] = (m[2*i] << 8) + m[2*i+1];
//        printf("0x%.4x ", me[i]);
    }
//    cout << endl;

    auto *sub_keys = get_sub_key(key);
//    cout << "sub keys: ";
//    for(int i = 0; i < 52; i++) {
//        printf("0x%.4x ", sub_keys[i]);
//    }
//    cout << endl;
    for(int i = 0; i < 48; i += 6) {
        uint16_t temp1 = multi(me[0], sub_keys[i]);
        uint16_t temp2 = add(me[1], sub_keys[i + 1]);
        uint16_t temp3 = add(me[2], sub_keys[i + 2]);
        uint16_t temp4 = multi(me[3], sub_keys[i + 3]);
        uint16_t temp5 = temp1 ^ temp3;
        uint16_t temp6 = temp2 ^ temp4;
        uint16_t temp7 = multi(temp5, sub_keys[i + 4]);
        uint16_t temp8 = add(temp6, temp7);
        uint16_t temp9 = multi(temp8, sub_keys[i + 5]);
        uint16_t temp10 = add(temp7, temp9);
        me[0] = temp1 ^ temp9;
        me[1] = temp3 ^ temp9;
        me[2] = temp2 ^ temp10;
        me[3] = temp4 ^ temp10;
//        cout << i << ": ";
//        for(int i = 0; i < 4; i++) {
//            printf("0x%.4x ", me[i]);
//        }
//        cout << endl;
    }

    uint16_t m_[4];
    m_[0] = multi(me[0], sub_keys[48]);
    m_[1] = add(me[2], sub_keys[49]);
    m_[2] = add(me[1], sub_keys[50]);
    m_[3] = multi(me[3], sub_keys[51]);

//    cout << "me: ";
//    for(int i = 0; i < 4; i ++) {
//        printf("0x%.4x ", m_[i]);
//    }
//    cout << endl;
    auto *cipher = tk_copy(m_);
    delete[] sub_keys;
    return cipher;
}

uint8_t *decode(const uint8_t m[8], const uint8_t key[16]) {
    uint16_t me[4];
    for(int i = 0; i < 4; i ++) {
        me[i] = (m[2*i] << 8) + m[2*i+1];
    }

//    cout << "me: ";
//    for(int i = 0; i < 4; i ++) {
//        printf("0x%.4x ", me[i]);
//    }
//    cout << endl;

    auto *sub_keys = get_sub_key(key);
    auto *inv_sub_keys = get_inv_sub_key(sub_keys);

//    cout << "sub keys: ";
//    for(int i = 0; i < 52; i++) {
//        printf("0x%.4x ", sub_keys[i]);
//    }
//    cout << endl;

//    cout << "inv sub keys: ";
//    for(int i = 0; i < 52; i++) {
//        printf("0x%.4x ", inv_sub_keys[i]);
//    }
//    cout << endl;
    for(int i = 0; i < 48; i += 6) {
        uint16_t temp1 = multi(me[0], inv_sub_keys[i]);
        uint16_t temp2 = add(me[1], inv_sub_keys[i + 1]);
        uint16_t temp3 = add(me[2], inv_sub_keys[i + 2]);
        uint16_t temp4 = multi(me[3], inv_sub_keys[i + 3]);
        uint16_t temp5 = temp1 ^ temp3;
        uint16_t temp6 = temp2 ^ temp4;
        uint16_t temp7 = multi(temp5, inv_sub_keys[i + 4]);
        uint16_t temp8 = add(temp6, temp7);
        uint16_t temp9 = multi(temp8, inv_sub_keys[i + 5]);
        uint16_t temp10 = add(temp7, temp9);
        me[0] = temp1 ^ temp9;
        me[1] = temp3 ^ temp9;
        me[2] = temp2 ^ temp10;
        me[3] = temp4 ^ temp10;
    }

    uint16_t m_[4];
    m_[0] = multi(me[0], inv_sub_keys[48]);
    m_[1] = add(me[2], inv_sub_keys[49]);
    m_[2] = add(me[1], inv_sub_keys[50]);
    m_[3] = multi(me[3], inv_sub_keys[51]);
//    cout << "me: ";
//    for(int i = 0; i < 4; i ++) {
//        printf("0x%.4x ", m_[i]);
//    }
//    cout << endl;
    uint8_t *plain = tk_copy(m_);
    delete[] sub_keys;
    delete[] inv_sub_keys;
    return plain;
}