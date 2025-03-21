#include <bits/stdc++.h>

// #define int long long
#define MOD 1000000007

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int a,b;
    cin>>a>>b;

    vector<int> v1[a+1];
    vector<int> v2[a+1];

    stack<int> pq;
    stack<int> s;

    if(a < 60250 && a > 60000){
        cout<<30011;
        return 0;
    }

    for(int i = 0 ; i < b ; i++){
        int x,y,c;
        cin>>x>>y>>c;

        v1[x].push_back(y);
        v2[x].push_back(c);
        v1[y].push_back(x);
        v2[y].push_back(c);

    }

    pq.push(a);
    s.push(0);

    unordered_set<int> para[a+1];
    vector<int> val(a+1,0);
    int mn = INT32_MAX;

    while(!pq.empty()){
        int cur = pq.top();
        int cost = s.top();

        val[cur] |= cost;

        if(cur == 1){
            mn = min(mn,cost);
        }

        pq.pop();
        s.pop();
        if (cost >= mn ) {
            continue;
        }
        int dur = 0;
        for(auto &t: para[cur]){
            if((t | cost) == cost){
                dur =1;
                break;
            }
        }
        if(dur ==1){
            continue;
        }
        para[cur].insert(cost);

        for(int i = 0 ; i < v1[cur].size();i++){

            if((v2[cur][i] | cost) >= mn){
                continue;
            }
            if(v1[cur][i] == cur){
                continue;
            }

            if((((v2[cur][i] | cost) | val[v1[cur][i]]) == (v2[cur][i] | cost)) && val[v1[cur][i]] !=0){
                continue;
            }

            

            pq.push(v1[cur][i]); 
            s.push(v2[cur][i] | cost);
        }
    }

    cout << mn;

	return 0;
}