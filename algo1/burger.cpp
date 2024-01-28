#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <vector>
#include <numeric>

using namespace std;

int main(){
    unordered_map<long long,bool> change1;
    long long a;
    long long b;
    cin>>a>>b;
    vector<long long> arA(a);
    vector<long long> arB(b);
    vector<long long> v;
    for(long long i=0;i<a;i++){
        long long oku=0;
        cin>>oku;
        change1[oku]=true;
        arA[i]=oku;
    }
    vector<long long> puan;
    long long count=0;
    for(long long j=0;j<b;j++){
        long long okur=0;
        cin>>okur;
        count+=okur;
        if(change1[okur]==true){
            v.push_back(okur);
            puan.push_back(count);
            count=0;
        }
        if(j==b-1){
            puan.push_back(count);
        }
        arB[j]=okur;
    }
    long long pp=0;
    count=0;
    for(long long k=0;k<a;k++){
        count+=arA[k];
        if(v[pp]==arA[k]){
            if(count>puan[pp]){
                puan[pp]=count;
            }
            count=0;
            pp++;
        }
        if(k==a-1){
            if(count>puan[pp]){
                puan[pp]=count;
            }
        }
    }
    count=0;
    for(long long as:puan){
        count+=as;
    }
    cout<<count%1000000007;
    
    



}