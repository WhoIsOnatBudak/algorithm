#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int logt(int sayi){
    int sayac=0;
    if(sayi==1){
        return 0;
    }
    while(sayi!=1){
        sayi=sayi/2;
        sayac++;
    }
    return sayac;
}

int main(){
    int kac=0;
    cin>>kac;
    int en=0;
    int anlik=0;
    for(int i=0;i<kac;i++){
        cin>>anlik;
        if(anlik>en){
            en=anlik;
        }
    }
    int abi=logt(en)+1;
    if(abi%3==0){
        cout<<abi/3;
    }
    else if(abi%3==1){
        cout<<(abi+2)/3;
    }
    else if(abi%3==2){
        cout<<(abi+1)/3;
    }
    return 0;
}