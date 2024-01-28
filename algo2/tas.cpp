#include <iostream>
#include <vector>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int tas;
    cin>>tas;
    vector<int> v;
    int toplam=0;
    for(int i=0;i<tas;i++){
        int bir;
        cin>>bir;
        toplam+=bir;
        v.push_back(bir);
    }
    if(toplam%2!=0){
        cout<<"false";
        return 0;
    }
    int ar[(toplam/2)+1];
    memset(ar,0,sizeof(ar));
    toplam=toplam/2;
    ar[0]=1;
    for(int j=0;j<v.size();j++){
        for(int k=toplam+1;k>=v[j];k--){
            ar[k]=ar[k] || ar[k-v[j]] ;
        }
    }
    if(ar[toplam]==1){
        cout<<"true";
        return 0;
    }
    cout<<"false";
    return 0;
}