//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,k;

    cin>>n>>k;

    vector<int> v(n);

    for(int i = 0 ; i < n ; i++){
        int temp;
        cin>>temp;
        v[i] = temp;

    }
    int prev = v[0];
    for(int i = 1; i < n;i++){
        int cur = v[i];
        if((cur-prev)%2 == 0){
            prev = cur;
            continue;
        }
        else{
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";

	return 0;
}
