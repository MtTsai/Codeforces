#include <iostream>

using namespace std;

int main() {
    int b, k;
    cin >> b >> k;

    int sum;
    for (int i = k - 1; i >= 0; i--) {
        int a;
        cin >> a;

        if (b % 2 || i == 0) {
            if (a % 2) {
                sum++;
            }
        }
    }

    if (sum % 2) {
        cout << "odd" << endl;
    }
    else {
        cout << "even" << endl;
    }
    
    return 0;
}
