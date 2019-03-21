#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int gcd(int x, int y) {
    while (y) {
        int t = y;
        y = x % y;
        x = t;
    }
    return x;
}

int main() {
    int n; cin >> n;

    vector<int> p;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        p.push_back(x);
    }

    sort(p.begin(), p.end());

    int dist = *(p.begin() + 1) - *(p.begin());
    for (int i = 1; i < p.size() - 1; i++) {
        dist = gcd(p[i + 1] - p[i], dist);
    }

    int total_p = ((p.back() - p.front()) / dist) + 1;

    cout << total_p - p.size();

    return 0;
}
