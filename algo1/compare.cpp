#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h> 

using namespace std;

class Cow_index{
    private:
    public:
        string name;
        int index;
        Cow_index(string nam,int in){
            name=nam;
            index=in;
        }
};
class cowCompare{
    public:
        bool operator()(Cow_index &fir,Cow_index &sec){
            if(fir.index<sec.index){
                return true;
            }
            else{
                return false;
            }
        }
};

int main(){
    Cow_index ilk("kemal",8);
    Cow_index iki("ertugrul",9);
    Cow_index uc("enes",8);
    Cow_index dort("onat",5);
    cowCompare cc;
    vector<Cow_index> v;
    v.push_back(ilk);
    v.push_back(iki);
    v.push_back(uc);
    v.push_back(dort);
    sort(v.begin(),v.end(),cc);
    cout<<v.front().name;
    vector<int> v1 {1,2,4,3};
    sort(v1.begin(),v1.end());
    cout<<v1[2];



}