#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int main() {
    int n, m;

    cin >> n >> m;

    unordered_map<int, vector<pair<int, long long>>> edges;

    for (int i = 0; i < m; i++) {
        int v, u;
        long long w;
        cin >> v >> u >> w;

        // w * 2 due to go and back
        edges[v - 1].push_back({u - 1, w * 2});
        edges[u - 1].push_back({v - 1, w * 2});
    }

    vector<bool> vis(n, false);
    vector<long long> ans(n, 0);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;

    for (int i = 0; i < n; i++) {
        long long p;
        cin >> p;
        q.push({p, i});
    }

    while (!q.empty()) {
        long long cost = q.top().first;
        int src = q.top().second;
        q.pop();

        if (vis[src]) continue;
        vis[src] = true;

        // cost from src to attend concert in j
        ans[src] = cost;
        // cout << src << " with cost: " << cost << endl;
        for (auto e: edges[src]) {
            int dst = e.first;
            long long w = e.second;

            q.push({cost + w, dst});
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
}

