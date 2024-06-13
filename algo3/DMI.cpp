#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <iomanip>


using namespace std;

int main(){
    int k,n;
    cin>>n>>k;

    queue<int> q;
    int arr[n];
    int gain[n-k+1];
    int loss[n-k+1];
    int curg = 0;
    int curl = 0;
    for(int i = 0 ; i < n ; i++){
        int temp;
        cin>>temp;
        arr[i]= temp;
        if(i > 0){
            int g = arr[i]-arr[i-1];
            if(g > 0){
                q.push(g);
                curg += g;
            }
            else{
                q.push(g);
                curl += -g;
            }
        }
        if(i+1 >= k){
            gain[i-k+1]=curg;
            loss[i-k+1]=curl;

            int bak = q.front();
            if(bak > 0){
                curg -= bak;
            }
            else{
                curl += bak;
            }
            q.pop();

        }
    }

    for(int i = 0 ; i < n-k+1 ; i++){
        double number;
        if(gain[i] == 0){
            number = 0;
        }
        else{
            number = (100.0*gain[i])/(gain[i]+loss[i]);
        }
        cout<<fixed << setprecision(1)<<number;
        if(number<35){
            cout<<" 1"<<"\n";
        }
        else if(number>65){
            cout<<" 2"<<"\n";
        }
        else{
            cout<<" 0"<<"\n";
        }
    }


}