
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int bas = 1;
        int son = *max_element(piles.begin(),piles.end());
        
        for(int i = 0; i < INT_MAX ; i++){
            int mid = (son + bas)/2;
            int t = 0;
            int c = 1;

            if(bas==son){
                return bas;
            }
            

            if(bas+1 == son){
                for(int j = 0 ; j < piles.size(); j++){
                    int temp2 = piles[j];
                    if(temp2% mid == 0){
                        t += temp2/mid;
                    }
                    else{
                        t += (temp2/mid) +1;
                    }
                }
                if(t <= h){
                    return bas;
                }
                else{
                    return son;
                }
            }

            for(int j = 0 ; j < piles.size(); j++){
                int temp = piles[j];
                if(temp% mid == 0){
                    t += temp/mid;
                }
                else{
                    t += (temp/mid) +1;
                }
            }
            if(t <= h){
                son = mid;
            }
            else{
                bas = mid;
            }
        }


        return 0;
    }
    
};