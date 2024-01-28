#include <iostream>
#include <vector>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

int yap(vector<int> arr[],int node,int hangi,bool bts[]){
    if(bts[hangi]==1){
        return 0;
    }
    else{
        bts[hangi]=1;
        for(int j=0;j<arr[hangi].size();j++){
            yap(arr,node,arr[hangi][j],bts);
        }
        return 1;
    }
}

int main(){
    int node;
    int edge;
    cin>>node>>edge;
    vector<int> ar[node+1];
    bool bts[node+1];
    memset(bts,0,sizeof(bts));
    for(int i=0;i<edge;i++){
        int temp1,temp2;
        cin>>temp1>>temp2;
        ar[temp1].push_back(temp2);
        ar[temp2].push_back(temp1);
    }
    int sehir=0;
    for(int k=1;k<node+1;k++){
        sehir+=yap(ar,node,k,bts);
    }
    cout<<sehir;
    return 0;
}