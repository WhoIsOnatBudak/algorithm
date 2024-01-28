#include <iostream>
#include <vector>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int size=0;
    cin>>size;
    int ar[size+1];
    int used[size+1];
    memset(used,1,sizeof(used));
    for(int i=0;i<size;i++){
        int temp;
        cin>>temp;
        ar[i]=temp;
        used[i]=1;
    }
    int max=1;

    for(int j=0;j<size;j++){
        int prev=1;
        for(int k=0;k<j;k++){
            if(ar[j]>=ar[k]){
                if(used[k]>=prev){
                    used[j]=used[k]+1;
                }
            }
            if(used[j]>max){
                max=used[j];
            }
        }
    }
    cout<<max;
    return 0;
}