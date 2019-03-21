#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<char> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    vector<vector<int>> dp(n, vector<int>(n, 1));

    for (int l = 2; l <= n; l++) {
        for (int i = 0; i + l <= n; i++) {
            int j = i + l - 1;
            dp[i][j] = min(dp[i + 1][j] + !(s[i] == s[i + 1] || s[i] == s[j]),
                           dp[i][j - 1] + !(s[j] == s[j - 1] || s[j] == s[i]));
            for (int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
            }
        }
    }

    cout << dp[0][n - 1] << endl;

    return 0;
}
