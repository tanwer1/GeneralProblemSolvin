/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: tarique
 *
 * Created on May 10, 2020, 2:09 AM
 */

#include <cstdlib>
#include <iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<iterator>

using namespace std;

class Solution {
public:
    static vector<int> twoSum(vector<int> &vec, int sum) {
        std::vector<int> result; 
        std::map<int, int> numToPosMap;
        for(int i = 0; i<vec.size(); ++i) {
            if (numToPosMap.find(sum-vec[i]) != numToPosMap.end()) {
                result.push_back(i);
                result.push_back(numToPosMap[sum-vec[i]]);
                return result;
            } else { 
                numToPosMap[vec[i]] = i;
            }
        }
        return result;
    }
};

void test(vector<int> v1, int sum, vector<int> expected) {
    vector<int> result = Solution::twoSum(v1, sum);
    if (result != expected || (result.size() == expected.size() && result.size() == 0)){
        cout<<"Result matches for sum :"<< sum<<endl;
    } else {
        cout<<"Failed for sum: "<<sum<<endl;
        cout<<"Expected: ";
        cout<< "  Size : "<<expected.size();
        cout<<"   Vector: {";
        for (auto itr = expected.begin(); itr != expected.end(); ++itr) {
            cout<< " "<< *itr;
        }
        cout<<" }"<<endl;

        cout<<"Result: ";
        cout<< "  Size : "<<result.size();
        cout<<"   Vector: {";
        for (auto itr = result.begin(); itr != result.end(); ++itr) {
            cout<< " "<< *itr;
        }
        cout<<" }"<<endl;
    }
}
/*
 * 
 */
int main(int argc, char** argv) {

    int x1 [] = {0, 2, 1,7, 3 };
    int result1 [] = {3, 4};
    
    vector<int> v1 (begin(x1), end(x1));
    vector<int> v2(begin(result1), end(result1));
    test(v1, 10, v2);
    test(v1, 20, vector<int>());
    
    int result3 [] = {0, 2};
    vector<int> v3(begin(result1), end(result1));
    test(v1, 1, v3);

    return 0;
}

