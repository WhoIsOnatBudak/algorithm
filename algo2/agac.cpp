#include <iostream>
#include <vector>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int sayi1;
    cin>>sayi1;
    vector<int> v;
    for(int i=0;i<sayi1;i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }



    int sayi=sayi1;
    for(int y=0;y<sayi1;y++){
        vector<int> s;
        int kal=v.size();
        for (int i=0; i<kal; i++){  
            s.push_back(v[i]);
        }

        for(int k=0;k<sayi-1;k++){
            for(int j=0;j<sayi1-1;j++){
                s[j]=s[j]+s[j+1];
                
            }
            s.pop_back();
        }

        sayi--;
        for(int l=0;l<s.size();l++){
            cout<<s[l]<<" ";
        }
        cout<<"\n";
        s.clear();
    }

    return 0;
}