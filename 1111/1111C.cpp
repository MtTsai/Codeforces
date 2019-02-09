#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef unsigned long long ll;

ll n, k, A, B;

ll _na(int l, int r, vector<int> &a) {
    int lidx = lower_bound(a.begin(), a.end(), l + 1) - a.begin();
    int ridx = lower_bound(a.begin(), a.end(), r + 1) - a.begin();

    return ridx - lidx;
}

ll power(int l, int r, vector<int> &a) {
    ll na = _na(l, r, a);
    ll p2 = (na == 0) ? A : B * na * (r - l);

    if (r - l == 1 || na == 0) return p2;

    ll p1 = power(l, (l + r) / 2, a) + power((l + r) / 2, r, a);

    return (p1 < p2) ? p1 : p2;
}

int main() {
    cin >> n >> k >> A >> B;

    vector<int> a(k);
    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    cout << power(0, 1 << n, a) << endl;

    return 0;
}
