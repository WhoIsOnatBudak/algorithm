    //Brace your keyboard
    //inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

    #include <bits/stdc++.h>

    using namespace std;



    int main() {
        int t;
        cin>>t;
        while(t>0){
            int count;
            cin>>count;
            set<int> a;
            set<int> b;

            for(int i = 0 ; i < count; i++){

                int temp;
                cin>>temp;
                a.insert(temp);

            }

            for(int i = 0 ; i < count; i++){

                int temp;
                cin>>temp;
                b.insert(temp);

            }
            if(a.size()+ b.size()>=4){
                cout<<"yes"<<"\n";
            }
            else{
                cout<<"no"<<"\n";
            }

            t--;
        }


        return 0;
    }
