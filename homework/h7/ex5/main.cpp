#include <iostream>
#include <gmp.h>
#include <ctime>
using namespace std;

void common(mpz_t n, mpz_t alpha, mpz_t beta, mpz_t a, mpz_t b, mpz_t power) {
    mpz_t power_a, power_b;
    mpz_init_set_ui(power_a, 1);
    mpz_init_set_ui(power_b, 1);

    size_t k_a = mpz_sizeinbase(a, 2);
    size_t k_b = mpz_sizeinbase(b, 2);

    clock_t time1 = clock();
    for(int i = k_a - 1; i >= 0; i--) {
        mpz_mul(power_a, power_a, power_a);
        mpz_mod(power_a, power_a, n);

        if(mpz_tstbit(a, i)) {
            mpz_mul(power_a, power_a, alpha);
            mpz_mod(power_a, power_a, n);
        }
    }

    for(int i = k_b - 1; i >= 0; i--) {
        mpz_mul(power_b, power_b, power_b);
        mpz_mod(power_b, power_b, n);

        if(mpz_tstbit(b, i)) {
            mpz_mul(power_b, power_b, beta);
            mpz_mod(power_b, power_b, n);
        }
    }

    mpz_mul(power, power_a, power_b);
    mpz_mod(power, power, n);

    clock_t time2 = clock();
    double t = (double)(time2 - time1) / CLOCKS_PER_SEC;
    cout << "The running time of the common algorithm which calculates a, b separately is: " << t << endl;
    //gmp_printf("Power: %Zd\n", power);
    mpz_clears(power_a, power_b, NULL);

}

void faster(mpz_t n, mpz_t alpha, mpz_t beta, mpz_t a, mpz_t b, mpz_t power) {
    mpz_t prod;
    mpz_init(prod);
    mpz_mul(prod, alpha, beta);

    size_t k_a = mpz_sizeinbase(a, 2);
    size_t k_b = mpz_sizeinbase(b, 2);
    size_t k = max(k_a, k_b);
    int flag;
    if(k == k_a) flag = 1;
    else flag = 0;

    clock_t time1 = clock();
    for(int i = k - 1; i >= 0; i--) {
        mpz_mul(power, power, power);
        mpz_mod(power, power, n);
        if(flag == 1 && i >= k_b) {
            if(mpz_tstbit(a, i)) {
                mpz_mul(power, power, alpha);
                mpz_mod(power, power, n);
            }
            continue;
        }
        if(flag == 0 && i >= k_a) {
            if(mpz_tstbit(b, i)) {
                mpz_mul(power, power, beta);
                mpz_mod(power, power, n);
            }
            continue;
        }
        if(mpz_tstbit(a, i) && mpz_tstbit(b, i)) {
            mpz_mul(power, power, prod);
        }
        else if(mpz_tstbit(a, i)) {
            mpz_mul(power, power, alpha);
        }
        else if(mpz_tstbit(b, i)) {
            mpz_mul(power, power, beta);
        }
        mpz_mod(power, power, n);
    }
    clock_t time2 = clock();
    double t = (double)(time2 - time1) / CLOCKS_PER_SEC;
    cout << "The running time of the faster algorithm is: " << t << endl;
    //gmp_printf("Power: %Zd\n", power);
    mpz_clear(prod);
}

int main() {
    gmp_randstate_t randState;
    gmp_randinit_mt(randState);
    gmp_randseed_ui(randState, time(0));
    mpz_t n, alpha, beta, a, b;
    mpz_inits(n, alpha, beta, a, b, NULL);

    mpz_urandomb(n, randState, 40000);
    mpz_urandomb(alpha, randState, 20000);
    mpz_urandomb(beta, randState, 20000);
    mpz_urandomb(a, randState, 20000);
    mpz_urandomb(b, randState, 20000);

    mpz_t power1, power2;
    mpz_init_set_ui(power1, 1);
    mpz_init_set_ui(power2, 1);

    common(n, alpha, beta, a, b, power1);
    faster(n, alpha, beta, a, b, power2);

    //gmp_printf("Power1: %Zd\n", power1);
    //gmp_printf("Power2: %Zd\n", power2);
    int comp = mpz_cmp(power1, power2);
    cout << (comp == 0 ? "Same exponentiation calculated!" : "Calculation failed.") << endl;

    mpz_clears(n, alpha, beta, a, b, power1, power2, NULL);

    return 0;
}
