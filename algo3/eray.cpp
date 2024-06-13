#include <bits/stdc++.h>

using namespace std;

int main(){
    int x,y;

    cin>>x>>y;

    vector<int> CT(x+1,0);
    vector<pair<int,pair<int,int>>> map;
    vector<int> visit(x+1,0);

    for(int i = 0 ; i < x ; i++){
        string temp;
        cin>>temp;
        if(temp == "CT"){
            CT[i+1]=1;
        }
    }

    for(int i = 0 ; i < y; i++){
        int f;
        int s;
        int w;
        cin>>f>>s>>w;
        map.push_back({w,{f,s}});



    }

    int result=0;

    sort(map.begin(),map.end());

    /*for(int i = 0 ; i < CT.size(); i++){
        cout<<CT[i]<<"\n";
    }*/

    int edge = 0;


    int hop = 0;
    int lw = map.front().first;
    int devam = 0;
    int lw2 = 0;
    bool gel = true;
    
    while(gel){
        int say = 0;
        for(int i = hop; i < map.size();i++){
            say++;
            if(i+1 == map.size()){
                gel = false;
            }
            
            if(map[i].first != lw ){
                devam = i;
                lw2 =  map[i].first;
                break;
            }
            if(i+1 == map.size()){
                gel = false;
                devam = i+1;
            }
            int ilk = map[i].second.first;
            int iki = map[i].second.second;
            if(visit[ilk] && visit[iki]){
                continue;
            }
            else if(CT[ilk] != CT[iki]){
                continue;
            }
            visit[ilk]=1;
            visit[iki]=1;
            cout<<map[i].second.first<<" "<<map[i].second.second<<"\n";

            edge++;


        }
        for(int i = hop; i < hop+say;i++){
            
            int ilk = map[i].second.first;
            int iki = map[i].second.second;
            if(visit[ilk] && visit[iki]){
                continue;
            }


            visit[ilk]=1;
            visit[iki]=1;
            
            result++;
            cout<<map[i].second.first<<" "<<map[i].second.second<<"\n";
            edge++;

        }

        lw = lw2;
        hop = devam;
    }



    //cout<<edge<<endl;
    if(edge != x-1){
        cout<<-1;
        return 0;
    }
    cout<<result;


}