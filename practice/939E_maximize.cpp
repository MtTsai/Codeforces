#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int main() {
    int Q;
    cin >> Q;

    double max_mmdiff = 0;
    double sum = 0, cnt = 0;
    queue<double> q;
    for (int i = 0; i < Q; i++) {
        int cmd;
        cin >> cmd;

        switch (cmd) {
            case 1: {
                double x; cin >> x;
                q.push(x);
                break;
            }
            case 2: {
                while (q.size() > 1 && q.front() < ((sum + q.back()) / (cnt + 1))) {
                    sum += q.front(); q.pop(); cnt++;
                }
                double cur_mmdiff = q.back() - ((sum + q.back())/ (cnt + 1));
                max_mmdiff = (max_mmdiff > cur_mmdiff) ? max_mmdiff : cur_mmdiff;
                printf("%.10llf\n", max_mmdiff);
                break;
            }
            default: break;
        }
    }

    return 0;
}
