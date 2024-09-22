#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k , p;
    cin>>n>>k>>p;

    vector<priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>> pq(p);
    vector<int> order(n);

    for(int i = 0 ; i < n ; i++){
        int temp;
        cin>>temp;
        int fk = temp%k;
        if(fk == 0) {fk = k;}
        int fp = temp%p;
        pq[fp].push({fk,temp});
        order[i]=fp;
    }
    vector<int> newOrder(n);

    for(int i = 0 ; i < n ; i++){
        int cur = order[i];
        int buldum = pq[cur].top().second;
        pq[cur].pop();
        cout<<buldum<<" ";
    }


    return 0;
}
