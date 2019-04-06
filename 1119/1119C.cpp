#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> A(n, vector<int>(m, 0));
    vector<vector<int>> B(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> B[i][j];
        }
    }

    bool can_transform = true;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            if (A[i][j] != B[i][j]) {
                A[i][j] = !A[i][j];
                A[i + 1][j] = !A[i + 1][j];
                A[i][j + 1] = !A[i][j + 1];
                A[i + 1][j + 1] = !A[i + 1][j + 1];
            }
        }
        if (A[i][m - 1] != B[i][m - 1]) {
            can_transform = false;
            break;
        }
    }
    if (can_transform) {
        for (int j = 0; j < m; j++) {
            if (A[n - 1][j] != B[n - 1][j]) {
                can_transform = false;
                break;
            }
        }
    }

    if (can_transform) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }

    return 0;
}
