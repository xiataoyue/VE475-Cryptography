#include <iostream>
#include <cstdlib>
#include <gmpxx.h>
#include <gmp.h>
using namespace std;

unsigned long int extended(mpz_t a,mpz_t b,mpz_t& x,mpz_t& y) {
    mpz_t r, s, t;
    mpz_init(r);
    mpz_init_set_str(s, "1", 10);
    mpz_init(t);
    mpz_set_ui(x, 1);
    mpz_set_ui(y, 0);

    //gmp_printf("%Zd %Zd %Zd %Zd %Zd %Zd %Zd\n", a, b, x, y, m, n, t);
    mpz_t temp;
    mpz_init(temp);
    while(mpz_cmp_ui(b, 0) != 0){
        mpz_set(t, r);
        mpz_fdiv_q(temp, a, b);
        mpz_mul(temp, temp, r);
        mpz_sub(r, x, temp);
        mpz_set(x, t);

        mpz_set(t, s);
        mpz_fdiv_q(temp, a, b);
        mpz_mul(temp, temp, s);
        mpz_sub(s, y, temp);
        mpz_set(y, t);

        mpz_set(t, b);
        mpz_fdiv_r(b, a, b);
        mpz_set(a, t);
    }

    unsigned long int answer = mpz_get_ui(a);

    mpz_clear(r);
    mpz_clear(s);
    mpz_clear(t);
    mpz_clear(temp);
    return answer;
}

int main() {
    mpz_t a, b, c;
    string s1 = "", s2 = "";

    srand(time(0));
    for(int i = 0; i < 4096; i++) {
        if(rand() % 2 == 1){
            s1 += "1";
        }
        else s1 += "0";
    }
    const char *s11 = s1.c_str();
    srand(rand() % 10);
    for(int i = 0; i < 4096; i++) {
        if(rand() % 2 == 0){
            s2 += "0";
        }
        else s2 += "1";
    }

    const char* s22 = s2.c_str();
    mpz_init_set_str(a, s11, 2);
    mpz_init_set_str(b, s22, 2);
    mpz_init(c);
    cout << "The first number: " << endl;
    gmp_printf("%Zd\n", a);
    cout << "The second Number: " << endl;
    gmp_printf("%Zd\n", b);
    mpz_gcd(c, a, b);
    cout << "gcd using mpz_gcd(): " << endl;
    gmp_printf("%Zd\n", c);

    mpz_t x, y;
    mpz_init(x);
    mpz_init(y);

    unsigned long int gcd = extended(a, b, x, y);

    mpz_clear(a);
    mpz_clear(b);
    mpz_clear(c);
    mpz_clear(x);
    mpz_clear(y);
    cout << "gcd using Extended Euclidean Algorithm: " << endl;
    cout << gcd << endl;
    //std::cout << s11 << endl;
    //cout << s22 << std::endl;
    return 0;
}
