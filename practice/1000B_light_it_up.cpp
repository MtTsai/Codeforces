#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int main() {
    int n, M;
    cin >> n >> M;
    
    vector<int> a(n + 2, 0);
    vector<int> on_f(n + 2, 0); // front
    vector<int> off_b(n + 2, 0); // back
    bool light;
    
    a[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    a[n + 1] = M;

    light = true;
    on_f[0] = 0;
    for (int i = 1; i <= n + 1; i++, light = !light) {
        int t = (light) ? a[i] - a[i - 1] : 0;

        on_f[i] = on_f[i - 1] + t;
    }

    light = (n % 2 == 0);
    off_b[n + 1] = 0;
    for (int i = n; i >= 0; i--, light = !light) {
        int t = (!light) ? a[i + 1] - a[i] : 0;
        off_b[i] = off_b[i + 1] + t;
    }
    
#define MAX(x, y) (((x) > (y)) ? (x) : (y))

    int max_time = on_f[n + 1];

    light = true;
    for (int i = 1; i <= n + 1; i++, light = !light) {
		if (a[i] - a[i - 1] <= 1) {
			continue;
		}
        if (light) {
            max_time = MAX(max_time, on_f[i] + off_b[i] - 1);
        }
        else {
            int t = a[i] - a[i - 1];
            max_time = MAX(max_time, on_f[i] + (t - 1) + off_b[i]);
        }
    }
    
    cout << max_time;
    
    return 0;
}
