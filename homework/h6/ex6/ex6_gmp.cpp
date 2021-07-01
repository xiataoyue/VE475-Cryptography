#include <iostream>
#include <gmp.h>
#include <gmpxx.h>
#include <string>
using namespace std;

void f(mpz_t x, mpz_t n){
    mpz_pow_ui(x, x, 2);
    mpz_add_ui(x, x, 1);
    mpz_mod(x, x, n);
}

void ff(mpz_t y, mpz_t n) {
    for(int i = 0; i < 2; i++) {
        mpz_pow_ui(y, y, 2);
        mpz_add_ui(y, y, 1);
        mpz_mod(y, y, n);
    }
}

void pollard_rho(mpz_t d, mpz_t n) {
    mpz_t x, y, temp;
    mpz_init_set_ui(x, 2);
    mpz_init_set_ui(y, 2);
    mpz_init(temp);

    while(mpz_cmp_ui(d, 1) == 0) {
        f(x, n);
        ff(y, n);
        mpz_sub(temp, x, y);
        mpz_abs(temp, temp);
        mpz_gcd(d, temp, n);
    }
    mpz_clears(x, y, temp, NULL);
}

int main() {
    string input;
    cout << "Please input a number n to be factorized:";
    cin >> input;
    mpz_t n, d;// temp1, temp2;
    mpz_init_set_str(n, input.c_str(), 10);
    //gmp_printf("%Zd\n", n);
    mpz_init_set_ui(d, 1);
    pollard_rho(d, n);
    //gmp_printf("d: %Zd\n", d);
    if(mpz_cmp(d, n) == 0) cout << "n doesn't have a factorization!" << endl;
    else {
        gmp_printf("n's factorization is: %Zd = %Zd", n, d);
        while(mpz_cmp(d, n) != 0){
            mpz_fdiv_q(n, n, d);
            mpz_set_ui(d, 1);
            pollard_rho(d, n);
            gmp_printf(" x %Zd", d);
        }
        gmp_printf("\n");
    }
    mpz_clears(n, d, NULL);

    return 0;
}
