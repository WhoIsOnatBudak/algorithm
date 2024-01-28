#include <iostream>
#include <vector>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int say;
    cin>>say;
    int ar[say+1];
    memset(ar, 0, sizeof(ar));
    for(int i=2;i<say+2;i++){
        int temp;
        cin>>temp;
        ar[i]=ar[temp]+1;
    }
    int ta;
    cin>>ta;
    cout<<ar[ta];
    return 0;
}