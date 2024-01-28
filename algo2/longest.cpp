#include <iostream>
#include <vector>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int uzunluk;
    cin>>uzunluk;
    string tam;
    cin>>tam;
    int en=0;
    for(int k=0;k<uzunluk-1;k++){
        string ilk=tam.substr(0,k+1);
        string iki=tam.substr(k+1,uzunluk-1);
        int ar[ilk.size()+1][iki.size()+1];
        memset(ar,0,sizeof(ar));
        for(int i=0;i<ilk.size();i++){
            for(int j=0;j<iki.size();j++){
                if(ilk[i]==iki[j]){
                ar[i+1][j+1]=ar[i][j]+1;
                continue;
            }
            ar[i+1][j+1]=max(ar[i][j+1],ar[i+1][j]);
        }
        int a=ar[ilk.size()][iki.size()];
        a=a*2;
        if(a>en){
            en=a;
        }
    }
    }
    cout<<en;


    return 0;
}