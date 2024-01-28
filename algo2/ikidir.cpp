#include <iostream>
#include <vector>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

int main(){
    long say=0;
    cin>>say;
    vector<long long> prev;
    prev.push_back(0);
    long min=INT64_MAX;
    for(int i=0;i<say;i++){
        long long temp;
        cin>>temp;
        long long size=prev.size();
        for(int k=0;k<size;k++){
            if(min>abs(prev[k]+temp)){
                min=abs(prev[k]+temp);
            }
            prev.push_back(prev[k]+temp);
            

        }

    }
    /*for(int y=0;y<prev.size();y++){
        cout<<prev[y]<<"\n";
    }*/
    cout<<min;
    return 0;
}