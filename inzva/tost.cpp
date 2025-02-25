//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

int main() {
    int count;
    cin>>count;
    int delay;
    cin>>delay;
    queue<string> q;
    for(int i = 0 ; i < count ; i++){
        string name;
        cin>>name;
        q.push(name);
    }
    int curdelay = delay;
    while(!q.empty()){
        if(curdelay > 0){
            string cur = q.front();
            q.pop();
            cout<<cur<<"\n";
            curdelay--;
        }
        else if(curdelay == 0){
            string hop = q.front();
            q.pop();
            q.push(hop);
            curdelay = delay;
        }
    }

	return 0;
}
