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
    for(int j=0;j<coins.size();j++){
        for(long k=1;k<target+1;k++){
            if((k-coins[j])>-1){
                //cout<<coins[j]<<endl;
                ar[k]=((ar[k]+ar[k-coins[j]]))%1000000007;
            }
        }
    }
    cout<<ar[target]%1000000007;

    return 0;
}