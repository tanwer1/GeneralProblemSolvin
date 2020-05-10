/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: tarique
 *
 * Created on May 10, 2020, 12:56 AM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/* sequence of operation is : 
 *  "*", "/", "+", and "-"
 * e.g clumsy(4) = 4 *3 / 2 +1
 * 
 */

enum Curop { mult, divide, add, sub};
class Solution {
public:
    static int clumsy(int N) {
        int result = 0;
        if (N<=0) return 0;
        switch (N) {
            case 1:
                return 1;
            case 2:
                return 2;
            case 3:
                return 6;
            case 4: 
                return 7;
        }
        result = N *(N-1)/(N-2)+(N-3);
        for (int i = N-4; i >= 1; i-=4) {
            if (i>=4) {
                result -= i * (i-1) /(i-2);
                result += i-3;
            } else if (i==3) {
                result -= 6;
            } else if (i==2) {
                result -= 2;
            } else {
                result -= 1;
            }
        }
        return result;
    }
};

/*
 * 
 */
void test(int n, int expected) {
    int r = Solution::clumsy(n);
    if (r != expected) {
        cout << " Result doesn't match, expected:"<< expected << ", found:"<<r<<endl;
    } else {
        cout<< "test passed for :"<<n<<endl;
    }
}
int main(int argc, char** argv) {

    test(0,1); // 0! = 1
    test(1, 1);  // 
    test(2, 2);
    test(10, 12);
    return 0;
}
