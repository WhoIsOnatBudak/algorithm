#include <bits/stdc++.h>
using namespace std;

int main() {
    int count;
    cin >> count;
    vector<int> v;

    // Input the values
    for (int i = 0; i < count; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    // Sort the vector
    sort(v.begin(), v.end());

    
    vector<int> maxDif;

    int left = 0;
    int right = count - 1;

    while (left <= right) {
        if (left == right) {
            maxDif.push_back(v[left]);
        } else {
            maxDif.push_back(v[right]); 
            maxDif.push_back(v[left]);  
        }
        left++;
        right--;
    }
    int ans = 0;

    for (int i = 0; i < maxDif.size(); i++) {
        //ans += abs(maxDif[i]-maxDif[i+1]);
        //cout <<ans<<endl;
        cout<<maxDif[i]<<endl;
    }
    

    return 0;
}
