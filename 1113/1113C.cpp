#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    unordered_map<int, int> m[2];

    int xor_val = 0;
    unsigned long long cnt = 0;
    m[1][0] = 1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        xor_val ^= a[i];
        cnt += m[i % 2][xor_val]++;
    }

    cout << cnt << endl;

    return 0;
}
