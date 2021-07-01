#include <iostream>
#include <gmp.h>
#include <time.h>
#include <cstring>
using namespace std;


void generate(mpz_t *n, mpz_t *e, mpz_t *d, int security) {
    int bits;
    //according to security, decide corresponding bits of p and q
    if(security == 80) bits = 1024 / 2;
    else if(security == 112) bits = 2048 / 2;
    else if(security == 128) bits = 3072 / 2;
    else if(security == 192) bits = 7680 / 2;
    else if(security == 256) bits = 15360 / 2;


    // set random seed
    clock_t time = clock();
    gmp_randstate_t randState;
    gmp_randinit_default(randState);
    gmp_randseed_ui(randState, time);

    // initialize p and q
    mpz_t p, q, phiN, p1, q1; //p1, q1 represents phiP and phiQ
    mpz_init(p);
    mpz_init(q);
    mpz_init(phiN);
    mpz_init(p1);
    mpz_init(q1);

    //generate random p and q
    mpz_urandomb(p, randState, bits);
    mpz_urandomb(q, randState, bits);
    mpz_nextprime(p, p);
    mpz_nextprime(q, q);
    mpz_mul(*n, p, q);  // n

    mpz_sub_ui(p1, p, 1);
    mpz_sub_ui(q1, q, 1);
    mpz_mul(phiN, p1, q1);
    gmp_printf("p: %Zd\n", p);
    gmp_printf("q: %Zd\n", q);
    gmp_printf("n: %Zd\n", *n);

    // Generate e as a prime for simplicity, and corresponding d
    mpz_urandomb(*e, randState, bits/2);
    // To make rsa secure enough, according to Wiener's Theorem, e could be at least n^1.5
    // but due to that it runs for too long, we make it
    mpz_nextprime(*e, *e);
    int flag = mpz_invert(*d, *e, phiN);
    if(flag == 0) cout << "Wrong e" << endl;
    gmp_printf("e: %Zd\n", *e);
    gmp_printf("d: %Zd\n", *d);
    mpz_clear(p);
    mpz_clear(q);
    mpz_clear(phiN);
    mpz_clear(p1);
    mpz_clear(q1);
}


void encrypt(mpz_t n, mpz_t e, mpz_t *ciphertext, unsigned char* message, size_t l)
{
    mpz_t me;
    mpz_init(me);
    mpz_import(me, l, 1, 1, 0, 0, message);
    mpz_powm(*ciphertext, me, e, n);
    gmp_printf("cipher: %Zd\n", *ciphertext);
    mpz_clear(me);
}


void decrypt(mpz_t n, mpz_t d, mpz_t ciphertext, unsigned char* message)
{
    mpz_t origin;
    mpz_init(origin);
    mpz_powm(origin, ciphertext, d, n);
    mpz_export(message, nullptr, 1, 1, 0, 0, origin);
    mpz_clear(origin);
}


int main()
{
    mpz_t n, e, d;
    mpz_init(n);
    mpz_init(e);
    mpz_init(d);

    int security[5] = {80, 112, 128, 192, 256};

    string x; //input plaintext
    cout << "Please input some plaintext you like: ";
    getline(cin, x);
    cout << "plaintext: " << x << endl;

    auto* message = (unsigned char*) x.c_str();
    size_t r = strlen(x.c_str());
    auto* recovered = new unsigned char[r];
    mpz_t ciphertext;
    mpz_init(ciphertext);

    // use a for loop to realize rsa in each security level.
    for(int i : security) {
        cout << "Security level: " << i << endl;
        generate(&n, &e, &d, i);

        encrypt(n, e, &ciphertext, message, r);
        decrypt(n, d, ciphertext, recovered);
        cout << "recovered message: " << recovered << endl;
        cout << endl;
    }

    delete[] recovered;
    mpz_clear(n);
    mpz_clear(e);
    mpz_clear(d);
    mpz_clear(ciphertext);
}