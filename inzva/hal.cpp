//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long t;
    cin>>t;
    for(int i = 0 ; i< t ; i++){
        long long m;
        cin>>m;
        long long heal;
        cin>>heal;
        long long at;
        cin>>at;

        //at,sclae,health
        priority_queue<pair<long long, pair<long long, long long>>, vector<pair<long long, pair<long long, long long>>>, greater<pair<long long, pair<long long, long long>>>> pq;
        vector<pair<long long,pair<long long,long long>>> mons(m);
        
        for(long long k = 0 ; k < m ; k++){
            long long temp;
            cin>>temp;
            mons[k].second.second=temp;
        }
        for(long long k = 0 ; k < m ; k++){
            long long temp;
            cin>>temp;
            mons[k].first=temp;
        }
        for(long long k = 0 ; k < m ; k++){
            long long temp;
            cin>>temp;
            mons[k].second.first=temp;
        }

        for(long long j = 0 ; j < m; j++){
            if(mons[j].first < heal){pq.push(mons[j]);}
            
        }
        sort(mons.begin(),mons.end());
        long long col=0;
        //int go =1;
        /*while(!pq.empty() || !test.empty()){

            pair<long long, pair<long long, long long>> curr;


            if (!pq.empty() && (test.empty() || pq.top() < test.top())) {
                curr = pq.top();
                pq.pop();
            } else {
                curr = test.top();
                test.pop();
            }



            long long attack = curr.first;
            long long scale = curr.second.first;
            long long healt = curr.second.second;

            if(attack>=heal){
                break;
            }
            col++;
            heal -=attack;

            healt -=at;
            attack+=scale;
            if (healt > 0 && attack < heal && test.size() < pq.size()) {
                test.push({attack, {scale, healt}});
            }
            else if (healt > 0 && attack < heal && test.size() >= pq.size()) {
                pq.push({attack, {scale, healt}});
            }
            


        }
        cout<<col<<"\n";*/
        
    }

	return 0;
}
