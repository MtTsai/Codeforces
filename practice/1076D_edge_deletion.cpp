#include <cstring>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct edge {
    int id;
    int to;
    int w;
};

class Dijkstra {
    int n, m, k;

    vector<edge> *l;
    bool *used;
    unsigned long long *d;

public:
    Dijkstra() {
        cin >> n >> m >> k;

        l = new vector<edge>[n + 1];

        used = new bool[n + 1];
        memset(used, 0, sizeof(bool) * (n + 1));

        d = new unsigned long long[n + 1];
        memset(d, 0xFF, sizeof(unsigned long long) * (n + 1));

        int id_n = 1;
        for (int i = 0; i < m; i++) {
            int x, y, w;
            cin >> x >> y >> w;
            l[x].push_back({id_n, y, w});
            l[y].push_back({id_n, x, w});
            id_n++;
        }
    }

    void find_short_path() {
        priority_queue<pair<unsigned long long, int>, vector<pair<unsigned long long, int>>, greater<pair<unsigned long long, int>>> q;

        q.push({0, 1});

        bool *visit = new bool[n + 1];
        for (int i = 0; i < n + 1; i++) {
            visit[i] = false;
        }

        d[1] = 0;
        while (!q.empty()) {
            auto p = q.top();
            q.pop();

            unsigned long long dist = p.first;
            int from = p.second;

            if (visit[from]) {
                continue;
            }
            visit[from] = true;
            for (edge e: l[from]) {
                if (d[e.to] > d[from] + (unsigned long long)e.w) {
                    d[e.to] = d[from] + (unsigned long long)e.w;
                }
                q.push({d[e.to], e.to});
            }
        }

        delete [] visit;
    }

    void out_ans() {
        priority_queue<pair<unsigned long long, int>, vector<pair<unsigned long long, int>>, greater<pair<unsigned long long, int>>> q;

        q.push({0, 1});

        bool *visit = new bool[n + 1];
        for (int i = 0; i < n + 1; i++) {
            visit[i] = false;
        }

        int cnt = 0;
        bool *ans = new bool[m + 1];
        memset(ans, 0, sizeof(bool) * (m + 1));

        while (!q.empty()) {
            auto p = q.top();
            q.pop();

            unsigned long long dist = p.first;
            int from = p.second;

            if (visit[from]) {
                continue;
            }
            visit[from] = true;
            for (edge e: l[from]) {
                if (d[e.to] == d[from] + (unsigned long long)e.w) {
                    if (cnt == k) {
                        break;
                    }
                    if (!used[e.to]) {
                        if (!ans[e.id]) {
                            ans[e.id] = true;
                            cnt++;
                        }
                        used[e.to] = true;
                    }
                }
                q.push({d[e.to], e.to});
            }
        }

        cout << cnt << endl;

        for (int i = 1; i < m + 1; i++) {
            if (ans[i]) {
                cout << i << " ";
            }
        }

        delete [] ans;
        delete [] visit;
    }

    ~Dijkstra() {
        delete [] l;
        delete [] used;
        delete [] d;
    }
};

int main() {
    Dijkstra dijk;

    dijk.find_short_path();
    dijk.out_ans();

    return 0;
}
