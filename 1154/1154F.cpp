#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<pair<int, int>> coupon(m);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        coupon[i] = {x, y};
    }

    return 0;
}
