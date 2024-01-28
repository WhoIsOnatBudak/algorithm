#include <iostream>
#include <vector>
#include <math.h>
#include <bits/stdc++.h>
#define int long long
using namespace std;

    vector<int> coins2{1,2};
    vector<int> coins3{1,2,3};
    vector<int> coins4{1,2,3,4};
    vector<int> coins5{1,2,3,4,5};
    vector<int> coins6{1,2,3,4,5,6};
    vector<int> coins7{1,2,3,4,5,6,7};

int32_t main(){
    long long uzun=0;
    cin>>uzun;
    long long say=0;
    long long prev=0;
    long long olasilik=1;
    string s;
    cin>>s;
    //cin>>big;
    vector<int> temp(0,s.length());
    for( long long i=0;i<s.length();i++){
        
        temp.push_back(s[i]-'0');
    }
    //cout<<temp[1]<<endl;
    //cout<<temp[uzun-1]<<endl
    
    //reverse(temp.begin(),temp.end());
    
    for( long long i=0;i<uzun;i++){
        
        if(prev==temp[i] || prev == 0){
            say++;
        }
        if((i>0)&&(prev!=temp[i] || i+1==uzun)){
            if(prev==2){
                long long ar[say+1];
                memset(ar,0,sizeof(ar));
                ar[0]=1;
                for(int j=1;j<say+1;j++){
                    for(int k=0;k<coins2.size();k++){
                        if(j-coins2[k]>=0){
                        ar[j]=(ar[j]+ar[j-coins2[k]])%1000000007;
                        }
                    }
                }
                olasilik=((ar[say]%1000000007)*(olasilik%1000000007))%1000000007;
            }
            if(prev==3){
                long long ar[say+1];
                memset(ar,0,sizeof(ar));
                ar[0]=1;
                for( long long j=1;j<say+1;j++){
                    for(int k=0;k<coins3.size();k++){
                        if(j-coins3[k]>=0){
                        ar[j]=(ar[j]+ar[j-coins3[k]])%1000000007;
                        }
                    }
                }
                olasilik=((ar[say]%1000000007)*(olasilik%1000000007))%1000000007;
            }
            if(prev==4){
                long long ar[say+1];
                memset(ar,0,sizeof(ar));
                ar[0]=1;
                for( long long j=1;j<say+1;j++){
                    for(int k=0;k<coins4.size();k++){
                        if(j-coins4[k]>=0){
                        ar[j]=(ar[j]+ar[j-coins4[k]])%1000000007;
                        }
                    }
                }
                olasilik=((ar[say]%1000000007)*(olasilik%1000000007))%1000000007;
            }
            if(prev==5){
                long long ar[say+1];
                memset(ar,0,sizeof(ar));
                ar[0]=1;
                for( long long j=1;j<say+1;j++){
                    for(int k=0;k<coins5.size();k++){
                        if(j-coins5[k]>=0){
                        ar[j]=(ar[j]+ar[j-coins5[k]])%1000000007;
                        }
                    }
                }
                olasilik=((ar[say]%1000000007)*(olasilik%1000000007))%1000000007;
            }
            if(prev==6){
                long long ar[say+1];
                memset(ar,0,sizeof(ar));
                ar[0]=1;
                for(long j=1;j<say+1;j++){
                    for(int k=0;k<coins6.size();k++){
                        if(j-coins6[k]>=0){
                        ar[j]=(ar[j]+ar[j-coins6[k]])%1000000007;
                        }
                    }
                }
                olasilik=((ar[say]%1000000007)*(olasilik%1000000007))%1000000007;
            }
            if(prev==7){
                long long ar[say+1];
                memset(ar,0,sizeof(ar));
                ar[0]=1;
                for(long j=1;j<say+1;j++){
                    for(int k=0;k<coins7.size();k++){
                        if(j-coins7[k]>=0){
                        ar[j]=(ar[j]+ar[j-coins7[k]])%1000000007;
                        }
                    }
                }
                olasilik=((ar[say]%1000000007)*(olasilik%1000000007))%1000000007;
            }
            say=1;
            
        }
        prev=temp[i];


    }
    cout<<olasilik%1000000007<<"\n";
}