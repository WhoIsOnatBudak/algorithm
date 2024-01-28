#include <iostream>
#include <vector>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int node;
    int edge;
    cin>>node>>edge;
    int ar[node+1];
    memset(ar, 0, sizeof(ar));
    for(int i=0;i<edge;i++){
        int temp1;
        int temp2;
        cin>>temp1>>temp2;
        ar[temp1]++;
        ar[temp2]++;
    }
    for(int j=1;j<node+1;j++){
        cout<<ar[j]<<" ";
    }
    return 0;
}