#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    long long int count=0;
    long long int tane=0;
    char late;
    char cur;
    cin>>tane;
    int pe=0;
    for(long i=0;i<tane;i++){
        //cout<<tane;
        late=cur;
        cin>>cur;
        if(cur=='n'){
            count++;
            pe=0;
        }
        else if((cur=='p'&&late=='e')&&pe==0){
            count++;
            pe=1;
        }
        else if((cur=='e'&&late=='p')&&pe==0){
            count++;
            pe=1;
        }
        else{
            pe=0;
        }

    }
    long long int hesap=((count*count)+count)/2;
    cout<<hesap;
    return 0;
}