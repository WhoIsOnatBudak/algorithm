#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int N;
    cin >> N;

    string particles;
    cin >> particles;

    long long count = 0;
    int netCharge = 0;
    
    unordered_map<int, int> prefixSumFreq;
    prefixSumFreq[0] = 1; // Initialize with one occurrence of zero, as it represents an empty subarray

    for (int i = 0; i < N; i++) {
        if (particles[i] == 'p') {
            netCharge++;
        } else if (particles[i] == 'e') {
            netCharge--;
        }

        count += prefixSumFreq[netCharge];
        prefixSumFreq[netCharge]++;
    }

    cout << count << endl;

    return 0;
}

