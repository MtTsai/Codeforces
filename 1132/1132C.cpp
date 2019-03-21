#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> l(q);
    vector<int> r(q);

    vector<int> f(n + 1, 0);
    f[0] = 2;

    for (int i = 0; i < q; i++) {
        cin >> l[i] >> r[i];
        for (int j = l[i]; j <= r[i]; j++) {
            f[j]++;
        }
    }

    for (int t = 0; t < 2; t++) {
        int cost = n, target = 0;
        for (int i = 0; i < q; i++) {
            int c = 0;
            for (int j = l[i]; j <= r[i]; j++) {
                if (f[j] > 1) continue;
                c++;
            }
            if (c < cost) {
                target = i;
                cost = c;
            }
            else if (c == cost) {
                if (r[i] - l[i] < r[target] - l[target]) {
                    target = i;
                }
            }
        }
        for (int j = l[target]; j <= r[target]; j++) {
            f[j]--;
        }
        l[target] = 1;
        r[target] = n;
    }

    int total = 0;
    for (int i = 1; i <= n; i++) {
        if (f[i]) total++;
    }
    cout << total << endl;

    return 0;
}
