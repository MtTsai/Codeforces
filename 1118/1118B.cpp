#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> c(n + 1, 0);
    vector<vector<int>> sum(2, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        cin >> c[i];

        sum[i % 2][i] = sum[i % 2][i - 1] + c[i];
        sum[(i + 1) % 2][i] = sum[(i + 1) % 2][i - 1];
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int evensum = sum[0][i - 1] + (sum[1][n] - sum[1][i]);
        int oddsum  = sum[1][i - 1] + (sum[0][n] - sum[0][i]);

        if (evensum == oddsum) ans++;
    }

    cout << ans << endl;

    return 0;
}
