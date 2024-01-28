#include <iostream>
#include <vector>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int balon;
    int kac;
    cin>>balon>>kac;
    vector<int> ar[balon+1];
    vector<int> color(balon+1,0);
    memset(ar,0,sizeof(ar));
    //memset(ma,0,sizeof(ma));
    for(int i=1;i<kac+1;i++){        
        int temp;
        int temp2;
        cin>>temp>>temp2;
        ar[temp2].push_back(temp);
        ar[temp].push_back(temp2);
    }
    color[1]=2;
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(int j=0;j<ar[cur].size();j++){
            if(color[cur]==color[ar[cur][j]]){
                cout<<"No";
                return 0;
            }
            else if(color[cur]==2&&color[ar[cur][j]]==0){
                color[ar[cur][j]]=3;
                q.push(ar[cur][j]);
            }
            else if(color[cur]==3&&color[ar[cur][j]]==0){
                color[ar[cur][j]]=2;
                q.push(ar[cur][j]);
            }
        }
    }
    cout<<"Yes";
    return 0;
}