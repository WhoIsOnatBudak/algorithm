//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

int main() {
    int j,k;
    cin>>j>>k;

    vector<vector<int>> v(j,vector<int>(k,0));

    for(int i = 0 ; i < j ; i++){
        for(int p = 0 ; p < k ; p++){
            int temp ;
            cin>>temp;
            v[i][p] =temp;
        }
    }

    vector<vector<int>> visit(j,vector<int>(k,0));

    vector<int> component(j*k,0);

    for(int say = 0 ; say <j*k ; say++){
        int satir = say / k;
        int sutun = say%k;
        if(visit[say/k][say%k] == 1){
            continue;
        }
        visit[say/k][say%k] = 1;
        if(satir%2 == 0){
            
        }
        else{

        }

    }


	return 0;
}
