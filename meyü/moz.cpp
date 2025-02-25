#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<vector<vector<int>>> tiles(4, vector<vector<int>>(N, vector<int>(N)));
    for (int k = 0; k < 4; k++){
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                cin >> tiles[k][i][j];
            }
        }
    }
    vector<vector<vector<vector<int>>>> orientations(4, vector<vector<vector<int>>>(0));
    for (int k = 0; k < 4; k++){
        vector<vector<vector<int>>> orients;
        vector<vector<int>> t0 = tiles[k];
        vector<vector<int>> t1(N, vector<int>(N, 0));
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                t1[j][N - 1 - i] = t0[i][j];
            }
        }
        vector<vector<int>> t2(N, vector<int>(N, 0));
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                t2[j][N - 1 - i] = t1[i][j];
            }
        }
        vector<vector<int>> t3(N, vector<int>(N, 0));
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                t3[j][N - 1 - i] = t2[i][j];
            }
        }
        vector<vector<int>> m0 = t0, m1 = t1, m2 = t2, m3 = t3;
        for (int i = 0; i < N; i++){
            reverse(m0[i].begin(), m0[i].end());
            reverse(m1[i].begin(), m1[i].end());
            reverse(m2[i].begin(), m2[i].end());
            reverse(m3[i].begin(), m3[i].end());
        }
        orients.push_back(t0);
        orients.push_back(t1);
        orients.push_back(t2);
        orients.push_back(t3);
        orients.push_back(m0);
        orients.push_back(m1);
        orients.push_back(m2);
        orients.push_back(m3);
        orientations[k] = orients;
    }
    int M = 2 * N - 1;
    long long answer = 0;
    vector<int> perm = {0, 1, 2, 3};
    do {
        for (int o0 = 0; o0 < 8; o0++){
            for (int o1 = 0; o1 < 8; o1++){
                for (int o2 = 0; o2 < 8; o2++){
                    for (int o3 = 0; o3 < 8; o3++){
                        vector<vector<int>> A = orientations[perm[0]][o0];
                        vector<vector<int>> B = orientations[perm[1]][o1];
                        vector<vector<int>> C = orientations[perm[2]][o2];
                        vector<vector<int>> D = orientations[perm[3]][o3];
                        bool valid = true;
                        for (int i = 0; i < M && valid; i++){
                            for (int j = 0; j < M && valid; j++){
                                int countNonZero = 0;
                                if (i < N && j < N && A[i][j] != 0)
                                    countNonZero++;
                                if (i < N && j >= (N - 1) && (j - (N - 1)) < N && B[i][j - (N - 1)] != 0)
                                    countNonZero++;
                                if (i >= (N - 1) && (i - (N - 1)) < N && j < N && C[i - (N - 1)][j] != 0)
                                    countNonZero++;
                                if (i >= (N - 1) && j >= (N - 1) && (i - (N - 1)) < N && (j - (N - 1)) < N && D[i - (N - 1)][j - (N - 1)] != 0)
                                    countNonZero++;
                                if (countNonZero != 1)
                                    valid = false;
                            }
                        }
                        if (valid)
                            answer++;
                    }
                }
            }
        }
    } while (next_permutation(perm.begin(), perm.end()));
    cout << answer << "\n";
    return 0;
}
