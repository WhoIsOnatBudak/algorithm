#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;
const int MAX_ROOMS = 1299827;

// Function to compute power of 2 modulo m
long long mod_pow(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Precompute factorials and their inverses
vector<long long> precompute_factorials(int n) {
    vector<long long> fact(n + 1, 1);
    for (int i = 2; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    return fact;
}

vector<long long> precompute_inverses(const vector<long long>& fact, int n) {
    vector<long long> inv(n + 1);
    inv[n] = mod_pow(fact[n], MOD - 2, MOD);
    for (int i = n - 1; i >= 0; i--) {
        inv[i] = (inv[i + 1] * (i + 1)) % MOD;
    }
    return inv;
}

// Function to calculate combinations
long long comb(int n, int r, const vector<long long>& fact, const vector<long long>& inv) {
    if (n < r) return 0;
    return (fact[n] * inv[r] % MOD * inv[n - r] % MOD) % MOD;
}

int main() {
    int k;
    cin >> k;

    // Precompute factorials and inverses
    vector<long long> fact = precompute_factorials(MAX_ROOMS);
    vector<long long> inv = precompute_inverses(fact, MAX_ROOMS);

    long long total_scenarios = 0;

    // Iterate through all rooms
    for (int i = 1; i < MAX_ROOMS; i++) {
        long long p = mod_pow(2, i, MAX_ROOMS); // Packs in room i

        if (p >= k) {
            total_scenarios = (total_scenarios + comb(p, k, fact, inv)) % MOD; // Count valid scenarios
        }
        // Rooms with p < k are ignored in the survival scenario count
    }

    cout << total_scenarios << endl; // Output the total scenarios
    return 0;
}
