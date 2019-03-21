#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> c(n, 0);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        sum += c[i];
    }
    sort(c.rbegin(), c.rend());

    if (sum < m) {
        cout << -1 << endl;
    }
    else {
        int d;
        for (d = n - 1; d >= 1; d--) {
            sum = 0;
            for (int j = 0; j < n; j++) {
                int t = max(0, c[j] - j / d);
                if (t == 0) break;
                sum += t;
            }
            if (sum < m) {
                break;
            }
        }
        cout << d + 1 << endl;
    }

    return 0;
}
