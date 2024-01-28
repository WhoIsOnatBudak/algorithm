#include <iostream>
#include <vector>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int node;
    int edge;
    cin>>node>>edge;

    vector<pair<int,pair<int,int>>> adj[node+1];
    vector<int> parent[node+1];
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> qq;

    int ar[node+1];
    memset(ar,-1,sizeof(ar));

    for(int  i = 0; i < edge ; i++){
        int temp1;
        int temp2;
        int temp3;
        int fre;
        cin >> temp1 >> temp2 >> temp3>>fre;
        pair<int,int> p;
        p.first=temp3;
        p.second=temp2;
        adj[temp1].push_back({temp3,{temp2,fre}});
        p.second=temp1;
        adj[temp2].push_back({temp3,{temp1,fre}});
    }
    //cout<<adj[3][1].second<<"\n";
    ar[1]=0;
    qq.push({0,1});
    while(!qq.empty()){
        int cost=qq.top().first;
        int curnode=qq.top().second;

        for(unsigned int k = 0; k < adj[curnode].size() ; k++){
            int neigh = adj[curnode][k].second.first;
            int mod;
            mod =(adj[curnode][k].second.second-(cost % adj[curnode][k].second.second));
            if(mod== adj[curnode][k].second.second){
                mod =0;
            }
            

            if(ar[neigh] > cost + adj[curnode][k].first+mod || ar[neigh] == -1){

                ar[neigh] = cost + adj[curnode][k].first + mod;

                qq.push({ar[neigh],adj[curnode][k].second.first});
            }

        }
        qq.pop();
    }
    cout<<ar[node]<<endl;

    


    return 0;
}