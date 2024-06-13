#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <queue>

using namespace std;

int main(){
    int x,y;
    cin>>y>>x;
    char arr[y][x];
    pair<int,int> A;
    stack<pair<int,int>> tracktor;


    for(int i = 0; i < y ; i++){
        for(int j = 0 ; j < x ;j++){
            char temp;
            cin>>temp;
            arr[i][j]=temp;
            if(temp == 'A'){
                A.first=j;
                A.second=i;
            }
            if(temp == 'M'){
                tracktor.push(make_pair(j,i));
            }

        }
    }
    vector<vector<int>> dpA(y,vector<int>(x,30000));
    vector<vector<int>> yedek(y,vector<int>(x,30000));
    
    queue<pair<int,int>> st;
    st.push(A);
    int s =0;
    while(!st.empty()){
        int curx = st.front().first;
        int cury = st.front().second;

        if(s == 0){
            dpA[cury][curx] = 0;
            yedek[cury][curx] = 0; 
            s++;
        }
        st.pop();
        
        if((curx-1)>=0 && (curx-1) < x && cury >= 0 && cury < y && dpA[cury][curx-1] > (dpA[cury][curx]+1) && arr[cury][curx-1] != '#'){
            st.push({curx-1,cury});
            dpA[cury][curx-1] = (dpA[cury][curx]+1);
            yedek[cury][curx-1] = (dpA[cury][curx]+1);
        }
        if((curx+1)>=0 && (curx+1) < x && cury >= 0 && cury < y && dpA[cury][curx+1] > (dpA[cury][curx]+1) && arr[cury][curx+1] != '#'){
            st.push({curx+1,cury});
            dpA[cury][curx+1] = (dpA[cury][curx]+1);
            yedek[cury][curx+1] = (dpA[cury][curx]+1);
        }
        if((curx)>=0 && (curx) < x && (cury+1) >= 0 && (cury+1) < y && dpA[cury+1][curx] > (dpA[cury][curx]+1) && arr[cury+1][curx] != '#'){
            st.push({curx,cury+1});
            dpA[cury+1][curx] = (dpA[cury][curx]+1);
            yedek[cury+1][curx] = (dpA[cury][curx]+1);
        }
        if((curx)>=0 && (curx) < x && (cury-1) >= 0 && (cury-1) < y && dpA[cury-1][curx] > (dpA[cury][curx]+1) && arr[cury-1][curx] != '#'){
            st.push({curx,cury-1});
            dpA[cury-1][curx] = (dpA[cury][curx]+1);
            yedek[cury-1][curx] = (dpA[cury][curx]+1);
        }

        //if((curx == 0 || cury == 0 || curx == (x-1) || cury == (y-1)) && arr[curx][cury] != '.'){

        //}
    }
    
    queue<pair<int,int>> stt;
    vector<vector<int>> dpB(y,vector<int>(x,3000));
    int size = tracktor.size();
    for(int i = 0 ; i < size; i++){
        //cout<<tracktor.size();
        s=0;
        auto tmp = tracktor.top();

        stt.push(tmp);
        tracktor.pop();
        while(!stt.empty()){
            int curx = stt.front().first;
            int cury = stt.front().second;

            if(s == 0){
                dpB[cury][curx] = 0;
                s++;
            }
            
            stt.pop();
            
            if(dpB[cury][curx] <  dpA[cury][curx]){
                if((curx-1)>=0 && (curx-1) < x && cury >= 0 && cury < y && dpB[cury][curx-1] > (dpB[cury][curx]+1) && arr[cury][curx-1] != '#'){
                    stt.push({curx-1,cury});
                    dpB[cury][curx-1] = (dpB[cury][curx]+1);
                }
                if((curx+1)>=0 && (curx+1) < x && cury >= 0 && cury < y && dpB[cury][curx+1] > (dpB[cury][curx]+1) && arr[cury][curx+1] != '#'){
                    stt.push({curx+1,cury});
                    dpB[cury][curx+1] = (dpB[cury][curx]+1);
                }
                if((curx)>=0 && (curx) < x && (cury+1) >= 0 && (cury+1) < y && dpB[cury+1][curx] > (dpB[cury][curx]+1) && arr[cury+1][curx] != '#'){
                    stt.push({curx,cury+1});
                    dpB[cury+1][curx] = (dpB[cury][curx]+1);
                }
                if((curx)>=0 && (curx) < x && (cury-1) >= 0 && (cury-1) < y && dpB[cury-1][curx] > (dpB[cury][curx]+1) && arr[cury-1][curx] != '#'){
                    stt.push({curx,cury-1});
                    dpB[cury-1][curx] = (dpB[cury][curx]+1);
                }
            }

        }
    }

    for(int i = 0 ; i < y ; i++){
        for(int j = 0 ; j < x; j++){
            yedek[i][j] = yedek[i][j] - dpB[i][j];
        }
    }
    int min = 30001;
    for(int i = 0 ; i < x ; i++){
        if(yedek[0][i] < 0 && dpA[0][i] < min){
            min = dpA[0][i];
        }
    }
    for(int i = 0 ; i < x ; i++){
        if(yedek[y-1][i] < 0 && dpA[y-1][i] < min){
            min = dpA[y-1][i];
        }
    }
    for(int i = 0 ; i < y ; i++){
        if(yedek[i][0] < 0 && dpA[i][0] < min){
            min = dpA[i][0];
        }
    }
    for(int i = 0 ; i < y ; i++){
        if(yedek[i][x-1] < 0 && dpA[i][x-1] < min){
            min = dpA[i][x-1];
        }
    }
    if(min == 30001){
        cout<<-1;
    }
    else{
        cout<<min;
    }
    
    /*for(int i = 0; i < y ; i++){
        for(int j = 0 ; j < x ;j++){
            cout<<dpB[i][j]<<" ";

        }
        cout<<endl;
    }*/



}