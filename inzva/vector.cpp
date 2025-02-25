// Brace your keyboard
// inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

int main() {
    long count, dimen;
    cin >> count >> dimen;

    vector<vector<int>> v;

    for(int i = 0 ; i < count ; i++){
        vector<int> temp;
        for(int j = 0; j < dimen; j++){
            int x;
            cin>>x;
            temp.push_back(x);
        }
        v.push_back(temp);
    }
    vector<int> ans;
    for(int i = 0 ; i <dimen; i++){
        int y;
        cin>>y;
        ans.push_back(y);
    }

    for(long i = 0 ; i < 1<<count ; i++){
        vector<int> sum(dimen,0);
        for(int j = 0 ; j < count;j++){
            if(i & (1 << j)){
                for(int k = 0 ; k < dimen; k++){
                    sum[k] += v[j][k];
                }
            }   
        }
        if (sum == ans) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
    return 0;
}
