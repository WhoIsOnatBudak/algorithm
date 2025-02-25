//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //cout.tie(nullptr);
    int count;
    cin>>count;

    vector<pair<int,int>> v(count);

    pair<int,int> dest;
    cin>>dest.first>>dest.second;

    for(int i = 0; i < count ; i++){
        int tempX;
        int tempY;
        cin>>tempX>>tempY;

        v[i]={tempX,tempY};
    }
    vector<pair<int,int>> v1;

    vector<pair<int,int>> v2;

    for(int i = 0 ; i < count/2 ; i++){
        v1.push_back(v[i]);
    }

    for(int i = count/2 ; i < count ; i++){
        v2.push_back(v[i]);
    }

    using Sum = pair<int,int>;

    map<Sum,unordered_map<int,int>> m1;

    map<Sum,unordered_map<int,int>> m2;    

    for(int i = 0 ; i < ( 1 << v1.size()); i++){

        Sum sum = {0,0};
        
        int ones = __builtin_popcount(i);

        for(int j = 0 ; j < v1.size() ; j++){
            if((i & (1 << j)) == 0){
                continue;
            }
            
                sum.first += v1[j].first;
                sum.second += v1[j].second;
            
        }

        m1[sum][ones]++;

    }

    for(int i = 0 ; i < ( 1 << v2.size()); i++){

        pair<int,int> sum = {0,0};

        int ones = __builtin_popcount(i);

        for(int j = 0 ; j < v2.size() ; j++){
            if((i & (1 << j)) == 0){
                continue;
            }
            
                sum.first += v2[j].first;
                sum.second += v2[j].second;
            
        }

        m2[sum][ones]++;
    }

    vector<int> ans(count+1,0);

    for (auto const& [key, value] : m1)
    {
        int searchX = key.first;
        int searchY = key.second;

        auto &bak = value;

        if(m2.count({dest.first-searchX, dest.second - searchY})){

            for(auto const& [key2,value2] : bak){
                
                    int curP = value2;

                    
                    

                    //if(m2.count({dest.first-searchX, dest.second - searchY})){


                        auto &gez = m2[{dest.first-searchX, dest.second - searchY}];


                        for(auto const& [key3,value3] : gez){

                            
                                ans[key2+key3] +=  value2*value3;
                            
                        }
                    //}
                        
                
            }
        } 

        
    }

    for(int i = 1 ; i < count +1; i++){
        cout<<ans[i]<<"\n";
    }



    

    return 0;
}
