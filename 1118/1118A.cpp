#include <iostream>

using namespace std;

typedef unsigned long long ull;


int main() {
    int q;
    cin >> q;

    for (int round = 0; round < q; round++) {
        ull n, a, b;
        cin >> n >> a >> b;

        ull cost = (n % 2) * a;
        cost += (n / 2) * min(a * 2, b);

        cout << cost << endl;
    }

    return 0;
}
