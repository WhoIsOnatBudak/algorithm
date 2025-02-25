//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

long long MOD = 1000000007;





long long mod_pow(long long x, long long y, long long mod) {
    long long res = 1;
    while (y > 0) {
        if (y & 1) {
            res = res * x % mod;
        }
        x = x * x % mod;
        y >>= 1;
    }
    return res;
}


long long comb(long long n, long long k) {

    if ( k == n) return 1;
    
    k = min(k, n - k);


    long long fact_n = 1, fact_k = 1, fact_n_k = 1;

    
    for (long long i = 1; i <= n; ++i) {
        fact_n = fact_n * i % MOD;
        if (i == k) fact_k = fact_n;  
        if (i == n - k) fact_n_k = fact_n;  
    }

    
    long long inv_fact_k = mod_pow(fact_k, MOD - 2, MOD);
    long long inv_fact_n_k = mod_pow(fact_n_k, MOD - 2, MOD);

    
    return fact_n * inv_fact_k % MOD * inv_fact_n_k % MOD;
}


int main() {

    //only keep the fact n and inverse factorial k and inverse factorial n-k;

    //the max is 93623149 so it varies from 1 to 93623148 and 2 again.

    //the rooms less than k is usesless.

    //rooms k to 93623149

    long long k;
    cin>>k;
    long long ans;

    ans = comb(93623149, k + 1);

    // combination 93623149 ,k+1; == k,k -k+1,k - k+2,k --- 93623148,k;




    if(k==1){
        ans+=2;
    }
    if(k==2){
        ans+=1;
    }
    cout<<ans;


	return 0;
}
