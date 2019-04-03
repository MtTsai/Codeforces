#include <iostream>
#include <vector>

using namespace std;


int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    vector<bool> is_sort(n, true);
    int ans = 1;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int l = 2; l <= n; l *= 2) {
        for (int i = n - l; i >= 0; i -= l) {
            int t = l / 2;
            if (is_sort[i] = is_sort[i] && is_sort[i + t] && (arr[i + t - 1] <= arr[i + t])) {
                ans = l;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
