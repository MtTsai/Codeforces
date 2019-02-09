#include <iostream>
#include <string>

using namespace std;

bool is_vowol(char c) {
    string s = "aeiou";
    for (int i = 0; i < 5; i++) {
        if (c == s[i]) {
            return true;
        }
    }
    return false;

    return (c == 'a' || c == 'e' || c == 'i' ||  c == 'o' || c == 'u');
}

bool trans(char c1, char c2) {
    return ((is_vowol(c1)  && is_vowol(c2)) ||
            (!is_vowol(c1) && !is_vowol(c2)));
}

int main() {
    string s, t;

    cin >> s >> t;

    int l = s.size();
    if (s.size() != t.size()) {
        cout << "No" << endl;
        return 0;
    }

    for (int i = 0; i < l; i++) {
        if (!trans(s[i], t[i])) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    return 0;
}
