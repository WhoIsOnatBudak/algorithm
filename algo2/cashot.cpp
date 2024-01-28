#include <iostream>
#include <vector>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;




long don(vector<vector<int>> &ve,int z,int n,long* dp){
    if(dp[z]!=0){
        return dp[z];
    }
    long en=0;
    for(int i=0;i<n;i++){
        int ooo=pow(2,i);
        if(z == (ooo | z)){
            continue;
        }
        if(__builtin_popcount(z)==(n-1)){
            return ve[n-1][n-i-1];
        }
        long cur=don( ve , ooo | z ,n ,dp)+ve[__builtin_popcount(z)][n-i-1];
        if(cur>en){
            en = cur;
        }
    }
    dp[z]=en;
    return en;
}

int main(){
    int n=0;
    cin>>n;
    long guc=pow(2,n);
    long dp[guc+1];
    memset(dp,0,sizeof(dp));
    vector<vector<int>> v(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int temp;
            cin>>temp;
            v[i][j]=temp;
        }
    }
    int zero=0;
    cout<<don(v,zero,n,dp)<<endl;
    
    return 0;
}