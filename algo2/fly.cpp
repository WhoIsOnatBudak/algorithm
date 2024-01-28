#include <iostream>
#include <vector>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int N=0;
    cin>>N;
    N--;
    int omerx;
    int omery;
    int sinekx;
    int sineky;
    int copx;
    int copy;
    cin>>omerx>>omery;
    cin>>sinekx>>sineky;
    cin>>copx>>copy;
    int k=min(sinekx,omerx);
    int b=max(sinekx,omerx);
    int xfark=b-k;
    int yolx=min((N-b+xfark),(k+xfark));
    k=min(sineky,omery);
    b=max(sineky,omery);
    int yfark=b-k;
    int yoly=min((N-b+yfark),(k+yfark));
    int toplamyol=yolx+yoly;
    cout<<yolx<<" "<<yoly<<"\n";


    return 0;
}