#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    string s;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> s;

    int start = 0, i;
    for (i = 1; i < n; i++) {
        if (s[i] != s[i - 1]) {
            if (i - start > k) {
                // skip the smaller value in consecutive array
                sort(a.begin() + start, a.begin() + i);
                for (int j = start; j < i - k; j++) {
                    a[j] = 0;
                }
            }
            start = i;
        }
    }
    if (i - start > k) {
        // skip the smaller value in consecutive array
        sort(a.begin() + start, a.begin() + i);
        for (int j = start; j < i - k; j++) {
            a[j] = 0;
        }
    }

    unsigned long long dmg = 0;
    for (int i = 0; i < n; i++) {
        dmg += a[i];
    }

    cout << dmg << endl;

    return 0;
}
