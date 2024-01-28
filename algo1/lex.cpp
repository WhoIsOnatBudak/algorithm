#include <iostream>
#include <vector>
#include <map>
#include <unordered_map> 

using namespace std;

int main(){
    unordered_map<int,bool> ch;
    unordered_map<int,bool> ch1;
    int kac=0;
    cin>>kac;
    int en=0;
    int lmin=1;
    int len=0;
    int lmax=0;
    vector<int> min(kac);
    vector<int> max(kac);
    for(int i=0;i<kac;i++){
        int cur;
        cin>>cur;
        if(cur>en){
            min[i]=cur;
            max[i]=cur;
            en=cur;
            ch[cur]=true;
            ch1[cur]=true;
        }
        if(max[i]==0){
            if(len==en){
                while(ch[lmax]==true){
                    lmax=lmax-1;
                }
                max[i]=lmax;
                ch[lmax]=true;  
            }
            else{
            int k=cur;
            while(ch[k]==true){
                k=k-1;
            }
            max[i]=k;
            ch[k]=true;
            len=en;
            lmax=k;
            }
        }
        if(min[i]==0){
            while(ch1[lmin]==true){
                lmin++;
            }
            min[i]=lmin;
            ch1[lmin]=true;
        }
    }
    for(int a:min){
        cout<<a<<" ";
    }
    cout<<endl;
    for(int b:max){
        cout<<b<<" ";
    }
}
