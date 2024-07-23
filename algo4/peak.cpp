
#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int bas = 0;
        int son = arr.size();

        for(int i = 0 ; i < INT_MAX; i++){
            int mid = (bas+son) / 2;
            if(bas == son){
                return bas;
            }
            if(bas+1 == son){
                if(arr[bas] < arr[son]){
                    return son;
                }
                return bas;
            }
            if(arr[mid] < arr[mid-1]){
                son = mid;

            }
            else{
                bas = mid;
            }
        }
        return 0;


    }
};