#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> s(n);
    vector<int> r(n), l(n);
    vector<int> t(n, 0);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        s[i] = {a, i};
        r[i] = i + 1;
        l[i] = i - 1;
    }

    sort(s.rbegin(), s.rend());

    int turn = 0;
    for (int i = 0; i < n; i++) {
        int idx = s[i].second;
        if (t[idx] != 0) continue;

        int team = (turn % 2) + 1;
        turn++;

        t[idx] = team;
        int ridx = idx + 1;
        for (int j = 1; j <= k; j++) {
            while (ridx < n && t[ridx] != 0) ridx = r[ridx];
            if (ridx >= n) break;
            t[ridx] = team;
        }
        int lidx = idx - 1;
        for (int j = 1; j <= k; j++) {
            while (lidx >= 0 && t[lidx] != 0) lidx = l[lidx];
            if (lidx < 0) break;
            t[lidx] = team;
        }
        if (lidx >= 0) {
            r[lidx] = ridx + 1;
        }
        if (ridx < n) {
            l[ridx] = lidx - 1;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << t[i];
    }
    cout << endl;

    return 0;
}
