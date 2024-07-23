
#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int bas = 0;
        int son = nums.size()-1;

        for(int i = 0; i < INT_MAX ; i++){
            int mid = (bas+son)/2;

            

            if( bas + 1 == son){
                if(nums[bas]< nums[son]){
                    return son;
                }
                else{
                    return bas;
                }
            }

            if(mid == 0){
                return bas;
            }

            if(nums[mid] > nums[mid+1]){
                son = mid;
            }
            else{
                bas = mid;
            }
        }
        return 0;
    }
};