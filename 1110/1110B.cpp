#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> b(n);
    vector<int> l;

    for (int i = 0; i < n; i++) {
        cin >> b[i];
        if (i > 0) {
            l.push_back(b[i] - b[i - 1] - 1);
        }
    }
    sort(l.begin(), l.end());

    int len = n;

    for (int i = 0; i < n - k; i++) {
        len += l[i];
    }

    cout << len << endl;

    return 0;
}
