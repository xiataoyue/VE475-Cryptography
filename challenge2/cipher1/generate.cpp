//
// Created by James Xia on 2021/7/2 0002.
//
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
using namespace std;

int main() {
    string x;
    int count = 0;
    srand(time(0));
    int flag = 1;
    int flag2 = 0;
    int table[7] = {33, 40, 41, 44, 46, 59, 63};
    while(count < 7) {
        int num = (rand() % 31) + 33;
        for(int i = 0; i < 7; i++) {
            if(num == table[i]){
                flag2 = 1;
                break;
            }
        }
        if(x.empty() && flag2) {
            x.push_back(num);
            count ++;
            flag2 = 0;
            continue;
        }
        else{
            for(int i = 0; i < x.size(); i++) {
                if(num == x[i]){
                    flag = 0;
                    break;
                }
            }
        }
        if(flag == 1 && flag2 == 1) {
            x.push_back(num);
            count ++;
            flag2 = 0;
        }
        else {
            flag = 1;
            flag2 = 0;
        }
    }
    cout << x << endl;
}
