#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

string process_string(int N, const string& S) {
    stack<vector<int>> letter_stacks; // Stack to hold letter assignments
    stack<char> bracket_stack; // Stack to check bracket validity
    vector<int> current_assignments(26, -1); // Current letter assignments
    int total_sum = 0;
    bool valid = true;

    for (int i = 0; i < N; i++) {
        char c = S[i];

        // Check for opening brackets
        if (c == '(' || c == '[' || c == '{') {
            bracket_stack.push(c); // Push the opening bracket
            letter_stacks.push(current_assignments); // Push current letter assignments onto the stack
            current_assignments.assign(26, -1); // Reset current assignments for new scope
            continue;
        }

        // Check for closing brackets
        if (c == ')' || c == ']' || c == '}') {
            if (bracket_stack.empty()) {
                valid = false; // Unbalanced brackets
                break;
            }

            char open_bracket = bracket_stack.top();
            bracket_stack.pop();

            // Check for matching brackets
            if ((c == ')' && open_bracket != '(') ||
                (c == ']' && open_bracket != '[') ||
                (c == '}' && open_bracket != '{')) {
                valid = false; // Mismatched brackets
                break;
            }

            // Sum values of currently assigned letters
            int scope_sum = 0;
            for (int j = 0; j < 26; j++) {
                if (current_assignments[j] != -1) {
                    scope_sum += current_assignments[j];
                }
            }
            total_sum += scope_sum; // Add the scope sum to total

            current_assignments = letter_stacks.top(); // Restore previous letter assignments
            letter_stacks.pop();
            continue;
        }

        // Check for letters and their assignments
        if (isalpha(c)) {
            int idx = c - 'a';
            // If next character is a digit
            if (i + 1 < N && isdigit(S[i + 1])) {
                int value = S[++i] - '0'; // Get the digit
                current_assignments[idx] = value; // Assign value to letter
            } else {
                // Alone letter, check if it has been assigned
                if (current_assignments[idx] == -1) {
                    valid = false; // Invalid if letter is unassigned
                    break;
                }
                total_sum += current_assignments[idx]; // Add assigned value to total
            }
        }
    }

    // Final check for unclosed brackets
    if (!bracket_stack.empty()) {
        valid = false;
    }

    return valid ? to_string(total_sum) : "INVALID";
}

int main() {
    int N;
    string S;

    cin >> N; // Input number of characters
    cin >> S; // Input the string

    cout << process_string(N, S) << endl; // Process the string and output result

    return 0;
}
