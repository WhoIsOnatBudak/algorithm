//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

//#define int long long

const int N = 1e6+5;
const int LOG = 20;

class LCA {
public:
    int parent[N][LOG] = {};
    int maxWeight[N][LOG] = {};
    int depth[N] = {};

    LCA(const vector<vector<pair<int, int>>>& tree) {
        int n = tree.size();

        dfs(0, -1, 0, 0, tree);

        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                if (parent[i][j - 1] != -1) {
                    parent[i][j] = parent[parent[i][j - 1]][j - 1];
                    maxWeight[i][j] = max(maxWeight[i][j - 1], maxWeight[parent[i][j - 1]][j - 1]);
                }
            }
        }
    }

    void dfs(int node, int par, int dep, int weight, const vector<vector<pair<int, int>>>& tree) {
        parent[node][0] = par;
        maxWeight[node][0] = weight;
        depth[node] = dep;

        for (auto [next, w] : tree[node]) {
            if (next != par) {
                dfs(next, node, dep + 1, w, tree);
            }
        }
    }

    pair<int, int> query(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);

        int maxEdge = 0;

        for (int j = LOG - 1; j >= 0; j--) {
            if (parent[u][j] != -1 && depth[parent[u][j]] >= depth[v]) {
                maxEdge = max(maxEdge, maxWeight[u][j]);
                u = parent[u][j];
            }
        }

        if (u == v) return {u, maxEdge};

        for (int j = LOG - 1; j >= 0; j--) {
            if (parent[u][j] != parent[v][j]) {
                maxEdge = max({maxEdge, maxWeight[u][j], maxWeight[v][j]});
                u = parent[u][j];
                v = parent[v][j];
            }
        }

        maxEdge = max({maxEdge, maxWeight[u][0], maxWeight[v][0]});
        return {parent[u][0], maxEdge};
    }
};


signed main() {

    int row,col;
    cin>>row>>col;

    vector<vector<int>> grid(row);


    //take input
    for(int i = 0 ; i < row ; i++){
        for(int j = 0 ; j < col ; j++){
            int temp;
            cin>>temp;

            grid[i].push_back(temp);

        }

    }


    //find compCount
    vector<int> compID(row*col);
    int compCount = 0;
    vector<vector<int>> visited(row,vector<int>(col,0));

    for(int i = 0 ; i < row ; i++){
        for(int j = 0 ; j < col; j++){
            if(visited[i][j] == 0){
                int cur = grid[i][j];
                queue<pair<int,int>> q;
                q.push({i,j});
                while(!q.empty()){
                    int curY = q.front().first;
                    int curX = q.front().second;
                    q.pop();

                    if(visited[curY][curX] == 1){
                        continue;
                    }
                    visited[curY][curX] = 1;

                    compID[curY*col + curX] = compCount;


                    int dx[] = {-1, 1, 0, 0};
                    int dy[] = {0, 0, -1, 1};


                    for(int i = 0; i < 4; i++) {
                        int newX = curX + dx[i];
                        int newY = curY + dy[i];
                        
                        if(newX >= 0 && newX < col && newY >= 0 && newY < row && visited[newY][newX] == 0) {
                            if(grid[newY][newX] == grid[curY][curX]){
                                q.push({newY,newX});
                            }
                        }
                    }
                }
                compCount++;
            }

            
        }
    }
    //cout<<compCount<<"\n";
    /*for(int i = 0 ; i < row; i++){
        for(int j = 0 ; j < col; j++){
            cout<<compID[i*col+j]<<" ";
        }
        cout<<"\n";
    }*/


    priority_queue<pair<int, pair<pair<int, int>, pair<int, int>>>, vector<pair<int, pair<pair<int, int>, pair<int, int>>>>, greater<>> pq;

    vector<vector<pair<int,int>>> tree(compCount);
    //vector<int> used(row*col);
    
    pq.push({0,{{-1,-1},{0,0}}});

    vector<vector<int>> visited2(row,vector<int>(col,-1));
    

    while(!pq.empty()){
        int cost = pq.top().first;
        int fromY = pq.top().second.first.first;
        int fromX = pq.top().second.first.second;

        int toY = pq.top().second.second.first;
        int toX = pq.top().second.second.second;



        pq.pop();
        if(visited2[toY][toX] == 1){
            continue;
        }
        visited2[toY][toX] = 1;
        

        if(fromX != -1 && compID[fromY*col +fromX] !=compID[toY*col +toX]){
            tree[compID[fromY*col +fromX]].push_back({compID[toY*col +toX],cost});
            tree[compID[toY*col +toX]].push_back({compID[fromY*col +fromX],cost});
            
        }
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for(int i = 0; i < 4; i++) {
            int newX = toX + dx[i];
            int newY = toY + dy[i];
                
            if(newX >= 0 && newX < col && newY >= 0 && newY < row && visited2[newY][newX] == -1) {
                pq.push({abs(grid[toY][toX]-grid[newY][newX]),{{toY,toX},{newY,newX}}});
            }
        }


    }
    /*
    for(int i = 0 ; i < compCount; i++){
        for(int j = 0 ; j < tree[i].size();j++){
            cout<<"from : "<<i <<" to: "<<tree[i][j].first<<" cost: "<<tree[i][j].second<<"\n";
        }
    }*/

    
    LCA lca(tree);

    int t;
    cin>>t;
    while(t--){
        int startX,startY,endX,endY;

        cin>>startY>>startX>>endY>>endX;

        startX--;
        startY--;
        endX--;
        endY--;

        int startID = compID[startY*col + startX];
        int endID = compID[endY*col + endX];

        auto [lcaNode, maxCost] = lca.query(startID,endID);
        cout<<maxCost<<"\n";
        //cout<<startID<<"" <<endID<<"\n";
    }
    

	return 0;
}
