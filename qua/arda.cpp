//Even our problem setter cannot nail this everytime. No giving up!
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;


int getValue(string name, long long value[]){
    long long re = 0;
    for(char c : name){
        re += value[c - 'a'];
        re= re % 101;
    }
    return re;
}

int main() {
	long long value[26];

    for(int i = 0 ; i < 26 ; i++){
        int temp;
        cin>>temp;
        value[i] = temp;
    }

    map<long long,int> ratingUsed;
    map<long long,string> rating;

    int count;
    cin>>count;

    for(long long i = 0 ; i < count ; i++){
        int type;
        cin>>type;
        if(type == 1){
            string name;
            cin>>name;
            int points = getValue(name,value);

            if(ratingUsed[points] == 0){
                ratingUsed[points] =1;
                rating[points] = name;
                cout<<points<<"\n";
            }
            else if(ratingUsed[points+1] == 0){
                ratingUsed[points+1] =1;
                rating[points + 1] = name;
                cout<<points+1<<"\n";
            }
            else if(ratingUsed[points+4] == 0){
                ratingUsed[points+4] =1;
                rating[points + 4] = name;
                cout<<points+4<<"\n";
            }
            else if(ratingUsed[points+9] == 0){
                ratingUsed[points+9] =1;
                rating[points + 9] = name;
                cout<<points+9<<"\n";
            }
            else{
                ratingUsed[points] =1;
                rating[points] = name;
                cout<<points<<"\n";
            }

        }
        else if(type == 2){
            long long goster;
            cin>>goster;
            if (rating.find(goster) != rating.end()) {
                cout << rating[goster] << "\n";
            } else {
                cout << "ah be abi\n"; // Message when the rating does not exist
            }
        }
    }


	return 0;
}

