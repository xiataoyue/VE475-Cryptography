//
// Created by James Xia on 2021/6/28 0028.
//
#include "transform.h"

vector<uint8_t> plaintext2byte(const string& p) {
    vector<uint8_t> b;
    for(char i : p) {
        b.push_back(text_rev[i]);
    }
    return b;
}

string byte2plaintext(vector<uint8_t> v) {
    string p;
    for(int i = 0; i < v.size(); i++) {
        p += text[v[i]];
    }
    return p;
}

vector<uint8_t> ciphertext2byte(const string& c) {
    vector<uint8_t> v;
    for(int i = 0; i < c.length(); i += 2) {
        v.push_back((text_rev[c[i]] % 4) * 69 + text_rev[c[i+1]]);
    }
    return v;
}

string byte2ciphertext(vector<uint8_t> v) {
    string c;
    srand(time(NULL));
    for(int i = 0; i < v.size(); i++) {
        c += text[v[i] / 69 + 4 * 3];
        c += text[v[i] % 69];
    }
    return c;
}
