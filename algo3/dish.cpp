#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> taste;

    for(int i = 0 ; i < n;i++){
        int t,s;
        cin>>t>>s;
        taste.push_back({t,s});


    }
    sort(taste.begin(), taste.end());

    vector<int> v;

    /*int en=1;

    for(int i = 0 ; i < n; i++){
        for (int j = i+1; j < n; j++)
        {
            if(taste[i].second <= taste[j].second){
                if(v[j] < v[i]+1){
                    v[j] = v[i]+1;
                }
                if(v[j]>en){
                    en= v[j];
                }

            }
        }
        
    }*/
    for(int i = 0 ; i < n ; i++){
        int sour = taste[i].second;

        auto it = upper_bound(v.begin(),v.end(),sour);

        if(it == v.end()){
            v.push_back(sour);
        }
        else{
            *it = sour;
        }

        }
    cout<<v.size();
    

    
    
}