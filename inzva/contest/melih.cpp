    //Brace your keyboard
    //inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

    #include <bits/stdc++.h>

    using namespace std;



    int main() {
        int low,high;

        cin>>low>>high;

        int chan;
        cin>>chan;

        string ilk,iki;
        cin>>ilk>>iki;

        low = min(low,high);

        vector<int> seq;

        int counter = 0;
        for(int i = 0 ; i < low ; i++){
            if(ilk[i] == iki[i]){
                counter++;
            }
            if(ilk[i] != iki[i] && counter >0){
                seq.push_back(counter);
                seq.push_back(0);
                counter =0;
            }
            else if(ilk[i] != iki[i] && counter == 0){
                seq.push_back(counter);
            }
        }
        if(counter > 0){
            seq.push_back(counter);
        }
        /*
        for(int i = 0 ; i < seq.size(); i++){
            cout<<seq[i]<<" ";
        }*/
        
        
        int max = 0;
        for(int i = 0 ; i < seq.size(); i++){
            int times = chan;
            int sum=0;
            int index = i;
            while(times > 0 && index < seq.size()){
                if(seq[index] !=0){
                    sum+= seq[index];
                }

                else if(seq[index] == 0){
                    sum++;
                    times--;
                }
                index++;
                if(times == 0 && index < seq.size()){
                    if(seq[index]!=0){
                        sum += seq[index];
                    }
                }
            }
            
            if(sum>max){
                    max = sum;
            }
        }
        cout<<max;
        
        
        



        return 0;
    }
