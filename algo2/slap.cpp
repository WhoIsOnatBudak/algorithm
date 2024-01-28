#include <iostream>
#include <vector>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int uzunluk;
    cin>>uzunluk;
    int ar[uzunluk+1];
    vector<int> coins;
    coins.push_back(2);
    coins.push_back(3);
    memset(ar,0,sizeof(ar));
    ar[0]=1;
    if(uzunluk==1){
        cout<<2;
        return 0;
    }
    if(uzunluk==2){
        cout<<3;
        return 0;
    }
    int toplam=0;
    for(int j=1;j<uzunluk+1;j++){
        for(int k=0;k<coins.size();k++){
            if(j-coins[k]>=0){
                ar[j]=(ar[j]+ar[j-coins[k]])%1007;
            }
        }
    }
    toplam+=ar[uzunluk];
    memset(ar,0,sizeof(ar));
    ar[0]=1;
    for(int j=1;j<uzunluk;j++){
        for(int k=0;k<coins.size();k++){
            if(j-coins[k]>=0){
                ar[j]=(ar[j]+ar[j-coins[k]])%1007;
            }
        }
    }
    toplam+=ar[uzunluk-1]*2;
    memset(ar,0,sizeof(ar));
    ar[0]=1;
    for(int j=1;j<uzunluk-1;j++){
        for(int k=0;k<coins.size();k++){
            if(j-coins[k]>=0){
                ar[j]=(ar[j]+ar[j-coins[k]])%1007;
            }
        }
    }
    toplam+=ar[uzunluk-2];
    cout<<toplam%1007;

    return 0;
}