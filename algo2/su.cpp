#include <iostream>
#include <vector>
#include <math.h>
#include <bits/stdc++.h>
#include <unordered_map> 

using namespace std;

int main(){
    int wall;
    int mall;
    cin>>wall;
    cin>>mall;
    unordered_map<int,pair<int,int>> map;
    for(int i=0;i<wall;i++){
        pair<int,int> temp;
        cin>>temp.first;
        temp.second=i+1;
        map[temp.first].first++;
        map[temp.first].second=temp.second;
    }
    for(int j=0;j<mall;j++){
        int temp;
        cin>>temp;
        if(map[temp].first==0){
            cout<<-1<<"\n";
        }
        else if(map[temp].first==1){
            cout<<map[temp].second<<"\n";
        }
        else if(map[temp].first>1){
            cout<<-1<<"\n";
        }
    }

}