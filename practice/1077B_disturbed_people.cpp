#include <cstring>
#include <iostream>

using namespace std;

class House {
    int n;
    uint8_t *flats;

public:
    House() {
        cin >> n;

        flats = new uint8_t[n + 1];

        for (int i = 1; i < n + 1; i++) {
            int t;
            cin >> t;
            flats[i] = t;
        }
    }

    void out() {
        int ans = 0;
        for (int i = 2; i < n; i++) {
            if (flats[i - 1] && !flats[i] && flats[i + 1]) {
                flats[i + 1] = 0;
                ans++;
            }
        }
        cout << ans;
    }

    ~House() {
        delete [] flats;
    }
};

int main() {
    House h;

    h.out();

    return 0;
};
