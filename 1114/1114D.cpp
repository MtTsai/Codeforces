#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> c;

    int prev_color = -1;
    for (int i = 0; i < n; i++) {
        int c_t;
        cin >> c_t;
        if (c_t != prev_color) {
            c.push_back(c_t);
            prev_color = c_t;
        }
    }
    vector<vector<int>> t(c.size(), vector<int>(2, 0));

    for (int len = 2; len <= c.size(); len++) {
        for (int i = 0; i < c.size() - len + 1; i++) {
            int j = i + len - 1;
            int next[2];
            next[0] = min(min(min(t[i + 1][0] + 1,
                                  t[i][0] + (c[i] != c[j]) * 2),
                                  t[i + 1][1] + (c[i] != c[j])),
                                  t[i][1] + (c[i] != c[j]) + 1);
            next[1] = min(min(min(t[i + 1][0] + (c[i] != c[j]) + 1,
                                  t[i][0] + (c[i] != c[j])),
                                  t[i + 1][1] + (c[i] != c[j]) * 2),
                                  t[i][1] + 1);
            t[i][0] = next[0];
            t[i][1] = next[1];
            // cout << t[i][j][0] << " " << t[i][j][1] << " | ";
        }
        // cout << endl;
    }

    cout << min(t[0][0], t[0][1]) << endl;

    return 0;
}
