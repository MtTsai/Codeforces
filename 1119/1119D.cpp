#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef unsigned long long ull;

int main() {
    int n;
    cin >> n;

    vector<ull> t(n);

    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    sort(t.begin(), t.end());

    vector<ull> d, psum(n);
    psum[0] = 0;
    for (int i = 0; i < n - 1; i++) {
        d.push_back(t[i + 1] - t[i]);
    }

    sort(d.begin(), d.end());

    psum[0] = 0;
    for (int i = 0; i < n - 1; i++) {
        psum[i + 1] = psum[i] + d[i];
    }

    int q;
    cin >> q;

    for (int _ = 0; _ < q; _++) {
        ull l, r;
        cin >> l >> r;

        ull range = r - l + 1;

        ull ans = t[n - 1] + range - t[0];

        ull pos = lower_bound(d.begin(), d.end(), range) - d.begin();

        ans -= ((psum[n - 1] - psum[pos]) - (range * (n - 1 - pos)));

        cout << ans << endl;
    }

    return 0;
}
