#include <iostream>
#include <vector>
#include <algorithm>

typedef unsigned long long ull;

using namespace std;

int findend(vector<int> &c, int start, int end, int k) {
    int i, n = c.size();
    for (i = min(n, end) - 1; i >= start; i--) {
        if (c[i] >= k) break;
    }
    return i + 1;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> c(n, 0);
    vector<ull> presum(n + 1, 0);
    ull sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    sort(c.rbegin(), c.rend());
    for (int i = 0; i < n; i++) {
        presum[i + 1] = presum[i] + c[i];
    }

    int d;
    for (d = n; d >= 1; d--) {
        // cout << d << "========" << endl;
        sum = 0;
        for (int k = 0; k <= (n - 1) / d; k++) {
            int start = k * d;
            int end   = findend(c, start, start + d, k);

            if (start >= end) break;
            sum += presum[end] - presum[start] - ((end - start) * k);
            // cout << presum[end] << " " << presum[start] << endl;
            // cout << sum << endl;
            // cout << start << " " << end << endl;
        }
        if (sum < m) {
            break;
        }
    }
    if (d == n) {
        cout << -1 << endl;
    }
    else {
        cout << d + 1 << endl;
    }

    return 0;
}
