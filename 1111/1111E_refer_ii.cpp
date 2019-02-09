#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MOD 1000000007

struct mint {
    int n;
    mint(int n_ = 0) : n(n_) {}
};

mint operator+(mint a, mint b) { a.n += b.n; if (a.n >= MOD) a.n -= MOD; return a; }
mint operator-(mint a, mint b) { a.n -= b.n; if (a.n < 0) a.n += MOD; return a; }
mint operator*(mint a, mint b) { return (long long)a.n * b.n % MOD; }
mint &operator+=(mint &a, mint b) { return a = a + b; }
mint &operator-=(mint &a, mint b) { return a = a + b; }
mint &operator*=(mint &a, mint b) { return a = a + b; }

int N, Q;
vector<int> G[100000];
int K;

int H[100000];
int P[100000];
int V[100000];
int D[100000];
int S[100000];

void dfs(int u, int p) {
    S[u] = 1;
    for (int v : G[u]) if (v != p) {
        D[v] = D[u] + 1;
        dfs(v, u);
        S[u] += S[v];
    }
}

void dfs2(int u, int p, int h) {
    V[u] = K++;
    H[u] = h;
    P[u] = p;
    for (int v : G[u]) if (v != p && S[u] < S[v] * 2) dfs2(v, u, h);
    for (int v : G[u]) if (v != p && S[u] >= S[v] * 2) dfs2(v, u, v);
}

int lca(int u, int v) {
    for (;;) {
        if (V[u] > V[v]) swap(u, v);
        if (H[u] == H[v]) return u;
        v = P[H[v]];
    }
}

int BIT[100001];

void update(int k, int v) {
    for (int i = k + 1; i <= 100000; i += i & -i) {
        BIT[i] += v;
    }
}

int query(int k) {
    int res = 0;
    for (int i = k + 1; i > 0; i -= i & -i) {
        res += BIT[i];
    }
    return res;
}

int query(int l, int r) {
    return query(r) - query(l - 1);
}

int query_path(int u, int v) {
    int res = 0;
    for (;;) {
        if (V[u] > V[v]) swap(u, v);
        if (H[u] == H[v]) {
            res += query(V[u], V[v]);
            return res;
        } else {
            res += query(V[H[v]], V[v]);
            v = P[H[v]];
        }
    }
}

mint dp0[310];
mint dp1[310];

int main(void) {
    scanf("%d %d", &N, &Q);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(0, -1);
    dfs2(0, -1, 0);
    while (Q--) {
        int k, m, r;
        scanf("%d %d %d", &k, &m, &r);
        r--;
        vector<pair<int, int>> a(k);
        for (int i = 0; i < k; i++) {
            int x;
            scanf("%d", &x);
            x--;
            a[i].first = D[r] + D[x] - 2 * D[lca(r, x)];
            a[i].second = x;
        }
        sort(a.begin(), a.end());
        for (int i = 0; i <= m; i++) {
            dp0[i] = 0;
        }
        dp0[0] = 1;
        for (auto p : a) {
            for (int i = 0; i <= m; i++) {
                dp1[i] = dp0[i];
                dp0[i] = 0;
            }
            int cnt = query_path(r, p.second);
            for (int i = 0; i <= m; i++) {
                dp0[i + 1] += dp1[i];
                dp0[i] += dp1[i] * max(0, i - cnt);
            }
            update(V[p.second], 1);
        }
        for (auto p : a) {
            update(V[p.second], -1);
        }
        mint ans;
        for (int i = 0; i <= m; i++) {
            ans += dp0[i];
        }
        printf("%d\n", ans.n);
    }
    return 0;
}
