#include <iostream>

using namespace std;

int main() {
    int a;

    cin >> a;

    int t = 0;
    while (a) {
        t += a % 10;
        a /= 10;
    }

    if (t % 5) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
    }


    return 0;
}
