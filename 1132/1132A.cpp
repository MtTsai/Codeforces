#include <iostream>

using namespace std;

int main() {
    int cnt[4];

    for (int i = 0; i < 4; i++) {
        cin >> cnt[i];
    }

    if (cnt[0] != cnt[3]) {
        cout << 0 << endl;
    }
    else {
        if (cnt[2] > 0) {
            if (cnt[0] > 0) {
                cout << 1 << endl;
            }
            else {
                cout << 0 << endl;
            }
        }
        else {
            cout << 1 << endl;
        }
    }

    return 0;
}
