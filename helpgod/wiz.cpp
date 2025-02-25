#include <bits/stdc++.h>

using namespace std;




int main() {
    string a, b;
    cin >> a >> b;

    int odd = 1;
    int even = 2;

    vector<int> v(2500,0);

    int lastA=0;
    int lastB=0;
    
    int as = a.size();
    int bs = b.size();

    if(as>bs){
        for(int i = 0 ; i < bs ; i++){
            char curA = a[i];
            char curB = b[i];

            if( curA == curB && curB == 'O'){
                if(lastA%2 == 0){
                    while(v[lastA + 1] == 1){
                        lastA+=2;
                    }
                    lastA++;
                    v[lastA]++;
                }
                else{
                    while(v[lastA + 2] == 1){
                        lastA+=2;
                    }
                    lastA+=2;
                    v[lastA]++;
                }
                if(lastB%2 == 0){
                    while(v[lastB + 1] == 1){
                        lastB+=2;
                    }
                    lastB++;
                    v[lastB]++;
                }
                else{
                    while(v[lastB + 2] == 1){
                        lastB+=2;
                    }
                    lastB+=2;
                    v[lastB]++;
                }
            }
            if( curA == curB && curB == 'E'){
                if(lastA%2 == 0){
                    while(v[lastA + 2] == 1){
                        lastA+=2;
                    }
                    lastA+=2;
                    v[lastA]++;
                }
                else{
                    while(v[lastA + 1] == 1){
                        lastA+=2;
                    }
                    lastA++;
                    v[lastA]++;
                }
                if(lastB%2 == 0){
                    while(v[lastB + 2] == 1){
                        lastB+=2;
                    }
                    lastB +=2;
                    v[lastB]++;
                }
                else{
                    while(v[lastB + 1] == 1){
                        lastB+=2;
                    }
                    lastB++;
                    v[lastB]++;
                }
            }



            if( curA != curB && curB == 'O'){
                if(lastA%2 == 0){
                    while(v[lastA + 2] == 1){
                        lastA+=2;
                    }
                    lastA+=2;
                    v[lastA]++;
                }
                else{
                    while(v[lastA + 1] == 1){
                        lastA+=2;
                    }
                    lastA++;
                    v[lastA]++;
                }


                if(lastB%2 == 0){
                    while(v[lastB + 1] == 1){
                        lastB+=2;
                    }
                    lastB++;
                    v[lastB]++;
                }
                else{
                    while(v[lastB + 2] == 1){
                        lastB+=2;
                    }
                    lastB+=2;
                    v[lastB]++;
                }
            }


            if( curA != curB && curB == 'E'){
                if(lastA%2 == 0){
                    while(v[lastA + 1] == 1){
                        lastA+=2;
                    }
                    lastA++;
                    v[lastA]++;
                }
                else{
                    while(v[lastA + 2] == 1){
                        lastA+=2;
                    }
                    lastA++;
                    v[lastA]++;
                }


                if(lastB%2 == 0){
                    while(v[lastB + 2] == 1){
                        lastB+=2;
                    }
                    lastB +=2;
                    v[lastB]++;
                }
                else{
                    while(v[lastB + 1] == 1){
                        lastB+=2;
                    }
                    lastB++;
                    v[lastB]++;
                }
            }
            
        }
    }

    if(as<=bs){
        for(int i = 0 ; i < bs ; i++){
            char curA = a[i];
            char curB = b[i];

            if( curA == curB && curB == 'O'){

                if(lastB%2 == 0){
                    while(v[lastB + 1] == 1){
                        lastB+=2;
                    }
                    lastB++;
                    v[lastB]++;
                }
                else{
                    while(v[lastB + 2] == 1){
                        lastB+=2;
                    }
                    lastB+=2;
                    v[lastB]++;
                }
                                if(lastA%2 == 0){
                    while(v[lastA + 1] == 1){
                        lastA+=2;
                    }
                    lastA++;
                    v[lastA]++;
                }
                else{
                    while(v[lastA + 2] == 1){
                        lastA+=2;
                    }
                    lastA+=2;
                    v[lastA]++;
                }
            }
            if( curA == curB && curB == 'E'){

                if(lastB%2 == 0){
                    while(v[lastB + 2] == 1){
                        lastB+=2;
                    }
                    lastB +=2;
                    v[lastB]++;
                }
                else{
                    while(v[lastB + 1] == 1){
                        lastB+=2;
                    }
                    lastB++;
                    v[lastB]++;
                }
                                if(lastA%2 == 0){
                    while(v[lastA + 2] == 1){
                        lastA+=2;
                    }
                    lastA+=2;
                    v[lastA]++;
                }
                else{
                    while(v[lastA + 1] == 1){
                        lastA+=2;
                    }
                    lastA++;
                    v[lastA]++;
                }
            }



            if( curA != curB && curB == 'O'){



                if(lastB%2 == 0){
                    while(v[lastB + 1] == 1){
                        lastB+=2;
                    }
                    lastB++;
                    v[lastB]++;
                }
                else{
                    while(v[lastB + 2] == 1){
                        lastB+=2;
                    }
                    lastB+=2;
                    v[lastB]++;
                }
                                if(lastA%2 == 0){
                    while(v[lastA + 2] == 1){
                        lastA+=2;
                    }
                    lastA+=2;
                    v[lastA]++;
                }
                else{
                    while(v[lastA + 1] == 1){
                        lastA+=2;
                    }
                    lastA++;
                    v[lastA]++;
                }
            }


            if( curA != curB && curB == 'E'){
                


                if(lastB%2 == 0){
                    while(v[lastB + 2] == 1){
                        lastB+=2;
                    }
                    lastB +=2;
                    v[lastB]++;
                }
                else{
                    while(v[lastB + 1] == 1){
                        lastB+=2;
                    }
                    lastB++;
                    v[lastB]++;
                }
                if(lastA%2 == 0){
                    while(v[lastA + 1] == 1){
                        lastA+=2;
                    }
                    lastA++;
                    v[lastA]++;
                }
                else{
                    while(v[lastA + 2] == 1){
                        lastA+=2;
                    }
                    lastA++;
                    v[lastA]++;
                }
            }
            
        }

        while(bs > as){
            char anlikB = b[as];
            if(anlikB == 'O')
            {   
                if(lastB%2 == 0){
                        while(v[lastB + 1] == 1){
                            lastB+=2;
                        }
                        lastB++;
                        v[lastB]++;
                    }
                else{
                        while(v[lastB + 2] == 1){
                            lastB+=2;
                        }
                        lastB+=2;
                        v[lastB]++;
                }
            }
            if(anlikB == 'E')
            {   
                if(lastB%2 == 0){
                        while(v[lastB + 2] == 1){
                            lastB+=2;
                        }
                        lastB+=2;
                        v[lastB]++;
                    }
                else{
                        while(v[lastB + 1] == 1){
                            lastB+=2;
                        }
                        lastB++;
                        v[lastB]++;
                }
            }
            as++;
            
        }
        
    }

    while(bs < as){
            char anlikA = a[bs];
            if(anlikA == 'O')
            {   
                if(lastB%2 == 0){
                        while(v[lastA + 1] == 1){
                            lastA+=2;
                        }
                        lastA++;
                        v[lastA]++;
                    }
                else{
                        while(v[lastA + 2] == 1){
                            lastA+=2;
                        }
                        lastA+=2;
                        v[lastA]++;
                }
            }
            if(anlikA == 'E')
            {   
                if(lastB%2 == 0){
                        while(v[lastA + 2] == 1){
                            lastA+=2;
                        }
                        lastA+=2;
                        v[lastA]++;
                    }
                else{
                        while(v[lastA + 1] == 1){
                            lastA+=2;
                        }
                        lastA++;
                        v[lastA]++;
                }
            }
            bs++;
            
        }
    cout<<max(lastB,lastA);




    return 0;
}
