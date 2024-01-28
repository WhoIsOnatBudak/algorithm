#include <iostream>
#include <vector>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int node;
    int edge;
    cin>>node;
    cin>>edge;
    bool ar[node+1][node+1];
    memset(ar, 0, sizeof(ar));
    vector<int> ar2[node+1];
    for(int i = 0; i< edge; i++){
        int temp1,temp2;
        cin>>temp1;
        cin>>temp2;
        ar[temp1][temp2]=1;
        ar[temp2][temp1]=1;
        ar2[temp1].push_back(temp2);
        ar2[temp2].push_back(temp1);
    }
    for(int j=0;j<node;j++){
        sort(ar2[j+1].begin(),ar2[j+1].end());
        for(int k=0;k<ar2[j+1].size();k++){
            cout<<ar2[j+1][k]<<" ";
        }
        cout<<"\n";
    }
    for(int s=0;s<node;s++){
        for(int l=0;l<node;l++){
            cout<<ar[s+1][l+1]<<" ";
        }
        cout<<"\n";
    }
}