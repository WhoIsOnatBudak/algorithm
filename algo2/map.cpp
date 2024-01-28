#include <iostream>
#include <vector>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int sayi;
    cin>>sayi;
    vector<int> v;
    int eleman=0;
    for(int i=0;i<sayi;i++){
      int temp;
      cin>>temp;
      if(temp==1){
        int tel;
        cin>>tel;
        v.push_back(tel);
        eleman=1;
      }
      else if(temp==2){
        if(v.empty()){
            cout<<-1<<"\n";
        }
        else{
           
                    auto maxElement = max_element(v.begin(), v.end());
                    cout << *maxElement << "\n";
                    v.erase(maxElement);
            

            
        }
      }  
    }
    return 0;
}