#include <iostream>
#include <vector>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

int main(){
    string ilk;
    string iki;
    cin>>ilk;
    cin>>iki;
    vector<char> v;
    int say=0;
    int start=0;

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
    }

    cout<<ar[ilk.size()][iki.size()];
    return 0;
}