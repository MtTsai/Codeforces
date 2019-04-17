#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int d = a[n - 1] - a[0];
    int d2 = d / 2;

    bool is_match = true;

    if (d % 2 == 0) {
        for (int i = 1; i < n; i++) {
            if (a[i] == a[i - 1]) continue;
            if (a[i] == a[n - 1]) break;

            if (a[i] + d2 != a[n - 1]) {
                is_match = false;
                break;
            }
        }
        if (is_match) {
            cout << d2 << endl;
            return 0;
        }
    }

    is_match = true;
    for (int i = 0; i < n; i++) {
        if (a[i] == a[n - 1]) break;
        if (a[i] + d != a[n - 1]) {
            is_match = false;
            break;
        }
    }

    if (is_match) {
        cout << d << endl;
    }
    else {
        cout << -1 << endl;
    }

    return 0;
}
