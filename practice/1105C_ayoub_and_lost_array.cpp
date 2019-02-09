#include <iostream>

using namespace std;

typedef unsigned long long ull;

ull mod = 1e9 + 7;

int main() {
    int n, l, r;
    cin >> n >> l >> r;

    ull cnt[3], dp[3];
    for (int i = 0; i < 3; i++) {
        dp[i] = cnt[i] = ((r - i + 3) / 3) - ((l - i - 1 + 3) / 3);
    }

    for (int round = 1; round < n; round++) {
        ull tmp[3] = {0};
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                tmp[i] = (tmp[i] + (dp[j] * cnt[(3 - j + i) % 3] % mod)) % mod;
            }
        }
        for (int i = 0; i < 3; i++) {
            dp[i] = tmp[i];
        }
    }

    cout << dp[0] << endl;

    return 0;
}
