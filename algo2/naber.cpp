#include <iostream>

using namespace std;

int main(){
    long sayi;
    cin>>sayi;
    long max;
    cin>>max;
    bool ar[max]= {false};
    long temp;
    for(long i=1;i<(sayi+1);i++){
        cin>>temp;
        ar[temp]=1;
    }
    ar[max]=1;
    for(long j=1;j<(max+1);j++){
        if(ar[j]==0){
            cout<<j<<" ";
        }
    }


    return 0;
}