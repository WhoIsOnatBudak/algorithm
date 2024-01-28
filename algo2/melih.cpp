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
    int bak[node+1];
    memset(bak,0,sizeof(bak));
    bak[1]=1;
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
        ar[temp2].push_back(temp1);
    }
    int cur=1;
    int pre_min=1;
    cout<<1<<" ";
    for(int k=1;k<node+1;k++){
        sort(ar[k].begin(),ar[k].end());
    }
    while(true){
        if(ar[cur].size()>0){
            while(bak[ar[cur].back()]==1&&ar[cur].size()>0){
                ar[cur].pop_back();
            }
        }
        if(ar[cur].size()==0){
            while(bak[pre_min]==1){
                pre_min++;
                if(pre_min>node){
                    return 0;
                }
            }
            bak[pre_min]=1;
            cur=pre_min;
            cout<<cur<<" ";
        }
        else if(ar[cur].size()>0){
            bak[ar[cur].back()]=1;
            cur=ar[cur].back();
            cout<<cur<<" ";
        }
        
    }    
}