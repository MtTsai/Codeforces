#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    map<int, int> coupon;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        coupon[x] = max(coupon[x], y);
    }

    vector<int> presum(k + 1, 0);
    for (int i = 0; i < k; i++) {
        presum[i + 1] = presum[i] + a[i];
    }

    vector<int> dp(k + 1, 0);

    for (int i = 1; i <= k; i++) {
        dp[i] = presum[i];
        for (auto c: coupon) {
            int x = c.first, y = c.second;

            if (x > i) break;

            dp[i] = min(dp[i], dp[i - x] + 
                               presum[i] - presum[i - x + y]);
        }
    }

    cout << dp[k] << endl;

    return 0;
}
