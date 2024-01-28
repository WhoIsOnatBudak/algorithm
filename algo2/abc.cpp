#include <iostream>
#include <vector>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int size;
    cin>>size;
    string alf;
    cin>>alf;
    int zero=0;
    int guc=pow(2,size-1);
    for(int i=0;i<guc;i++){
        for(int j=0;j<size;j++){
            cout<<alf[j];
            int ag=pow(2,size-j-2);
            if((ag | zero) != zero ){
                cout<<" ";
            }
        }
        cout<<"\n";
        zero++;
    }

    return 0;
}