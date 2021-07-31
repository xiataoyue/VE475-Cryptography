#include <iostream>
#include <fstream>
#include <cstring>
#include "transform.h"

extern "C" {
#include "aes.h"
}

string generate(){
    srand(time(NULL));
    string key;
    for(int i = 0; i < 16; i++) {
        key += text[rand() % 69];
    }
    return key;
}

string encrypt(const string& message, const string& key) {
    vector<uint8_t> m = plaintext2byte(message);
    vector<uint8_t> k_ = plaintext2byte(key);
    uint8_t k[16] = {};
    for(int i = 0; i < 16; i++){
        if(i >= k_.size()) k[i] = 0;
        else k[i] = k_[i];
    }
//    cout << "k: ";
//    for(int i = 0; i < 16; i++){
//        printf("0x%x ", k[i]);
//    }
//    cout << endl;

    unsigned int rest =  16 - ((m.size() + 1) % 16);
    if(rest == 16) m.insert(m.begin(), 0);
    else{
        m.insert(m.begin(), rest);
        for(int i = 0; i < rest; i++) {
            m.push_back(i);
        }
    }

//    cout << "p: ";
//    for (auto i:m){
//        printf("0x%x ", i);
//    }
//    cout << endl;

    vector<uint8_t> cipher(m.size());
    for(int i = 0; i < m.size(); i += 16) {
        uint8_t plaintext[16] = {};
        for(int j = 0; j < 16; j++){
            plaintext[j] = m[i+j];
        }
        auto *c = encode(plaintext, k);
//        cout << "c enc: ";
//        for(int j = 0; j < 16; j++) {
//            printf("0x%x ", c[j]);
//        }
//        cout << endl;

        for(int j = 0; j < 16; j++){
            cipher[i+j] = c[j];
        }
        free(c);
    }
//    cout << "cipher: ";
//    for(auto i:cipher){
//        printf("0x%x ", i);
//    }
//    cout << endl;
    string ciphertext = byte2ciphertext(cipher);
    cout << ciphertext << endl;
    return ciphertext;
}

void decrypt(string ciphertext, const string& key){
    if(ciphertext.length() % 2 != 0) {
        srand(time(NULL));
        ciphertext += text[0];
    }
//    cout << "ciphertext: " << ciphertext << endl;
    vector<uint8_t> c = ciphertext2byte(ciphertext);

//    cout << "c: ";
//    for(auto i:c){
//        printf("0x%x ", i);
//    }
//    cout << endl;
    vector<uint8_t> k = plaintext2byte(key);
    uint8_t k_[16] = {};
    for(int i = 0; i < 16; i++){
        if(i >= k.size()) k_[i] = 0;
        else k_[i] = k[i];
    }

//    cout << "k: ";
//    for(int i = 0; i < 16; i++){
//        printf("0x%x ", k_[i]);
//    }
//    cout << endl;

    unsigned int rest = c.size() % 16;
    if(rest > 0) {
        for(int i = 0; i < 16 - rest; i++) {
            c.push_back(i);
        }
    }

//    cout << "c': ";
//    for(auto i:c){
//        printf("0x%x ", i);
//    }
//    cout << endl;

    vector<uint8_t> plain(c.size());
//    cout << c.size() << endl;

    for(int i = 0; i < c.size(); i += 16) {
        uint8_t cipher[16] = {};
        for(int j = 0; j < 16; j++) {
            cipher[j] = c[i+j];
            //printf("0x%x ", c[i+j]);
        }
//        cout << endl;
//        cout << "cc: " << endl;
//        for(int j = 0; j < 16; j++) {
//            printf("0x%x ", cipher[j]);
//        }
//        cout << endl;
        auto *m = decode(cipher, k_);
        //cout << "m: " ;
        for(int j = 0; j < 16; j++){
            plain[i+j] = m[j];
            //printf("0x%x ", m[j]);
        }
        //cout << endl;
        free(m);
    }

//    cout << "test" << endl;
//    for(int i = 0; i < plain.size(); i++) {
//        printf("0x%x ", plain[i]);
//    }
    uint8_t num = plain[0];
    plain.erase(plain.begin());
    for(int i = 0; i < num; i++) plain.pop_back();
    string plaintext = byte2plaintext(plain);
    cout << plaintext << endl;
}

