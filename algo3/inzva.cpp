#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int x,y;
    cin>>y>>x;
    char arr[y][x];
    int ix,iy;
    vector<vector<int>> dp(y,vector<int>(x,-999));
    for(int i = 0 ; i < y ; i++){
        for(int j = 0 ; j < x; j++){
            char temp;
            cin>>temp;
            arr[i][j] = temp;
            if(temp == 'i'){
                ix=j;
                iy=i;
                dp[i][j]=0; 
            }

        }
    }
    //---i
    for(int i = ix ; i >-1 ; i--){
        if(arr[iy][i] == 'i'){
            continue;
        }
        if(arr[iy][i] == 'a'){
            dp[iy][i] = dp[iy][i+1]+1;
        }
        if(arr[iy][i] == 'b'){
            dp[iy][i] = dp[iy][i+1]-1;
        }
        if(arr[iy][i] == '.'){
            dp[iy][i] = dp[iy][i+1];
        }
    }

    //i-----
    for(int i = ix ; i < x ; i++){
        if(arr[iy][i] == 'i'){
            continue;
        }
        if(arr[iy][i] == 'a'){
            dp[iy][i] = dp[iy][i-1]+1;
        }
        if(arr[iy][i] == 'b'){
            dp[iy][i] = dp[iy][i-1]-1;
        }
        if(arr[iy][i] == '.'){
            dp[iy][i] = dp[iy][i-1];
        }
    }

    //-
    //-
    //i
    for(int i = iy ; i > -1 ; i--){
        if(arr[i][ix] == 'i'){
            continue;
        }
        if(arr[i][ix] == 'a'){
            dp[i][ix] = dp[i+1][ix]+1;
        }
        if(arr[i][ix] == 'b'){
            dp[i][ix] = dp[i+1][ix]-1;
        }
        if(arr[i][ix] == '.'){
            dp[i][ix] = dp[i+1][ix];
        }
    }

    //i
    //-
    //-
    for(int i = iy ; i < y ; i++){
        if(arr[i][ix] == 'i'){
            continue;
        }
        if(arr[i][ix] == 'a'){
            dp[i][ix] = dp[i-1][ix]+1;
        }
        if(arr[i][ix] == 'b'){
            dp[i][ix] = dp[i-1][ix]-1;
        }
        if(arr[i][ix] == '.'){
            dp[i][ix] = dp[i-1][ix];
        }
    }

    //sol üst;
    for(int i = ix -1; i > -1 ; i--){
        for(int j = iy -1 ; j > -1 ; j--){
            if(arr[j][i] == 'i'){
            continue;
            }
            if(arr[j][i] == 'a'){
                dp[j][i] = dp[j+1][i]+1+dp[j][i+1] -dp[j+1][i+1];
            }
            if(arr[j][i] == 'b'){
                dp[j][i] = dp[j+1][i]-1+dp[j][i+1] -dp[j+1][i+1];
            }
            if(arr[j][i] == '.'){
                dp[j][i] = dp[j+1][i]+dp[j][i+1] -dp[j+1][i+1];
            }
        }
    }
    //cout<<-1;
    //sag üst
    for(int i = ix +1; i < x ; i++){
        for(int j = iy -1 ; j > -1 ; j--){
            if(arr[j][i] == 'i'){
            continue;
            }
            if(arr[j][i] == 'a'){
                dp[j][i] = dp[j+1][i]+1+dp[j][i-1] -dp[j+1][i-1];
            }
            if(arr[j][i] == 'b'){
                dp[j][i] = dp[j+1][i]-1+dp[j][i-1] -dp[j+1][i-1];
            }
            if(arr[j][i] == '.'){
                dp[j][i] = dp[j+1][i]+dp[j][i-1] -dp[j+1][i-1];
            }
        }
    }
    
    //sag alt
    for(int i = ix+1; i < x ; i++){
        for(int j = iy+1 ; j < y ; j++){
            if(arr[j][i] == 'i'){
            continue;
            }
            if(arr[j][i] == 'a'){
                dp[j][i] = dp[j-1][i]+1+dp[j][i-1] -dp[j-1][i-1];
            }
            if(arr[j][i] == 'b'){
                dp[j][i] = dp[j-1][i]-1+dp[j][i-1] -dp[j-1][i-1];
            }
            if(arr[j][i] == '.'){
                dp[j][i] = dp[j-1][i]+dp[j][i-1] -dp[j-1][i-1];
            }
        }
    }
    cout<<-1;
    //sol alt
    for(int i = ix -1; i > -1 ; i--){
        for(int j = iy +1 ; j < y ; j++){
            if(arr[j][i] == 'i'){
            continue;
            }
            if(arr[j][i] == 'a'){
                dp[j][i] = dp[j-1][i]+1+dp[j][i+1] -dp[j-1][i+1];
            }
            if(arr[j][i] == 'b'){
                dp[j][i] = dp[j-1][i]-1+dp[j][i+1] -dp[j-1][i+1];
            }
            if(arr[j][i] == '.'){
                dp[j][i] = dp[j-1][i]+dp[j][i+1] -dp[j-1][i+1];
            }
        }
    }
    // Print dp vector
    for(int i = 0; i < y; i++) {
        for(int j = 0; j < x; j++) {

            cout << dp[i][j] << " ";
            
        }
        cout << endl;
    }

    return 0;
    

}