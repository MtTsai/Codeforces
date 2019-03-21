#include <iostream>

using namespace std;

int main() {
    unsigned int n, k;
    cin >> n >> k;

    if (n > (k * (k - 1))) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++) {
            int round = i / k + 1;
            cout << i % k + 1 << " " << ((i + round) % k) + 1 << endl;
        }
    }

    return 0;
}
