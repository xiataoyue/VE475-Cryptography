#include <iostream>
#include <cstdlib>
#include <cstdint>

using namespace std;

//use uint64_t so that it can calculate very large numbers
uint64_t gcd(uint64_t a, uint64_t b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

uint64_t f(uint64_t x, uint64_t n){
    return ((x * x + 1) % n);
}

uint64_t pollard_rho(uint64_t n) {
    uint64_t x = 2;
    uint64_t y = 2;
    uint64_t d = 1;

    while(d == 1){
        x = f(x, n);
        y = f(f(y, n), n);
        if(x >= y) d = gcd(x - y, n);
        else d = gcd(y - x, n);
    }

    if(d == n) return 0;
    else return d;
}

int main() {
    uint64_t n;
    cout << "Please input a number n to be factorized:";
    cin >> n;
    uint64_t d = pollard_rho(n);
    if(d == 0) cout << "n doesn't have a factorization!" << endl;
    else{
        cout << "n's factorization is: " << n << " = " << d;
        while(d != 0){
            n = n / d;
            d = pollard_rho(n);
            if(d != 0) cout << " x " << d;
        }
        cout << " x " << n << endl;
    }
    return 0;
}
