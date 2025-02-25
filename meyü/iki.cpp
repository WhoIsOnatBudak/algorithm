//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    int test;
    cin>>test;
    while(test>0){

        int n;
        cin>>n;
        vector<int> a(n);
        vector<int> b(n);


        for(int i = 0 ; i < n;i++){
            int temp;
            cin>>temp;
            a[i] = temp;
        }
        for(int i = 0 ; i < n;i++){
            int temp;
            cin>>temp;
            b[i] = temp;
        }

        
        int ia=0;
        int ib=0;
        long long ans=0;

        while(ia < n && ib < n){

            
            if(a[ia] == b[ib]){
                if(ia <= ib){
                    if(ia < n-1 && a[ia+1] == a[ia]){
                        ans+=(ia+1)*(ib+1);
                        ia++;
                    }
                    else{
                        ans+=(ia+1)*(ib+1);
                        ib++;
                    }
                }
                else if(ib < ia){
                    if(ib < n-1 && b[ib+1] == b[ib]){
                        ans+=(ia+1)*(ib+1);
                        ib++;
                    }
                    else{
                        ans+=(ia+1)*(ib+1);
                        ia++;
                    }
                }

            }






            else if(a[ia] < b[ib]){
                ia++;
            }
            else if(a[ia] > b[ib]){
                ib++;
            }
            
        }
        cout<<ans<<"\n";



        test--;
    }

	return 0;
}






