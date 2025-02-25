//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;


    vector<vector<vector<int>>> intro (4,vector<vector<int>>(n,vector<int>(n)));
    for(int i = 0 ; i < 4 ; i++){
        for(int j = 0 ; j < n ; j++){
            for(int k = 0 ; k < n;k++){
                int temp;
                cin >> temp;
                intro[i][j][k]=temp;
            }
        }
    }

    vector<vector<vector<vector<int>>>> hepsi(4, vector<vector<vector<int>>>(0));
    for (int k = 0; k < 4; k++){
        vector<vector<vector<int>>> don;
        vector<vector<int>> t0 = intro[k];
        vector<vector<int>> t1(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                t1[j][n - 1 - i] = t0[i][j];
            }
        }
        vector<vector<int>> t2(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                t2[j][n - 1 - i] = t1[i][j];
            }
        }
        vector<vector<int>> t3(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                t3[j][n - 1 - i] = t2[i][j];
            }
        }
        vector<vector<int>> m0 = t0, m1 = t1, m2 = t2, m3 = t3;
        for (int i = 0; i < n; i++){
            reverse(m0[i].begin(), m0[i].end());
            reverse(m1[i].begin(), m1[i].end());
            reverse(m2[i].begin(), m2[i].end());
            reverse(m3[i].begin(), m3[i].end());
        }
        don.push_back(t0);
        don.push_back(t1);
        don.push_back(t2);
        don.push_back(t3);
        don.push_back(m0);
        don.push_back(m1);
        don.push_back(m2);
        don.push_back(m3);
        hepsi[k] = don;
    }
    int p = 2 * n - 1;
    long long answer = 0;
    vector<int> perm = {0, 1, 2, 3};



	do {
        for (int o0 = 0; o0 < 8; o0++){
            for (int o1 = 0; o1 < 8; o1++){
                for (int o2 = 0; o2 < 8; o2++){
                    for (int o3 = 0; o3 < 8; o3++){
                        vector<vector<int>> A = hepsi[perm[0]][o0];
                        vector<vector<int>> B = hepsi[perm[1]][o1];
                        vector<vector<int>> C = hepsi[perm[2]][o2];
                        vector<vector<int>> D = hepsi[perm[3]][o3];
                        bool gec = true;
                        for (int i = 0; i < p && gec; i++){
                            for (int j = 0; j < p && gec; j++){
                                int zc = 0;
                                if (i < n && j < n && A[i][j] != 0)
                                    zc++;
                                if (i < n && j >= (n - 1) && (j - (n - 1)) < n && B[i][j - (n - 1)] != 0)
                                    zc++;
                                if (i >= (n - 1) && (i - (n - 1)) < n && j < n && C[i - (n - 1)][j] != 0)
                                    zc++;
                                if (i >= (n - 1) && j >= (n - 1) && (i - (n - 1)) < n && (j - (n - 1)) < n && D[i - (n - 1)][j - (n - 1)] != 0)
                                    zc++;
                                if (zc != 1)
                                    gec = false;
                            }
                        }
                        if (gec)
                            answer++;
                    }
                }
            }
        }
    } while (next_permutation(perm.begin(), perm.end()));
    cout << answer << "\n";
    return 0;
}
