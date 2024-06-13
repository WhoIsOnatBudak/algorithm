#include <bits/stdc++.h>

using namespace std;

int main() {
    long x,y;
    cin>>x>>y;
    int mod = 1000000007;
    vector<long> v(x+1,0);
    v[0]=1;
    vector<int> yemek;

    

    int sum = 1; 

    for(int i = 1 ; i < y; i++){
        v[i] = sum%mod;
        sum += v[i]%mod;
    }

    if(y == x){
        v[y] = (sum*2)%mod;
        cout<<v[y];
        return 0;
    }

    for(int i = y ; i < x ; i++){
        v[i] = sum%mod;
        sum += v[i]%mod;
        sum -= v[i-y]%mod;
        if(i-y-2 > -1){
            sum -= v[i-y-2]%mod;    
        }
        if(i-y-1 > -1){
            sum += v[i-y-1]%mod;    
        }
    }
    sum = 0;
    for(int i = 1 ; i < y+1;i++){
        sum+=v[x-i];
    }

    if(x >= y+2 ){
        v[x] = ((sum * 2)%mod + v[x-y-2]%mod +v[x-y-1]%mod)%mod;
    }
    else{
        v[x] = ((sum * 2)%mod + v[x-y-1]%mod)%mod;
    }

    
    //for(int i = 0 ;i<v.size(); i++){
                    cout<<v[x]%mod<<"\n";
    //}
}