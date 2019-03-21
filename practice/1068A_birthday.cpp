#include <iostream>

using namespace std;

int main() {
    long long n, m, k, l;

    cin >> n >> m >> k >> l;

    long long maxc = n / m;

    if (maxc == 0) {
        cout << -1;
    }
    else {
        long long need  = l + k;
        if ((maxc * m) < need) {
            cout << -1;
        }
        else {
            long long ans = need / m;
            if (need % m) {
                cout << ans + 1;
            }
            else {
                cout << ans;
            }
        }
    }

    return 0;
}
