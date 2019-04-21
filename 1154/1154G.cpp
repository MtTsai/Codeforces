#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

#define N ((int)1e7 + 1)

int idx[N];

int main() {
    ll n;
    cin >> n;

    int maxn = 0;
    ll min_lcm = -1, ans_i = 0, ans_j = 0;
    for (ll i = 1; i <= n; i++) {
        int t;
        cin >> t;

        maxn = max(maxn, t);
        if (!idx[t]) {
            idx[t] = i;
        }
        else {
            if (min_lcm < 0 || min_lcm > t) {
                min_lcm = t;
                ans_i = i, ans_j = idx[t];
            }
        }
    }

    for (ll gcd = 1; gcd <= maxn; gcd++) {
        ll x = -1, y = -1;
        for (ll t = gcd; t <= maxn; t += gcd) {
            if (!idx[t]) continue;

            if (x < 0) {
                x = t; continue;
            }
            if (y < 0) {
                y = t;

                ll lcm = x * y / gcd; 
                if (min_lcm < 0 || lcm < min_lcm) {
                    min_lcm = lcm;
                    ans_i = idx[x], ans_j = idx[y];
                }
                break;
            }
        }
    }

    if (ans_i > ans_j) {
        swap(ans_i, ans_j);
    }

    cout << ans_i << " " << ans_j << endl;

    return 0;
}
