//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {

    int row,col;
    cin>>row>>col;

    vector<vector<int>> grid(row);

    for(int i = 0 ; i < row ; i++){
        for(int j = 0 ; j < col ; j++){
            int temp;
            cin>>temp;

            grid[i].push_back(temp);

        }

    }

    int t;

    cin>>t;

    while(t>0){

        int fromX,fromY,tooX,tooY;
        cin>>fromY>>fromX>>tooY>>tooX;
        fromX--;
        fromY--;
        tooX--;
        tooY--;

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

        //vector<vector<int>> length(row,vector<int>(col,INT32_MAX));
        vector<vector<int>> visited(row,vector<int>(col,-1));

        pq.push({0,{fromX,fromY}});

        visited[fromY][fromX] = 1;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while(!pq.empty()) {
            int cost = pq.top().first;
            int curX = pq.top().second.first;
            int curY = pq.top().second.second;
            pq.pop();
            
            if(visited[curY][curX] == 1){
                continue;
            }
            visited[curY][curX] = 1;

            if(curX == tooX && curY == tooY) {
                cout << cost << "\n";
                break;
            }

            for(int i = 0; i < 4; i++) {
                int newX = curX + dx[i];
                int newY = curY + dy[i];
                
                if(newX >= 0 && newX < col && newY >= 0 && newY < row && visited[newY][newX] == -1) {
                    int newCost = max(cost, abs(grid[curY][curX] - grid[newY][newX]));
                    
                    pq.push({newCost, {newX, newY}});
                }
            }
        }

        t--;
    }

    

	return 0;
}
