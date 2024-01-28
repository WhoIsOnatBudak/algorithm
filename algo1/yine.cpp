#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int power(int n,int x1,int y1,int x2, int y2, int x3, int y3,int x4,int y4,int x5, int y5, int x6, int y6){
    if(n==1){
        return (x2+y2+x3+y3-x1-x1-y1-y1);
    }
    else if(n==2){
        return (x5+y5+x6+y6-x4-x4-y4-y4);
    }
    int pwr =(x2+y2+x3+y3-x1-x1-y1-y1+power(n-1,x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,x6,y6)+power(n-1,x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,x6,y6)+power(n-2,x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,x6,y6)+power(n-2,x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,x6,y6));

    return pwr;
}

int main(){
    int xx1;
    int yy1;
    int xx2;
    int yy2;
    int xx3;
    int yy3;
    int xx4;
    int yy4;
    int xx5;
    int yy5;
    int xx6;
    int yy6;
    int N;
    cin>>N;
    cin>>xx1;
    cin>>yy1;
    cin>>xx2;
    cin>>yy2;
    cin>>xx3;
    cin>>yy3;
    cin>>xx4;
    cin>>yy4;
    cin>>xx5;
    cin>>yy5;
    cin>>xx6;
    cin>>yy6;
    cout<<yy6;
    power(N,xx1,yy1,xx2,yy2,xx3,yy3,xx4,yy4,xx5,yy5,xx6,yy6);
    return 0;
}