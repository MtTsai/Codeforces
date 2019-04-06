#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, h;

    cin >> n >> h;

    vector<int> b;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int t; cin >> t;

        b.insert(lower_bound(b.begin(), b.end(), t), t);

        int remain = h;
        for (int j = i; j >= 0; j -= 2) {
            remain -= b[j];
        }

        if (remain < 0) {
            break;
        }

        ans = i + 1;
    }

    cout << ans << endl;

    return 0;
}
