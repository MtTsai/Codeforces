#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

typedef unsigned long long ull;
using namespace std;

int main() {
    ull n, k, m;
    cin >> n >> k >> m;

    vector<ull> p(n);
    double sum = 0;
    for (ull i = 0; i < n; i++) {
        cin >> p[i];
        sum += p[i];
    }

    sort(p.begin(), p.end());

    double ans = (sum + min(n * k, m)) / n;
    for (int i = 0; i < min(m, n - 1); i++) {
        sum -= p[i];
        ull num = n - i - 1;
        ull remaining_op = m - i - 1;
        ans = max(ans, (sum + min(num * k, remaining_op)) / num);
    }

    cout << setprecision(10) << fixed << ans << endl;

    return 0;

    // Wrong answer
    ull del = 0;
    ull add = 0;
    for (ull i = 0; i < m; i++) {
        ull num = n - del;
        double a = (num == 1) ? (sum / num) : ((sum - p[del]) / (num - 1));
        double b = (min(num * k, add + 1) + sum) / num;

        if (a >= b) {
            sum -= p[del];
            del++;
        }
        else {
            if (num * k > add) add++;
        }
    }

    cout << (sum + add) / (n - del) << endl;

    return 0;
}
