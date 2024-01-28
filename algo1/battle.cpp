#include <bits/stdc++.h>
#include <iostream>
#include <cmath>

using namespace std;

int isprime(int sayi){
    int test = sqrt(sayi)+1;
    if(sayi<2){
        return 0;
    }

    if(sayi==2){
        return 1;
    }
    for(int i=2;i<test;i++){
        if(sayi%(i)==0){
            return 0;
        }
    }
    return 1;
}

int isdonek(int yas,int yil){
    int test=0;
    for(int j=0;j<yil+1;j++){
        test=isprime(j+yas);
        if(test==1){
        return 1;
        }
    }
    
    return 0;
    
}

int main(){
    int toplam=0;
    int sura=0;
    int bera=0;
    int age=0;
    cin>>toplam;
    cin>>age;
    sura= toplam;
    for(int k=0;k<toplam;k++){
        int bak=0;
        int baktim=0;
        cin>>bak;
        baktim=isdonek(bak,age);
        sura-=baktim;
        bera+=baktim;
    }

    if(bera>sura){
        cout<<"Berat"<<"\n";
        cout<<bera;
    }
    else{
        cout<<"Sura"<<"\n";
        cout<<sura<<endl;
    }

    return 0;
}