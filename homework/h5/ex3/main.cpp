#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
using namespace std;

// This function is used to calculate each fraction integer of e/n
vector<int> fraction(long long int n, long long int e) {
    vector<int> result;
    int d = n / e;
    long long int temp = n;
    n = e;
    e = temp - d * e;
    result.push_back(d);
    while(n % e != 0){
        //cout << n << " " << e << endl;
        d = n / e;
        result.push_back(d);
        temp = n;
        n = e;
        e = temp - d * e;
    }
    result.push_back(n / e);
    return result;
}

//use the algorithm below to generate every k,d pair
void generate_kd(vector<int> frac, vector<long long int>& k, vector<long long int>& d){
    for(int i = 0; i < frac.size(); i++){
        long long int x = 0, y = 0, z = 1;
        if(i == 0) {
            k.push_back(1);
            d.push_back(frac[0]);
            continue;
        }
        for(int j = i; j > 0; j--) {
            if(j == i) x = frac[j];
            y = x;
            x = frac[j - 1] * x + z;
            z = y;
        }
        d.push_back(x);
        k.push_back(z);
        x = 0;
        y = 0;
        z = 1;
    }
}

//print out each value in vector
template <class T>
void print_vec(vector<T> vec) {
    for(auto i:vec) {
        cout << i << " ";
    }
    cout << endl;
}

template <class T>
void solve_pq(long long int n, long long int e, vector<T> d_satisfy, vector<T> k) {
    for(int i = 0; i < d_satisfy.size(); i++){
        long long int phi = (e * d_satisfy[i] - 1) / k[i];
        cout << "phi: " << phi << endl;
        long long int b = n - phi + 1;
        double x1 = (b + sqrt(b * b - 4 * n)) / 2;
        double x2 = (b - sqrt(b * b - 4 * n)) / 2;
        cout << "p: " << x1 << " " << "q: " << x2 << endl;
    }
}

int main() {
    long long int n = 317940011;
    long long int e = 77537081;
    vector<int> frac = fraction(n, e);
    cout << "frac: ";
    for(int i : frac) {
        cout << i << " ";
    }
    cout << endl;

    vector<long long int> k;
    vector<long long int> d;
    //use the algorithm below to generate every k,d pair
    generate_kd(frac, k, d);
    cout << "k: ";
    print_vec(k);

    cout << "d: ";
    print_vec(d);

    double d0 = pow(n, 0.25) / 3;
    cout << "d constraint: " << d0 << endl; //the constraint for d < 1/3 * (n^(1/4))

    vector<long long int> d_satisfy;
    cout << "d satisfy: ";
    for(auto i:d) {
        if(i < d0) {
            d_satisfy.push_back(i);
            cout << i << " ";
        }
    }
    cout << endl;

    solve_pq(n, e, d_satisfy, k);
    return 0;
}
