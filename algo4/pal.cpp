#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        string cevap = "";
        for(int i = 0; i < words.size();i++){
            for(int j = 0; j <words[i].length();j++){
                
                if(words[i][j] != words[i][words[i].length() - j-1]){
                    break;
                }


                if(j >= words[i].length() / 2 ){
                    cevap = words[i];
                    return cevap;
                }
            }
        }
        return cevap;
    }
};