#include <iostream>
#include <vector>

using namespace std;

const long long MOD = 1000000007;


int main() {
    long long count;
    cin>>count;
    string hop;
    cin>>hop;
    long long o =0;
    long long s=0;
    long long m=0;
    long long a=0;
    long long n=0;

    vector<vector<long long>> v(5);
    for(long long i = 0 ; i < count; i++){
        char temp = hop[i];
        if(temp == 'o'){
            o++;
        }
        else if(temp == 's'){
            s+=o;
            s=s%MOD;
        }
        else if(temp == 'm'){
            m+=s;
            m = m % MOD;
        }
        else if(temp == 'a'){
            a+=m;
            a= a%MOD;
        }
        else if(temp == 'n'){
            n+=a;
            n = n % MOD;
        }
        else{
            int sayi = temp - '0';
            if(sayi==1){
                n+=a;
                a+=m;
                m+=s;
                s+=o;
                o++;
            }
            if(sayi==2){
                n+=m;
                a+=s;
                m+=o;
                s++;
            }
            if(sayi == 3){
                n+=s;
                a+=o;
                m++;
            }
            if(sayi == 4){
                n+=o;
                a++;
            }
            if(sayi == 5){
                n++;
            }
        }
    }
    cout<<n;
    return 0;
}
