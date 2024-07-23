#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string cevap = strs[0];
        
        for(int i = 0; i < strs.size() ; i++){
            if(cevap.length() == 0){
                return cevap;
            }
            string n_cevap = "";
            for(int j = 0 ; j < cevap.length(); j++){
                if(strs[i][j] == cevap[j]){
                
                    n_cevap += cevap[j];
                }
                else{
                    cevap = n_cevap;
                    break;
                }
            }
        }
        return cevap;

    }
};