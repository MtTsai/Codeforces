#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int n, q;
int k, m, r;
unordered_map<int, vector<int>> m;
unordered_map<int, bool> vis;

vector<int> dfs(int cur, unordered_set<int> &a) {
    vector<int> p(m, 0);

    vis[cur] = true;

    for (auto dst: m[cur]) {
        if (!vis[dst]) {
            vector<int> p_child = dfs(dst, a);
            vector<int> tmp(m);
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < m; j++) {
                    if (i + j < m) {
                        p[i]
                    }
                }
            }
        }
    }
    if (a.count(cur)) {
    }

    vis[cur] = false;
}

int main() {
    cin >> n >> q;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;

        m[u].push_back(v);
        m[v].push_back(u);

        vis[u] = vis[v] = false;
    }

    for (int i = 0; i < q; i++) {
        cin >> k >> m >> r;

        unordered_set<int> a;

        for (int j = 0; j < k; j++) {
            int t;
            cin >> t;
            a.insert(t);
        }

        vector<int> p = dfs(r, a);
    }

    
    return 0;
}
