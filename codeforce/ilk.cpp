//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

int main() {
// write your code here
    int q;
    cin>>q;

    for(int i = 0 ; i < q; i++){
        int count;
        cin>>count;
        int prev;
        int flag=0;
        for(int j = 0 ; j < count; j++){
            int cur;
            if(j == 0){
                cin>>cur;
            }
            if(j > 0){
                prev = cur;
                cin>>cur;
                if(prev*2 > cur && cur*2 > prev){
                    flag=1;
                }
            }

        }
        if(flag == 0){
            cout<<"NO"<<"\n";
        }
        if(flag == 1){
            cout<<"YES"<<"\n";
        }
    }
	return 0;
}
