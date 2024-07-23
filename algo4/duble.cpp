
#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int bas = 0;
        int son = nums.size() -1 ;

        for(int i = 0 ; i < INT_MAX; i++){
            int mid = (bas + son) / 2;
            if(mid == 0){
                return nums[0];
            }

            if(bas+1 == son){
                if(nums[bas]> nums[son]){
                    return nums[bas];
                }
                else{
                    return nums[son];
                }
            }

            if((mid % 2 == 0)){
                if(nums[mid+1] == nums[mid]){
                    bas = mid;
                }
                else{
                    son = mid;
                }    
            }
            else{
                if(nums[mid] == nums[mid-1]){
                    bas= mid;
                }
                else{son = mid;}
            }
        }
        return 0;


    }
};