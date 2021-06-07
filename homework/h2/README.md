# Readme

## Ex1_4 code

```c++
#include <iostream>
#include <cmath>
using namespace std;


int main(){
    int cnt = 0;
    int num[71];
    int prime[70];
    for(int i = 0; i < 70; i++){
        num[i] = i;
    }
	// to create a prime number list for numbers less than 70
    for (int i = 2; i < 70; i++) {
        if(num[i] != 0) {
            prime[cnt++] = num[i];
            for(int j = i * i; j < 70; j += i) {
                num[j] = 0;
            }
        }
    }

    int num1 = 4883;
    int num2 = 4369;
    int cnt1 = 0;
    int cnt2 = 0;
    int factor1[13];
    int factor2[13];
    //determine the factorials of 4883 and save them in factor1[]
    for(int i = 0; i < cnt; i++){
        if(num1 % prime[i] == 0){
            num1 = num1 / prime[i];
            factor1[cnt1++] = prime[i];
            i = 0;
        }
    }
    //determine the factorials of 4369 and save them in factor2[]
    for(int i = 0; i < cnt; i++){
        if(num2 % prime[i] == 0){
            num2 = num2 / prime[i];
            factor2[cnt2++] = prime[i];
            i = 0;
        }
    }
    //print the factorization of 4883 and 4369
    cout << 4883 << " = ";
    for(int i = 0; i < cnt1; i++){
        cout << factor1[i] << " * ";
    }
    cout << num1 << endl;
    cout << 4369 << " = ";
    for(int i = 0; i < cnt2; i++){
        cout << factor2[i] << " * ";
    }
    cout << num2 << endl;
}
```

