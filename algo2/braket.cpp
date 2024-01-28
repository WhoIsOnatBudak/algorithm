#include <iostream>
#include <vector>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

int main(){

    int say;
    cin >> say;
    stack<char> st;
    string buyuk;
    int ind=0;
    cin>>buyuk;
    while(ind<buyuk.size()){
        if( buyuk[ind] == ')' && buyuk[ind+1]=='('){
            break;
        }
        if( buyuk[ind] == ')' && buyuk[ind+1]=='{'){
            break;
        }
        if( buyuk[ind] == ')' && buyuk[ind+1]=='['){
            break;
        }
        if( buyuk[ind] == ']' && buyuk[ind+1]=='('){
            break;
        }
        if( buyuk[ind] == ']' && buyuk[ind+1]=='{'){
            break;
        }
        if( buyuk[ind] == ']' && buyuk[ind+1]=='['){
            break;
        }
        if( buyuk[ind] == '}' && buyuk[ind+1]=='('){
            break;
        }
        if( buyuk[ind] == '}' && buyuk[ind+1]=='{'){
            break;
        }
        if( buyuk[ind] == '}' && buyuk[ind+1]=='['){
            break;
        }
        ind++;
    }
    if(ind==buyuk.size()){
        cout<<"NO";
        return 0;
    }
    for (int i = 0; i < say; i++) {
    char temp;
    temp = buyuk[i];

    if (!st.empty() && temp == ')' && st.top() != '(') {
        cout << "NO";
        return 0;
    } else if (!st.empty() && temp == '}' && st.top() != '{') {
        cout << "NO";
        return 0;
    } else if (!st.empty() && temp == ']' && st.top() != '[') {
        cout << "NO";
        return 0;
    }

    if (!st.empty() && temp == ')' && st.top() == '(') {
        st.pop();
    } else if (!st.empty() && temp == '}' && st.top() == '{') {
        st.pop();
    } else if (!st.empty() && temp == ']' && st.top() == '[') {
        st.pop();
    } else {
        st.push(temp);
    }
}

    cout<<"YES";
    return 0; 
}