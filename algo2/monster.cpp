#include <iostream>
#include <vector>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

int main(){
    long long mon;
    cin>>mon;
    long long cenk;
    cin>>cenk;
    vector<long long> v;
    for(long long i=0;i<mon;i++){
        long long temp;
        cin>>temp;
        v.push_back(temp);
    }
    sort(v.begin(),v.end());
    long long say=1;
    

    while(cenk>0&&mon>0){
        cenk-=v[say-1];
        mon--;
        if(cenk<=0){
            cout<<say;
        }
        say++;
        if(say==v.size()){
            cout<<"EV";
        }
    }
    return 0;
}