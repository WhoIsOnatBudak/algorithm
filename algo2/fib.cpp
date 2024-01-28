#include <iostream>
#include <vector>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int tur;
    cin>>tur;
    long long mod = 1000000007;
    int ar[tur+1];
    ar[0]=0;
    ar[1]=1;
    ar[2]=1;
    if(tur>2){
        for(int i=3;i<=tur;i++){
            ar[i]=(ar[i-1]+ar[i-2])% mod;
        }
    }
    cout<<ar[tur];
}