#include <iostream>
#include <vector>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

int who(vector<int> ar[],int look){
    int count=1;
    if(ar[look].size()==1&&look!=1){
        return 1;
    }
    if(ar[look].size()==1){
        count+=who(ar,ar[look][0]);
    }
    for (int i = 1; i < ar[look].size(); i++)
    {
        count+=who(ar,ar[look][i]);
    }
    return count;
    
}

int main(){
    int siz;
    cin>>siz;
    vector<int> ar[siz+1];
    for(int i=2;i<siz+1;i++){
        int temp;
        cin>>temp;
        ar[temp].push_back(i);
        ar[i].push_back(temp);
    }
    int as;
    cin>>as;
    int cevap=who(ar,as);
    cout<<cevap;
}