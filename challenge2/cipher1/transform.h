//
// Created by James Xia on 2021/6/28 0028.
//

#ifndef CHALLENGE_TRANSFORM_H
#define CHALLENGE_TRANSFORM_H

#include <vector>
#include <cstdlib>
#include <ctime>
#include <cstdint>
#include <string>
using namespace std;

static const char text[] = "fhmbzydpqnsjtrlcagewkoixvuEKJANUBOQRTYISWLGHCZXPVFMD5167048932!?).,;(";
static const uint8_t text_rev[] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 62, 0, 0, 0, 0, 0, 0, 68, 64, 0, 0, 66, 0, 65, 0, 56, 53, 61, 60, 57, 52, 54, 55,
        58, 59, 0, 67, 0, 0, 0, 63, 0, 29, 32, 44, 51, 26, 49, 42, 43, 38, 28, 27, 41, 50, 30, 33,
        47, 34, 35, 39, 36, 31, 48, 40, 46, 37, 45, 0, 0, 0, 0, 0, 0, 16, 3, 15, 6, 18, 0, 17, 1, 22, 11,
        20, 14, 2, 9, 21, 7, 8, 13, 10, 12, 25, 24, 19, 23, 5, 4, 0, 0, 0, 0, 0

};

vector<uint8_t> plaintext2byte(const string& p);
string byte2plaintext(vector<uint8_t> v);
vector<uint8_t> ciphertext2byte(const string& c);
string byte2ciphertext(vector<uint8_t> v);

#endif //CHALLENGE_TRANSFORM_H
