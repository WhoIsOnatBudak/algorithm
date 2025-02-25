//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

int main() {
    int count;
    cin>>count;
    int t=2;
    vector<int> v;

    for(int i = 0 ; i < count ; i++){
        int temp;
        cin>>temp;
        v.push_back(temp);

    }
    sort(v.begin(),v.end());
    int lastcur = 1;
    for(int i = 0 ; i < count; i++){
        int cur = v[i];
        if(t==0){
            cout<<"NO";
            return 0;
        }
        if(cur != lastcur){
            t*= pow(2,cur-lastcur);
            t--;
        }
        if(cur == lastcur){
            t--;
            if(t < 0){
                cout<<"NO";
                return 0;
            }
        }
        lastcur = cur;
    }
    cout<<"YES";

	return 0;
}
