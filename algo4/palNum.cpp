
#include <iostream>
#include <vector>
#include <string>
#include <cmath> // Use cmath instead of math.h for C++ compatibility

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) {
            return false;
        }
        if(x < 10) {
            return true;
        }
        if(x >= 10) {
            int temp = x;
            int t = 0;
            while(temp != 0) {
                temp /= 10;
                t++;
            }
            int p = static_cast<int>(pow(10, t-1)); // Cast pow result to int
            int bas = x / p;
            int son = x % 10;
            if(bas != son) {
                return false;
            } else {
                int me = 1;
                while(true) {
                    if(t-me < me){
                        return true;
                    }
                    int temp2 = x;
                    if((temp2 / static_cast<int>(pow(10, t - me - 1))) % 10 == 0 && (temp2 / static_cast<int>(pow(10, me))) % 10 == 0) {
                        me++;
                        

                    } else if((temp2 / static_cast<int>(pow(10, t - me - 1))) % 10 == (temp2 / static_cast<int>(pow(10, me))) % 10) {
                        

                        return isPalindrome(x % static_cast<int>(pow(10, t - me)) / static_cast<int>(pow(10, me)));

                    } else {
                        
                        return false;
                    }
                }
            }
        }
        return false;
    }
};