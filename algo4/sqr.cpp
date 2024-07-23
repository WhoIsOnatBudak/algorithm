
#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int c = sqrt(x);
        return c;
        for(int i = 0 ; i < x; i++){
            if(i*i > x){
                return i-1;
            }
        }
    }
};