//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin>>n;


    map<int,vector<pair<int,int>>> harita;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ;j++){
            int temp;
            cin>>temp;
            harita[temp].push_back({i,j});
        }
    }
    int ans = 0;
    
    for(auto p: harita){
        sort(p.second.begin(),p.second.end());
        if(p.second.size() < 2){
            continue;
        }

        for(int i = 0 ; i < p.second.size(); i++){
            int x = p.second[i].first;
            int y = p.second[i].second;



            int dist = INT32_MAX;

            for(int j = i ; j < p.second.size(); j++){
                if(j == i){
                    continue;
                }

                if(dist < abs(p.second[j].first-x)){
                    break;
                }
                dist= min(dist,abs(p.second[j].first-x)+abs(p.second[j].second-y));

            }
            for(int j = i ; j > -1; j--){
                if(j == i){
                    continue;
                }

                if(dist < abs(p.second[j].first-x)){
                    break;
                }
                
                dist= min(dist,abs(p.second[j].first-x)+abs(p.second[j].second-y));

            }

            ans+=dist;
        }

    }



    cout<<ans;


	return 0;
}
