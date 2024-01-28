#include <iostream>
#include <vector>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;



int main(){
    int node;
    int edge;

    cin>>node>>edge;

    vector<int> ar[node+1];
    int degre[node+1];
    int say=0;
    vector<int> last;
    memset(degre,0,sizeof(degre));
    priority_queue<int,vector<int>,greater<>> qq;
    for(int i=0;i<edge;i++){
        int temp1;
        int temp2;
        cin>>temp1>>temp2;
        ar[temp2].push_back(temp1);
        degre[temp1]++;
    }
    for(int j=1;j<node+1;j++){
        if(degre[j]==0){
            //cout<<j<<endl;
            qq.push(j);
            //say++;
        }
    }
    while(!qq.empty()){
        int top =qq.top();
        last.push_back(top);
        qq.pop();
        for(int k=0;k<ar[top].size();k++){
            if(--degre[ar[top][k]]==0){
                qq.push(ar[top][k]);
                //say++;
            }
        }
        say++;
    }
    if(say!=node){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    for (int as: last){
        cout<<as<<" ";
    }

    return 0;
}