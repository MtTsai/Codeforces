#include <iostream>
#include <string>
#include <cmath>

using namespace std;

typedef unsigned long long ll;
#define MOD ((ll)((1e9) + 7))

int m[52] = {0};
int vis[52] = {0};
int n;
int tx, ty;

// trans
int T(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a';
    }
    else {
        return c - 'A' + 26;
    }
}

ll ar(int x, int y) {
    ll ret = (ll)pow((x + 1), y) % MOD;
    // cout << x << " - " << y << ": " << ret << endl;
    return ret;
}

ll dfs(int total, int p) {
    ll ret = 0;

    // cout << total << " " << p << endl;

    if (total == n/2) {
        for (int i = 0; i < 52; i++) {
            if (!vis[i] && m[i]) {
                ret = ar(m[i], ret);
            }
        }
        ret = (ret * p) % MOD;
    }
    else if (total > n / 2) {
        return 0;
    }
    else {
        for (int i = 0; i < 52; i++) {
            if (!vis[i] && m[i]) {
                vis[i] = 1;
                ret += dfs(total + m[i], ar(total, m[i]));
                vis[i] = 0;
            }
        }
    }

    // cout << "ret  = " << ret << endl;
    return ret;
}

int main() {
    string s;
    cin >> s;
    n = s.size();
    for (auto c: s) {
        m[T(c)]++;
    }

    int q; cin >> q;
    for (int _q = 0; _q < q; _q++) {
        int x, y;
        cin >> x >> y;

        tx = T(s[x - 1]);
        ty = T(s[y - 1]);
        int numX = m[tx], numY = m[ty];
        if (tx == ty) numY = 0;

        // cout << numX + numY << endl;
        if ((numX + numY) > (n / 2)) {
            cout << 0 << endl;
            continue;
        }

        vis[tx] = vis[ty] = 1;

        ll ans = dfs(numX + numY, ar(numX, numY));
        cout << (ans * 2) % MOD << endl;

        vis[tx] = vis[ty] = 0;
    }

    return 0;
}
