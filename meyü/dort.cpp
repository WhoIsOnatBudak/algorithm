    //Brace your keyboard
    //inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

    #include <bits/stdc++.h>

    using namespace std;

    #define MOD 232323233



    int main() {


        int N, M;
        pair<int, int> dp[100005][6];
        map<pair<int, int>, int> safePoints;
        
        cin >> N >> M;
        
        
        for (int i = 0; i < M; i++) {
            int x, y;
            cin >> x >> y;
            safePoints[{x, y}] = 1;  
        }

        
        for (int j = 1; j <= 5; j++) {
            dp[1][j].first = (safePoints.find({1, j}) != safePoints.end());
            dp[1][j].second = 1;  
        }


        for (int i = 1; i < N; i++) {
            for (int j = 1; j <= 5; j++) {
                

                
                for (int dj = -1; dj <= 1; dj++) {
                    int nj = j + dj;
                    if (nj < 1 || nj > 5) continue;

                    int newSafe = (safePoints.find({i + 1, nj}) != safePoints.end());

                    int newPoints = dp[i][j].first + newSafe;
                    if (newPoints > dp[i + 1][nj].first) {
                        dp[i + 1][nj].first = newPoints;
                        dp[i + 1][nj].second = dp[i][j].second;
                    } else if (newPoints == dp[i + 1][nj].first) {
                        dp[i + 1][nj].second = (dp[i + 1][nj].second + dp[i][j].second) % MOD;
                    }
                }
            }
        }


        int maxPoints = 0, ways = 0;
        for (int j = 1; j <= 5; j++) {
            if (dp[N][j].first > maxPoints) {
                maxPoints = dp[N][j].first;
                ways = dp[N][j].second;
            } else if (dp[N][j].first == maxPoints) {
                ways = (ways + dp[N][j].second) % MOD;
            }
        }

        cout << maxPoints << " " << ways << endl;




        return 0;
    }
