#include <iostream>
#include <vector>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;


int don(vector<vector<int>> &arr,int tur,int r,int c,int rm,int cm,vector<vector<vector<int>>> &fnd){
    int say=0;
    if(r<1 || c < 1 || c > cm || r > rm){
        return 0;
    }



    if(tur==1){
        if(arr[r][c]!=2){
            return 0;
        }
        if(fnd[r][c][1]>=0){
            return fnd[r][c][1];
        }
        say+=don(arr,2,r,c+1,rm,cm,fnd);
        say+=don(arr,2,r,c-1,rm,cm,fnd);
        say+=don(arr,2,r+1,c,rm,cm,fnd);
        say+=don(arr,2,r-1,c,rm,cm,fnd);
        fnd[r][c][1]=say;
        return say;
        
    }
    else if(tur==2){
        if(arr[r][c]!=0){
            return 0;
        }
        if(fnd[r][c][2]>=0){
            return fnd[r][c][2];
        }
        say+=don(arr,3,r,c+1,rm,cm,fnd);
        say+=don(arr,3,r,c-1,rm,cm,fnd);
        say+=don(arr,3,r+1,c,rm,cm,fnd);
        say+=don(arr,3,r-1,c,rm,cm,fnd);
        fnd[r][c][2]=say;
        return say;
    }
    else if(tur==3){
        if(arr[r][c]!=2){
            return 0;
        }
        if(fnd[r][c][3]>=0){
            return fnd[r][c][3];
        }
        say+=don(arr,4,r,c+1,rm,cm,fnd);
        say+=don(arr,4,r,c-1,rm,cm,fnd);
        say+=don(arr,4,r+1,c,rm,cm,fnd);
        say+=don(arr,4,r-1,c,rm,cm,fnd);
        fnd[r][c][3]=say;
        return say;
        
    }
    else if(tur==4){
        if(arr[r][c]!=2){
            return 0;
        }
        return 1;
    }

}

int main(){
    int collum;
    int row;
    cin>>row;
    cin>>collum;
    //int find[row+1][collum+1][5];

    vector<vector<vector<int>>> find(row+1,vector<vector<int>>(collum+1,vector<int>(5,-1)));

    vector<vector<int>> ar(row+1,vector<int>(collum+1,-1));


    //memset(find,0,sizeof(find));
    
    int sayac=0;
    for(int i=1;i<row+1;i++){
        for(int j=1;j<collum+1;j++){
            int temp;
            cin>>temp;
            ar[i][j]=temp;
        }
    }
    for(int k=1;k<row+1;k++){
        for(int l=1;l<collum+1;l++){
            sayac+=don(ar,1,k,l,row,collum,find);
        }
    }
    cout<<sayac;





    return 0;
}