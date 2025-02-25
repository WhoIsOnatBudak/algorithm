//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

int main() {


    int n;
    int m;
    cin>>n>>m;

    vector<vector<pair<pair<int,int>,pair<int,int>>>> fl(n, vector<pair<pair<int,int>,pair<int,int>>>(n,{{-1,-1},{-1,-1}}));
    vector<vector<char>> grid(n, vector<char>(n));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            char temp;
            cin>>temp;
            grid[i][j] = temp;
            
        }
    }
    for(int i = 0 ; i < m ; i++){
        int x;
        int y;
        cin>>x>>y;
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{x,y}});
        vector<vector<int>> visit(n,vector<int>(n,0));
        while(!q.empty()){
            
            int cost = q.front().first;
            int xq = q.front().second.first;
            int yq = q.front().second.second;
            int flag = 0;

            if(xq>= 0 && yq>=0 && xq < n && yq < n && visit[xq][yq] == 1){
                q.pop();
                continue;
            }

            if(xq>= 0 && yq>=0 && xq < n && yq < n && grid[xq][yq] != '#'){
                visit[xq][yq] =1;
                flag = 1;
            }

            if(xq>= 0 && yq>=0 && xq < n && yq < n && grid[xq][yq] != '#' && (fl[xq][yq].first.second == -1 || cost < fl[xq][yq].first.second)){
                fl[xq][yq].first.first = i+1;
                fl[xq][yq].first.second = cost;
                flag = 1;
                
            }
            if(xq>= 0 && yq>=0 && xq < n && yq < n && grid[xq][yq] != '#' && (fl[xq][yq].second.second == -1 || cost > fl[xq][yq].second.second)){
                fl[xq][yq].second.first = i+1;
                fl[xq][yq].second.second = cost;
                flag = 1;
                
            }
            q.pop();
            if(flag){
                q.push({cost+1,{xq+1,yq}});
                q.push({cost+1,{xq-1,yq}});
                q.push({cost+1,{xq,yq-1}});
                q.push({cost+1,{xq,yq+1}});
            }
            
        }
    }
    int qu;
    cin>>qu;
    for(int i = 0 ; i < qu ; i++){
        int mx;
        int my;
        cin>>mx>>my;
        cout<<fl[mx][my].first.first<<" "<<fl[mx][my].second.first<<"\n";
    }

	return 0;
}
