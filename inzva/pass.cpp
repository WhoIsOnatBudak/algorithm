#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
#include <string>

// Function to count distinct substrings
int countDistinctSubstrings(const std::string &s) {
    std::set<std::string> substrings;
    for (size_t i = 0; i < s.size(); ++i) {
        for (size_t j = i + 1; j <= s.size(); ++j) {
            substrings.insert(s.substr(i, j - i));
        }
    }
    return substrings.size();
}

// Function to count distinct subsequences (excluding the empty subsequence)
int countDistinctSubsequences(const std::string &s) {
    int n = s.size();
    std::vector<int> dp(n + 1, 0);
    dp[0] = 1; // Base case: There's one subsequence (the empty subsequence)
    
    std::unordered_map<char, int> lastOccurrence;
    
    for (int i = 1; i <= n; ++i) {
        dp[i] = 2 * dp[i - 1]; // Each subsequence can either include or exclude s[i-1]
        
        // If s[i-1] has appeared before, subtract the duplicate subsequences
        if (lastOccurrence.find(s[i - 1]) != lastOccurrence.end()) {
            dp[i] -= dp[lastOccurrence[s[i - 1]] - 1];
        }
        
        lastOccurrence[s[i - 1]] = i;
    }
    
    return dp[n] - 1; // Subtract 1 to exclude the empty subsequence
}

int main() {
    std::string s;
    //std::cout << "Enter the string: ";
    std::cin >> s;

    // Count distinct substrings
    int numSubstrings = countDistinctSubstrings(s);

    // Count distinct subsequences (excluding the empty subsequence)
    int numSubsequences = countDistinctSubsequences(s);

    // Subtract substrings count from subsequences count
    int result = numSubsequences - numSubstrings;

    // Display the result
    std::cout << "Number of distinct subsequences minus substrings (excluding empty subsequence): " << result << std::endl;

    return 0;
}
