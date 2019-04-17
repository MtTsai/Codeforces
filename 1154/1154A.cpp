#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int in[4];

    for (int i = 0; i < 4; i++) {
        cin >> in[i];
    }
    sort(in, in + 4);

    for (int i = 0; i < 3; i++) {
        cout << in[3] - in[i] << " ";
    }
    cout << endl;
    return 0;
}
