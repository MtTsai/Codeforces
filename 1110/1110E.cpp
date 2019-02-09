#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> c, t;
vector<int> cdiff, tdiff;

int main() {
    int n;
    cin >> n;

    c = vector<int>(n);
    t = vector<int>(n);
    cdiff = vector<int>(n - 1);
    tdiff = vector<int>(n - 1);

    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    for (int i = 0; i < n - 1; i++) {
        cdiff[i] = c[i + 1] - c[i];
    }
    for (int i = 0; i < n - 1; i++) {
        tdiff[i] = t[i + 1] - t[i];
    }
    sort(cdiff.begin(), cdiff.end());
    sort(tdiff.begin(), tdiff.end());

    bool ok = c[0] == t[0];

    if (ok) {
        for (int i = 0; i < n - 1; i++) {
            if (cdiff[i] != tdiff[i]) {
                ok = false;
                break;
            }
        }
    }

    cout << ((ok) ? "Yes" : "No") << endl;

    return 0;
}
