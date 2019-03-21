#include <iostream>

using namespace std;

int main() {
    int n, v;
    cin >> n >> v;

    if (v >= n - 1) {
        cout << n - 1 << endl;
    }
    else {
        cout << (v - 1) + (1 + (n - v)) * (n -v) / 2 << endl;
    }

    return 0;
}
