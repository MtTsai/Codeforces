#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll n, m, k;
int main() {
    cin >> n >> m >> k;

    vector<pair<ll, ll>> a(n);
    for (int i = 0; i < n; i++) {
        ll t;
        cin >> t;
        a[i] = {t, i};
    }

    sort(a.rbegin(), a.rend());

    vector<ll> prio(n);
    for (int i = 0; i < n; i++) {
        prio[a[i].second] = i;
    }

    ll sum = 0;
    for (int i = 0; i < m * k; i++) {
        sum += a[i].first;
    }
    cout << sum << endl;
    ll cnt = 0;
    for (int i = 0;; i++) {
        while (prio[i] >= m * k) {
            i++;
        }
        cnt++;
        if (cnt == m * k) break;
        if (cnt % m == 0) {
            cout << i + 1 << " ";
        }
    }
    cout << endl;

}
