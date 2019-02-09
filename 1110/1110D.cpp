#include <iostream>
#include <vector>
#include <map>

using namespace std;

#ifdef DEBUG
void dump(vector<vector<int>> &dp) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << "----" << endl;
}
#else
inline void dump(vector<vector<int>> &dp) {
}
#endif

void sol() {
    int n, m;
    cin >> n >> m;

    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        cnt[a]++;
    }

    int inf = 1e9;
    vector<vector<int>> dp(3, vector<int>(3, -inf));
    dp[0][0] = 0;

    int prev = 0;
    // dp[middle][head]
    for (map<int, int>::iterator it = cnt.begin(); it != cnt.end(); it++) {
        int num   = it->first;
        int tiles = it->second;

        if (num != prev + 1) {
            // not consecutive, clear middle & head count
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (i || j) {
                        dp[i][j] = -inf;
                    }
                }
            }
        }
        vector<vector<int>> next(3, vector<int>(3, -inf));
        for (int i = 0; i < 3; i++) { // tiles used for middle
            for (int j = 0; j < 3; j++) { // tiles used for head
                for (int k = 0; k < 3; k++) { // tiles used for end, end # used = new triple #
                    int tile_used = i + j + k;
                    if (tiles >= tile_used) {
                        int same_triple_num = (tiles - tile_used) / 3;
                        // dp[k][j] (previous triple with k middle # + current k end # + same triple #
                        next[i][j] = max(next[i][j], dp[k][i] + k + same_triple_num);
                    }
                }
            }
        }

        dp = next;
        prev = num;

        dump(dp);
    }

    // Max triple # = no tile used middle & head for the last num
    cout << dp[0][0];
}

void _sol() {
    int n, m;
    cin >> n >> m;

    vector<int> cnt(m + 1, 0);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        cnt[a]++;
    }

    int inf = 1e9;
    vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(3, vector<int>(3, -inf)));

    // dp[num][middle][head]
    dp[0][0][0] = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                dp[i][j][k] = -inf;
                
                // l is the [end #]
                for (int l = 0; l < 3; l++) {
                    int t = j + k + l; // # is used;
                    if (cnt[i] >= t) {
                        int same_tiles_num = (cnt[i] - t) / 3;
                        dp[i][j][k] = max(dp[i][j][k], dp[i - 1][l][j] + l + same_tiles_num);
                    }
                }
            }
        }
        dump(dp[i]);
    }
    cout << dp[m][0][0];
}

int main() {
    sol();

    // memory inefficient
    // _sol();

    return 0;
}
