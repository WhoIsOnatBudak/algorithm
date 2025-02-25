//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

int main() {
// write your code here
    vector<int> deck;
    for(int i = 0 ; i < 52;i++){
        int temp;
        cin>>temp;
        deck.push_back(temp);
    }
    int total=0;
    int geralt1 = 0;
    geralt1 += deck[0];
    geralt1 += deck[1];
    geralt1 += deck[5];
    geralt1 += deck[4];
    int index = 0;
    for(int i = 0 ; i< 500;i++){
        geralt1 += deck[index%52];
        index+=2;
    }

    vector<int> thresholds;
    int p;
    cin>>p;
    for(int i = 0 ; i < p ;i++){
        int tep;
        cin>>tep;
        thresholds.push_back(tep);
    }
    for (int t : thresholds) {
        if (geralt1 >= t) {
            cout << "Geralt will face Imlerith!" << endl;
        } else {
            cout << "Imlerith will face Ciri!" << endl;
        }
    }
	return 0;
}
