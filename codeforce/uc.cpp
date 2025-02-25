#include <iostream>
#include <stack>
#include <vector>
#include <climits>  // For INT_MAX
using namespace std;

void solve() {
    int n;
    cin >> n;  // Read the size of the input list
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];  // Read the input list
    }

    stack<int> stack1;  // First stack
    stack<int> stack2;  // Second stack
    vector<int> result; // To store the result of stack operations
    vector<int> pushed(n + 1, 0);  // Track if a number is pushed (index 1 to n)
    int expected = 1;

    // Push INT_MAX initially to both stacks to avoid empty checks
    stack1.push(INT_MAX);
    stack2.push(INT_MAX);

    for (int num : arr) {
        // If both stacks have top values greater than the current number, push to the lower one
        if (stack1.top() > num && stack2.top() > num) {
            if (stack1.top() > stack2.top()) {
                stack1.push(num);
                result.push_back(1);
            } else {
                stack2.push(num);
                result.push_back(2);
            }
            pushed[num] = 1;
        }
        // If only one of the stacks can push the number, push it there
        else if (stack1.top() > num) {
            stack1.push(num);
            result.push_back(1);
            pushed[num] = 1;
        } else if (stack2.top() > num) {
            stack2.push(num);
            result.push_back(2);
            pushed[num] = 1;
        } else {

            cout << "IMPOSSIBLE" << endl;
            return;
        }

        // Now check if we can pop from the stacks
        while (stack1.top() == expected || stack2.top() == expected) {
            // Pop from stack1 if top matches expected
            if (stack1.top() == expected) {
                stack1.pop();
            }
            // Pop from stack2 if top matches expected
            if (stack2.top() == expected) {
                stack2.pop();
            }
            ++expected;  // Increment the expected number
        }

        // If expected exceeds n, print the result immediately
        if (expected > n) {
            for (int i = 0; i < result.size(); ++i) {
                cout << result[i] << " ";
            }
            cout << endl;
            return;
        }

        // Check if the expected number is pushed and not on top of either stack
        if ((pushed[expected] && (stack1.top() != expected)) && (stack2.top() != expected)) {

            cout << "IMPOSSIBLE" << endl;
            return;
        }
    }

    // If the sequence was possible, we print the result
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
}

int main() {
    solve();
    return 0;
}
