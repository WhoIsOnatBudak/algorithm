//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;


void recursive(int left,int right,int many,vector<int>& v,vector<int>& last){
    int res = 0;
    int tek = many%2;
    if(many == 0){
        return;
    }
    if(tek){
        int mid=(left+right)/2;
        last.push_back(v[mid]);
        if(many <= 1){
            return;
        }
        recursive(left,mid,(many-1)/2,v,last);
        recursive(mid+1,right,(many-1)/2,v,last);
    }
    if(!tek){
        int mid=(left+right)/2;
        recursive(left,mid,(many)/2,v,last);
        recursive(mid+1,right,(many)/2,v,last);
    }
    return;
}

int main() {
    int a,b;
    cin>>a>>b;
    vector<int> v;
    for(int i = 0 ; i < a ; i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    vector<int> last;
    sort(v.begin(),v.end());
    last.push_back(v[0]);
    last.push_back(v[v.size()-1]);
    recursive(1,v.size()-2,b-2,v,last);
    sort(last.begin(),last.end());
    int min = INT32_MAX;
    for(int i = 0 ; i < (last.size() -1 ) ; i++){
        if(last[i+1] - last[i] < min ){
            min = last[i+1] - last[i];
        }
    }
    /*for(int i = 0 ; i < last.size() ; i++){
        cout<<last[i]<<" ";
    }
    cout<<endl;*/
    cout<<min;



	return 0;
}
