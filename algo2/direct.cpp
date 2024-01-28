#include <iostream>
#include <vector>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int node;
    int edge;
    int p=0;
    cin>>node>>edge;
    vector<int> ar[node+1];
    vector<int> fd[node+1];
    map<pair<int,int>,bool> ma;
    memset(ar,0,sizeof(ar));
    for(int i=0;i<edge;i++){
        int temp1,temp2;
        cin>>temp1>>temp2;
        pair<int,int> pa;
        pa.first=temp1;
        pa.second=temp2;
        if(ma[pa]==1){
            continue;
        }
        ma[pa]=1;
        ar[temp1].push_back(temp2);
    }
    for (int j = 1; j < node+1; j++)
    {   
        for (int k = 0; k < ar[j].size(); k++)
        {
            int elemanSayisi = count(ar[ar[j][k]].begin(), ar[ar[j][k]].end(), j);
            if(elemanSayisi>0){
                p++;
                if(j<ar[j][k]){
                    fd[j].push_back(ar[j][k]);
                }
            }
        }
        
    }
    cout<<p/2<<"\n";
    for(int o=1;o<node+1;o++){
        sort(fd[o].begin(),fd[o].end());
        for(int p=0;p<fd[o].size();p++){
            cout<<o<<" "<<fd[o][p]<<"\n";
        }
    }
    
}