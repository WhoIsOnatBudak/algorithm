//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

pair<long long,long long> calcL(vector<pair<long long,pair<long long,long long>>> &mons,long long index,long long att){
    long long damage =0;
    long long money =0;
    long long thres= mons[index].first;
    for(int i=0 ; i < index; i++){
        long long cura = mons[i].first;
        long long curs = mons[i].second.first;
        long long curh = mons[i].second.second;

        long long times;
        if((thres-cura)%curs  == 0 && (thres-cura)>=curs){
            times = ((thres-cura)/curs);
        }
        else{
            times = ((thres-cura)/curs) + 1;
        }

        if(curh >= att){
            long long mod= curh%att;
            curh+=mod;

            if(curh/att < times){
                times = curh/att;
            }
        }


        money+= times;
        damage+= (times*cura) +(curs *((times*(times-1))/2));
        
    }
    return {damage,money};
}

void last(vector<pair<long long,pair<long long,long long>>> &mons,long long index,long long att,long long my){
    priority_queue<pair<long long, pair<long long, long long>>, vector<pair<long long, pair<long long, long long>>>, greater<pair<long long, pair<long long, long long>>>> pq;
    

    long long money =0;
    long long thres= mons[index].first;


    for(int i=0 ; i < index; i++){
        long long damage =0;
        long long cura = mons[i].first;
        long long curs = mons[i].second.first;
        long long curh = mons[i].second.second;

        long long times;
        if((thres-cura)%curs  == 0 && (thres-cura)>=curs){
            times = ((thres-cura)/curs);
        }
        else{
            times = ((thres-cura)/curs) + 1;
        }
        int oldu =0;
        if(curh >= att){
            long long mod= curh%att;
            mod+=curh;

            if(mod/att <= times){
                times = mod/att;
                oldu=1;
            }
        }


        money+= times;
        damage+= (times*cura) +(curs *((times*(times-1))/2));
        //cout<<damage<<" "<<times<<" "<<curs<<"\n";
        my-=damage;
        if(oldu == 0){
            pq.push({cura+(times * curs),{curs,curh-(att*times)}});
        }
        //cout<<my<<" "<<damage<<"\n";
        
    }
    pq.push(mons[index]);

    while(!pq.empty()){
            long long attack = pq.top().first;
            long long scale = pq.top().second.first;
            long long healt = pq.top().second.second;
            pq.pop();

            if(attack>=my){
                break;
            }
            money++;
            my -=attack;

            healt -=att;
            attack+=scale;
            if(healt > 0){pq.push({attack,{scale,healt}});}
            


        }
    cout<<money<<"\n";

    return;
}

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
        //priority_queue<pair<long long, pair<long long, long long>>, vector<pair<long long, pair<long long, long long>>>, greater<pair<long long, pair<long long, long long>>>> pq;
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

        sort(mons.begin(),mons.end());

        
        long long left = 0, right = m-1;

        while (left < right) {
            long long mid = (left + right) / 2;
            long long damage, money;
            tie(damage, money) = calcL(mons, mid, at);

            if (damage > heal) {
                right = mid;
            } else {
                left = mid + 1;
            }
            cout<<"mid: "<<calcL(mons,mid,at).first<<" heal: "<<heal<<"\n";
            //cout<<left<<" "<<right<<"\n";
        }

        
        //cout<<calcL(mons,left,at).first<<" "<<heal<<"\n";
        //last cal
        last(mons,left,at,heal);




        
    }

	return 0;
}
