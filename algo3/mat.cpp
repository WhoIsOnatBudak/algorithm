#include <iostream>
#include <vector>

using namespace std;

int main(){
    int l = 18;
    vector<int> origin;
    vector<int> mainn;
    vector<int> first;
    vector<int> second;

    bool yes = 1;
    for(int i = 0; i < l; i++){
        mainn.push_back(i+1);
        origin.push_back(i+1);
    }
    int shf = 0;
    while(yes){
        first.clear();
        second.clear();
        int t = 0;
        int f = 0;
        int s = 0;
        shf++;
        for(int i = 0; i < l/2;i++){
            first.push_back(mainn[i]);
        }
        for(int i = 0; i < l/2;i++){
            second.push_back(mainn[i+(l/2)]);
        }
        for(int i = 0; i < l;i++){
            if(f==s){
                mainn[i]=second[s];
                s++;
            }
            else if(f < s ){
                mainn[i]=first[f];
                f++;
            }
        }
        for(int i = 0; i < l; i++){
            if(mainn[i]!=origin[i]){
                break;
            }
            t++;
        }
        //print
        /*for(int i = 0; i < mainn.size();i++){
            std::cout<<mainn[i]<<endl;
        }*/
        if(t == l){
            yes = 0;
        }
    }
    std::cout<<shf;


}