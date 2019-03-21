#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef unsigned long long ull;

int main() {
    int n, m;
    cin >> n;

    vector<int> a(n);
    ull sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a.rbegin(), a.rend());

    cin >> m;
    for (int i = 0; i < m; i++) {
        int q;
        cin >> q;
        cout << sum - a[q - 1] << endl;
    }

    return 0;
}
