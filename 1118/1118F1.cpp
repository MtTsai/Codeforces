#include <iostream>
#include <vector>

using namespace std;

vector<int> color;
vector<vector<int>> num;
vector<vector<int>> edge;

void dfs(int i, int p) {
    for (int dst: edge[i]) {
        if (dst != p) {
            dfs(dst, i);
            num[i][0] += num[dst][0];
            num[i][1] += num[dst][1];
            num[i][2] += num[dst][2];
        }
    }
    num[i][color[i]]++;
}

int main() {
    int n;
    cin >> n;

    color = vector<int>(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> color[i];
    }

    num  = vector<vector<int>>(n, vector<int>(3, 0));
    edge = vector<vector<int>>(n);
    for (int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;
        v--; u--;
        edge[v].push_back(u);
        edge[u].push_back(v);
    }

    dfs(0, -1);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        // cout << num[i][0] << " " << num[i][1] << " " << num[i][2] << endl;
        if ((num[i][1] && !num[i][2]) &&
            (!(num[0][1] - num[i][1]) &&
             (num[0][2] - num[i][2]))) {
                ans++;
        }
        else if ((!num[i][1] && num[i][2]) &&
                 ((num[0][1] - num[i][1]) &&
                  !(num[0][2] - num[i][2]))) {
                ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