int main(int argc, char *argv[]) {
    string default_key = "wGAvj(;z1jo;pz5p";
//    if(argc <= 1) cout << "wrong command." << endl;
//    else if(argc == 2 && strcmp(argv[1], "--generate") == 0) cout << generate() << endl;
//    else if(argc == 4 && strcmp(argv[1], "--generate") == 0 && strcmp(argv[2], ">>") == 0) {
//        ofstream outfile("keyfile.txt");
//        if(outfile) outfile << generate();
//        outfile.close();
//    }
//    else if(argc == 3 && strcmp(argv[1], "--encrypt") == 0) encrypt(argv[2], default_key);
//    else if(argc == 3 && strcmp(argv[1], "--decrypt") == 0) decrypt(argv[2], default_key);
//    else if(argc == 5 && strcmp(argv[1], "--encrypt") == 0 && strcmp(argv[3], "--key") == 0){
//        ifstream keyfile(argv[4]);
//        if(!keyfile.is_open()) {
//            cout << "Key file doesn't exist!" << endl;
//            exit(1);
//        }
//        else{
//            string key;
//            getline(keyfile, key);
//            encrypt(argv[2], key);
//        }
//    }
//    else if(argc == 5 && strcmp(argv[1], "--decrypt") == 0 && strcmp(argv[3], "--key") == 0){
//        ifstream keyfile(argv[4]);
//        if(!keyfile.is_open()) {
//            cout << "Key file doesn't exist!" << endl;
//            exit(1);
//        }
//        else{
//            string key;
//            getline(keyfile, key);
//            decrypt(argv[2], key);
//        }
//    }
//    return 0;
//

//    string message = "lkdddpquwrj1i3riojHDKOu731407,;.";
//    string key = "iuiqiuroiuq713658D";
//    string c = encrypt(message, key);
//    string cipher1 = "ztL8mAS194ZkxnZBstrEoB5!Y!bS52ZkHtf8uAa194RkJn.BgtvE!BT!g!vSz2Vkztn8OAe194lk.nxBctfEQBj!Y!fS?2F";
//    decrypt(c, key);
    int flag1 = 0, flag2 = 0, flag3 = 0;
    string plaintext, ciphertext, key;

    if(argc <= 1) {
        cout << "wrong command!" << endl;
        exit(-1);
    }
    else if(strcmp(argv[1], "--generate") == 0) cout << generate() << endl;
    else {
        for(int i = 0; i < argc; i++) {
            if(strcmp(argv[i], "--encrypt") == 0) {
                if(i != argc - 1){
                    plaintext = argv[i+1];
                    flag1 = 1;
                }
                else {
                    cout << "No plaintext input!" << endl;
                    exit(1);
                }
            }
            else if(strcmp(argv[i], "--decrypt") == 0) {
                if(i != argc - 1){
                    ciphertext = argv[i+1];
                    flag2 = 1;
                }
                else {
                    cout << "No ciphertext input!" << endl;
                    exit(2);
                }
            }
            else if(strcmp(argv[i], "--key") == 0) {
                if(i != argc - 1){
                    ifstream keyfile(argv[i+1]);
                    if(!keyfile.is_open()) {
                        cout << "No such file." << endl;
                        exit(3);
                    }
                    getline(keyfile, key);
                    flag3 = 1;
                    keyfile.close();
                }
                else {
                    cout << "No keyfile input exists" << endl;
                    exit(4);
                }
            }
        }

        if(flag1) {
            if(flag2){
                if(flag3){
                    encrypt(plaintext, key);
                    decrypt(ciphertext, key);
                }
                else{
                    encrypt(plaintext, default_key);
                    decrypt(ciphertext, default_key);
                }
            }
            else{
                if(flag3) encrypt(plaintext, key);
                else encrypt(plaintext, default_key);
            }
        }
        else if(flag2) {
            if(strcmp(ciphertext.c_str(), "rat9rscotnl0cClgtyrflVt0tIlStKl6r9lntNlGt0cqlBtOrMrXlclqlRrRcCtU") == 0){
                cout << "cheater: it is forbidden to decrypt the challenge ciphertext" << endl;
                exit(5);
            }
            if(flag3) decrypt(ciphertext, key);
            else decrypt(ciphertext, default_key);
        }
        else if(flag3) cout << "Only key, no text to be encrypted or decrypted!" << endl;
    }
    return 0;


}
