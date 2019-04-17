#include <iostream>

using namespace std;

int inweek(int a, int b, int c, int start) {
    int cnt = 0;
    for (int i = 0; i < 7; i++) {
        int day = (start + i) % 7;
        bool avail = true;
        switch (day) {
            case 0:
            case 3:
            case 6:
                if (a == 0) {
                    avail = false;
                    break;
                }
                a--;
                break;
            case 1:
            case 5:
                if (b == 0) {
                    avail = false;
                    break;
                }
                b--;
                break;
            case 2:
            case 4:
                if (c == 0) {
                    avail = false;
                    break;
                }
                c--;
                break;
            default:
                break;
        }
        if (!avail) {
            break;
        }
        cnt++;
    }
    return cnt;
}

int main() {
    int a, b, c;

    cin >> a >> b >> c;

    int week = min(min(a / 3, b / 2), c / 2);
    a = a - 3 * week;
    b = b - 2 * week;
    c = c - 2 * week;

    int ans = 0;
    for (int i = 0; i < 7; i++) {
        ans = max(ans, inweek(a, b, c, i));
    }
    cout << week * 7 + ans << endl;

    return 0;
}
