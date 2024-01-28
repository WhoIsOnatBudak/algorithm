#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    long balon=0;
    long mal=0;
    //long onceki=0;
    long current=0;
    vector<long> v;
    cin>>balon;
    cin>>mal;

    for(int i=0;i<balon;i++){
        cin>>current;
        long size=v.size();
        for(int j=0;j<size;j++){
            v.push_back(v[j]+current);
        }
        v.push_back(current);
    }
    
    for(int k=0;k<mal;k++){
        long it=0;
        cin>>current;
        for(unsigned int u=0;u<v.size();u++){
            if(v[u]==current){
                it=1;
                break;
            }
        }
        if(it==1){
            cout<<"yes"<<"\n";
        }
        else if(it==0){
            cout<<"no"<<"\n";
        }
    }
}