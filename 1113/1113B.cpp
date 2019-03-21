#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);

    int power = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        power += a[i];
    }

    sort(a.begin(), a.end());

    int ans = power;
    for (int i = 1; i < n; i++) {
        for (int j = 2; j <= a[i]; j++) {
            if (a[i] % j == 0) {
                int x = a[i] / j;
                int new_power = power - a[i] - a[0] + (a[i] / x) + (a[0] * x);
                ans = min(ans, new_power);
                // cout << i << ", " << j << ": " << new_power << endl;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
