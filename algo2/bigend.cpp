#include <iostream>
#include <vector>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int node;
    int edge;
    cin>>node>>edge;

    vector<pair<int,int>> adj[node+1];
    vector<int> parent[node+1];
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> qq;

    int ar[node+1];
    memset(ar,-1,sizeof(ar));

    for(int  i = 0; i < edge ; i++){
        int temp1;
        int temp2;
        int temp3;
        cin >> temp1 >> temp2 >> temp3;
        pair<int,int> p;
        p.first=temp3;
        p.second=temp2;
        adj[temp1].push_back(p);
        p.second=temp1;
        adj[temp2].push_back(p);
    }
    //cout<<adj[3][1].second<<"\n";
    ar[node]=0;
    qq.push({0,node});
    while(!qq.empty()){
        int cost=qq.top().first;
        int curnode=qq.top().second;

        for(unsigned int k = 0; k < adj[curnode].size() ; k++){
            int neigh = adj[curnode][k].second;

            if(ar[neigh] == cost + adj[curnode][k].first){
                parent[neigh].push_back(curnode);
            }

            else if(ar[neigh] > cost + adj[curnode][k].first || ar[neigh] == -1){

                ar[neigh] = cost + adj[curnode][k].first;


                parent[neigh].clear();
                parent[neigh].push_back(curnode);

                qq.push({ar[neigh],adj[curnode][k].second});
            }

        }
        qq.pop();
    }
    int start=1;
    
    while(start!=node){
       if(parent[start].size()==0){
        cout<<-1;
        return 0;
       }
       sort(parent[start].begin(),parent[start].end()); 
       start=parent[start][0];
    }
    start =1;
    cout<<1<<" ";
    while (start != node){
        sort(parent[start].begin(),parent[start].end());
        cout<<parent[start][0]<<" "; 
        start=parent[start][0];
    }
    


    return 0;
}