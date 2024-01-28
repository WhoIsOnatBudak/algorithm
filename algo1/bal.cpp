#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    long balon = 0;
    long mal = 0;
    long current = 0;

    cin >> balon >> mal;

    unordered_set<long> sumSet;
    
    for (int i = 0; i < balon; i++) {
        cin >> current;
        unordered_set<long> newSums;
        for (const long& sum : sumSet) {
            newSums.insert(sum + current);
        }
        newSums.insert(current);
        sumSet.insert(newSums.begin(), newSums.end());
    }

    for (int k = 0; k < mal; k++) {
        cin >> current;
        if (sumSet.count(current) > 0) {
            cout << "yes" << "\n";
        } else {
            cout << "no" << "\n";
        }
    }

    return 0;
}
