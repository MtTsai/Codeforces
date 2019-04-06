#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> c(n);

    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (i > 0 && c[i] == c[i - 1]) continue;

        for (int j = n - 1; j >= i + ans; j--) {
            if (c[i] != c[j]) {
                ans = max(ans, j - i);
                break;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
