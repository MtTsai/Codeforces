#include <iostream>

using namespace std;

typedef unsigned long long ull;

ull mod = 1e9 + 7;

int T(char c) {
    if (c >= 'a' && c <= 'z') return c - 'a';
    else return c - 'A' + 26;
}

ull cnt[52] = {0};

int main() {
    string s;
    cin >> s;

    ull n = s.size();
    for (char c: s) {
        cnt[T(c)]++;
    }
    





    ull q;
    cin >> q;

    return 0;
}
