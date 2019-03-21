#include <iostream>

using namespace std;

int x, y, z;
int g, p, b;

int main() {
    cin >> x >> y >> z >> g >> p >> b;

    if ((x > g) ||
        ((x + y) > (g + p)) ||
        ((x + y + z) > (g + p + b))) {
        cout << "No" << endl;
    }
    else {
        cout << "Yes" << endl;
    }

    return 0;
}
