#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> mat(n, vector<int>(n, 0));
    map<int, int> cnt;
    for (int i = 0; i < n * n; i++) {
        int a; cin >> a;
        cnt[a]++;
    }

    int i4 = 0, i2 = 0, i1 = 0;
    /* i4(0) i4(1) i2(2)
     * i4(2) i4(3) i2(3)
     * i2(0) i2(1) i1(0)
     * i4    i4
     * i4    i4
     */
    for (auto v: cnt) {
        int val = v.first;
        int num = v.second;
        while (num) {
            if (num >= 4 && i4 < ((n / 2) * (n / 2))) {
                int x = i4 / (n / 2);
                int y = i4 % (n / 2);
                mat[x][y] = mat[n - x - 1][y] = mat[x][n - y - 1] = mat[n - x - 1][n - y - 1] = val;
                i4++;
                num -= 4;
                continue;
            }
            if (num >= 2 && (i2 < ((n / 2) * 2 * (n % 2)))) {
                if (i2 < n / 2) {
                    int x = i2;
                    int y = n / 2;
                    mat[x][y] = mat[n - x - 1][y] = val;
                }
                else {
                    int x = n / 2;
                    int y = i2 - n / 2;
                    mat[x][y] = mat[x][n - y - 1] = val;
                }
                i2++;
                num -= 2;
                continue;
            }
            if (num >= 1 && i1 < (n % 2)) {
                int x = n / 2, y = n / 2;
                mat[x][y] = val;
                i1++;
                num -= 1;
                continue;
            }
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
