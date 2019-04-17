#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, b, a;
    cin >> n >> b >> a;

    vector<int> s(n);

    int cur_b = b, cur_a = a;

    int i;
    for (i = 0; i < n; i++) {
        int s;
        cin >> s;

        if (cur_a == 0 && cur_b == 0) {
            break;
        }

        if (cur_a == a) {
            cur_a--;
            continue;
        }
        else {
            if (cur_a == 0) {
                cur_b--;
            }
            else if (cur_b == 0) {
                cur_a--;
                continue;
            }
            else {
                if (s == 1) {
                    cur_b--;
                }
                else {
                    cur_a--;
                    continue;
                }
            }
        }
        if (s == 1) {
            cur_a = min(a, cur_a + 1);
        }
    }

    cout << i << endl;

    return 0;
}
