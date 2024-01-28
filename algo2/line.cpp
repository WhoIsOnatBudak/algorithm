#include <iostream>
#include <vector>
#include <math.h>
#include <bits/stdc++.h>
#include <unordered_map>
#include <stack> 

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int range;
    cin>>range;
    int guess;
    cin>>guess;
    //unordered_map<int,bool> map;
    bitset<1000000001> bits;
    for(int i=0;i<range;i++){
        long temp1;
        long temp2;
        cin>>temp1;
        cin>>temp2;
        while(temp1<=temp2){
            bits[temp1]=true;
            temp1++;
        }
    }
    for(int j=0;j<guess;j++){
        int g=0;
        cin>>g;
        if(bits[g]){
            cout<<"Yes"<<"\n";
        }
        else{cout<<"No"<<"\n";}
    }


}