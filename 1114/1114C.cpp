#include <iostream>
#include <unordered_map>

using namespace std;

typedef unsigned long long ull;

int main() {
    ull n, b;

    cin >> n >> b;

    // calc how many b in 1 to n
    unordered_map<ull, ull> cnt;
    for (ull i = 2; i * i <=b; i++) {
        while (b % i == 0) {
            cnt[i]++;
            b /= i;
        }
    }
    if (b > 1) {
        cnt[b]++;
    }

    ull ans = -1;
    for (auto v: cnt) {
        ull prime = v.first;
        ull num = v.second;

        ull prime_cnt = 0;
        ull N = n;
        while (N) {
            N /= prime;
            prime_cnt += N;
        }
        // cout << v.first << " " << v.second << " " << prime_cnt << endl;
        ans = min(ans, prime_cnt / num);
    }

    cout << ans << endl;

    return 0;
}
