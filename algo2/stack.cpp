#include <iostream>
#include <vector>
#include <math.h>
#include <bits/stdc++.h>
#include <unordered_map>
#include <stack> 

using namespace std;

int main(){
    stack<char> st;
    string asli;
    cin>>asli;
    for(int i=0;i<asli.length();i++){
        char temp=asli[i];
        if((temp=='}' || temp == ']' || temp == ')')&&st.empty()){
            cout<<"NO";
            return 0;
        }
        if(temp=='(' || temp == '[' || temp == '{'){
            st.push(temp);
        }
        else if(st.top()=='('&&temp==')'){
            st.pop();
        }
        else if(st.top()=='{'&&temp=='}'){
            st.pop();
        }
        else if(st.top()=='['&&temp==']'){
            st.pop();
        }
        else{
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}