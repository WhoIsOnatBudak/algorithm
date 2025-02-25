//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

int main() {
// write your code here
    int n,q;
    cin>>n>>q;
    vector<int> v(n);
    vector<pair<int,int>> best(n);
    best[0].first=-1;
    best[n-1].second = -1;

    for(int i = 0; i < n; i++){
        int temp;
        cin>>temp;
        v[i] =temp;
    }
    int left_max = v[0];
    int left_max_i = 0;
    int left_min = v[0];
    int left_min_i = 0;
    for(int i = 1 ; i < n ; i++){
        int cur = v[i];
        if(abs(cur-left_max) > abs(cur-left_min)){
            best[i].first = left_max_i;
        }
        if(abs(cur-left_max) < abs(cur-left_min)){
            best[i].first = left_min_i;
        }
        if(abs(cur-left_max) == abs(cur-left_min)){
            best[i].first = left_min_i;
            if(left_max_i > left_min_i){
                best[i].first = left_max_i;
            }
        }
        if(cur >= left_max){
            left_max = cur;
            left_max_i = i;
        }
        if(cur <= left_min){
            left_min = cur;
            left_min_i = i;
        }
    }
    int right_max = v[n-1];
    int right_max_i = n-1;
    int right_min = v[n-1];
    int right_min_i = n-1;
    
    for(int i = n-2; i >= 0; i--) {
        int cur = v[i];
        if(abs(cur-right_max) > abs(cur-right_min)) {
            best[i].second = right_max_i;
        }
        if(abs(cur-right_max) < abs(cur-right_min)) {
            best[i].second = right_min_i;
        }
        if(abs(cur-right_max) == abs(cur-right_min)) {
            best[i].second = right_min_i;
            if(right_max_i < right_min_i) {
                best[i].second = right_max_i;
            }
        }
        if(cur >= right_max) {
            right_max = cur;
            right_max_i = i;
        }
        if(cur <= right_min) {
            right_min = cur;
            right_min_i = i;
        }
        
    }
    while (q--) {
        int g;
        cin >> g;
        g--;  

        int left_card = best[g].first;
        int right_card = best[g].second;

        
        if (left_card == -1 && right_card != -1) {
            cout << right_card + 1 << "\n"; 
        } else if (right_card == -1 && left_card != -1) {
            cout << left_card + 1 << "\n";  
        } else if (left_card != -1 && right_card != -1) {
            if (abs(v[g] - v[left_card]) > abs(v[g] - v[right_card])) {
                cout << left_card + 1 << "\n";  
            } else if (abs(v[g] - v[left_card]) < abs(v[g] - v[right_card])) {
                cout << right_card + 1 << "\n";  
            } else {
                if (abs(g - left_card) <= abs(g - right_card)) {
                    cout << left_card + 1 << "\n";  
                } else {
                    cout << right_card + 1 << "\n";  
                }
            }
        }
    }
	return 0;
}
