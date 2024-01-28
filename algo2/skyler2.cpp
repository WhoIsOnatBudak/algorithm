#include <iostream>
#include <vector>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

int main(){
    long coin;
    long target;
    cin>>coin>>target;
    int ar[target+1];
    vector<int> coins;
    memset(ar,0,sizeof(ar));
    for(int i=0;i<coin;i++){
        int temp;
        cin>>temp;
        coins.push_back(temp);
    }
    ar[0]=1;
    for(int j=1;j<target+1;j++){
        for(int k=0;k<coins.size();k++){
            if(j-coins[k]>=0){
                ar[j]=(ar[j]+ar[j-coins[k]])%1000000007;
            }
        }
    }
    cout<<ar[target];

    return 0;
}