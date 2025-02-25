#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

const long long MOD = 1000000007;
const int MAX_N = 1000005; 

vector<long long> power_of_two(MAX_N);
vector<long long> factorial(MAX_N);
vector<long long> inv_factorial(MAX_N);


//https://www.geeksforgeeks.org/modular-exponentiation-power-in-modular-arithmetic/


long long mod_pow(long long base, long long exp) {
    long long result = 1;
    while(exp > 0) {
        if(exp & 1) result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return result;
}


void precompute() {
    power_of_two[0] = 1;
    factorial[0] = 1;
    inv_factorial[0] = 1;
    for (int i = 1; i < MAX_N; i++){
        power_of_two[i] = (power_of_two[i-1] * 2) % MOD;
        factorial[i] = (factorial[i-1] * i) % MOD;
        inv_factorial[i] = mod_pow(factorial[i], MOD-2); // Fermat's little theorem
    }
}


long long comb(int n, int k) {
    if(k < 0 || k > n) return 0;
    return ((factorial[n] * inv_factorial[k]) % MOD * inv_factorial[n-k]) % MOD;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    precompute();
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        unordered_map<int, int> freq;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            freq[arr[i]]++;
        }
        
        
        long long total_subsets = power_of_two[n]; 
        
        long long sum_sizes = ((long long)n * power_of_two[n-1] ) % MOD;
        
        
        int M = 0;
        for(auto &p : freq) {
            M = max(M, p.second);
        }
        
        
        long long sum_max = 0;
        for (int k = 1; k <= M; k++){
            long long prod = 1;
            
            for(auto &p : freq){
                int f = p.second;
                int up_to = min(f, k-1); 
                long long ways = 0;
                for (int j = 0; j <= up_to; j++){
                    ways = (ways + comb(f, j)) % MOD;
                }
                prod = (prod * ways) % MOD;
            }
            
            long long valid = (total_subsets - prod + MOD) % MOD;
            sum_max = (sum_max + valid) % MOD;
        }
        
        
        long long answer = (sum_sizes - sum_max + MOD) % MOD;
        //cout << answer << "\n";
    }
    return 0;
}
