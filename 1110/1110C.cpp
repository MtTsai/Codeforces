#include <iostream>

using namespace std;

int nbit[26] = {0};

int is_full_nbit(int n) {
    for (int i = 1; i < 26; i++) {
        if (nbit[i] == n) return true;
    }
    return false;
}

int make_full_nbit(int n) {
    for (int i = 24; i >= 0; i--) {
        if (n > nbit[i]) {
            return nbit[i + 1];
        }
    }
    return 0;
}

int main() {
    int q;
    cin >> q;


    for (int i = 1; i < 26; i++) {
        nbit[i] = (nbit[i - 1] << 1) + 1;
    }

    for (int tc = 0; tc < q; tc++) {
        int a, ans = 1;
        cin >> a;

        if (is_full_nbit(a)) {
            // gcd(a ^ b, a & b) = gcd(a - b, b)
            // a = n * x, b = n * y
            // a - b = n * (x - y), x > y >= 1
            // find the smallest x to find the largest n
            int n = 1;
            for (int i = 2; i * i < a; i++) {
                if (a % i == 0) {
                    n = a / i;
                    break;
                }
            }
            cout << n << endl;
        }
        else {
            cout << make_full_nbit(a) << endl;
        }
    }

    return 0;
}
