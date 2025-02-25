//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!



/////////https://www.geeksforgeeks.org/count-distinct-subsequences/   used as reference
/////////https://www.geeksforgeeks.org/count-number-of-distinct-substring-in-a-string/
/////////https://takeuforward.org/data-structure/number-of-distinct-substrings-in-a-string-using-trie/


#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

// Function to build the suffix array in O(N log N)
vector<int> buildSuffixArray(string &s) {
    int n = s.size();
    vector<int> suffixArray(n), rank(n), temp(n);

    // Initial ranking based on the first character
    for (int i = 0; i < n; i++) {
        suffixArray[i] = i;
        rank[i] = s[i];
    }

    for (int k = 1; k < n; k *= 2) {
        auto cmp = [&rank, k, n](int i, int j) {
            if (rank[i] != rank[j]) return rank[i] < rank[j];
            int ri = i + k < n ? rank[i + k] : -1;
            int rj = j + k < n ? rank[j + k] : -1;
            return ri < rj;
        };

        sort(suffixArray.begin(), suffixArray.end(), cmp);

        temp[suffixArray[0]] = 0;
        for (int i = 1; i < n; i++) {
            temp[suffixArray[i]] = temp[suffixArray[i - 1]] + (cmp(suffixArray[i - 1], suffixArray[i]) ? 1 : 0);
        }
        rank = temp;
    }

    return suffixArray;
}

// Function to build the LCP array in O(N)
vector<int> buildLCPArray(string &s, vector<int> &suffixArray) {
    int n = s.size();
    vector<int> lcp(n), rank(n);
    
    for (int i = 0; i < n; i++) {
        rank[suffixArray[i]] = i;
    }

    int h = 0;
    for (int i = 0; i < n; i++) {
        if (rank[i] > 0) {
            int j = suffixArray[rank[i] - 1];
            while (i + h < n && j + h < n && s[i + h] == s[j + h]) {
                h++;
            }
            lcp[rank[i]] = h;
            if (h > 0) h--;
        }
    }

    return lcp;
}

// Function to count the number of distinct substrings in O(N)
long long countDistinctSubstrings(string &s) {
    int n = s.size();
    
    // Build suffix array and LCP array
    vector<int> suffixArray = buildSuffixArray(s);
    vector<int> lcp = buildLCPArray(s, suffixArray);

    long long totalSubstrings = 0;

    // For each suffix, calculate the number of distinct substrings it contributes
    for (int i = 0; i < n; i++) {
        totalSubstrings += (n - suffixArray[i]) - (i > 0 ? lcp[i] : 0);
        totalSubstrings %= MOD;
    }

    return totalSubstrings;
}

long long countSub(string &str) {
    // Create an array to store index of last occurrence of each character
    vector<long long> last(256, -1);

    // Length of input string
    long long n = str.length();

    // dp[i] will store count of distinct subsequences of length i
    vector<long long> dp(n + 1, 0);

    // Empty substring has only one subsequence
    dp[0] = 1;

    // Traverse through all lengths from 1 to n
    for (long long i = 1; i <= n; i++) {
        // Number of subsequences with substring str[0..i-1]
        dp[i] = (2 * dp[i - 1]) % MOD;

        // If current character has appeared before, then remove all subsequences
        // ending with the previous occurrence
        if (last[str[i - 1]] != -1)
            dp[i] = (dp[i] - dp[last[str[i - 1]]] + MOD) % MOD;

        // Mark occurrence of the current character
        last[str[i - 1]] = i - 1;
    }

    return dp[n];
}

int main() {
    long long c;
    cin >> c;
    string s;
    cin >> s;

    // Count the distinct subsequences and distinct substrings
    long long subsequences = countSub(s);
    long long substrings = countDistinctSubstrings(s);

    // Result is the number of distinct subsequences that are not substrings
    cout << (subsequences - substrings - 1 + MOD) % MOD;

    return 0;
}

