//
// Created by James Xia on 2021/6/16 0016.
//
#include <iostream>
#include <cmath>

using namespace std;

unsigned int modulo(unsigned int a, unsigned int b, unsigned int e) {
    unsigned int c = 1;
    if(b == 1) return 0;
    for(int i = 0; i < e; i++) {
        c = (c * a) % b;
    }
    return c;
}

int main(){
    unsigned int answer;
    answer = modulo(1801, 8191, 4095);
    cout << "The final modulo is: " << answer << endl;
}