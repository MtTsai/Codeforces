#include <iostream>
#include <cstring>

using namespace std;

long long classy_nums_s(string S) {
    int cnt = 0;
    for (int i = 0; i < S.length(); i++) {
        if (S[i] != '0') {
            cnt++;
        }
        if (cnt > 3) {
            return 0;
        }
    }
    return 1;
}

long long comb(int n, int m) {
    long long ret = 1, i;
	if (n > 0) {
		for (i = n; i > m; i--) {
			ret *= i;
		}
		for (i = n - m; i >= 1; i--) {
			ret /= i;
		}
	}
    return ret;
}

long long pow(int n, int m) {
    long long ret = 1;
    if (m > 0) {
		for (int i = 0; i < m; i++) {
			ret *= n;
		}
	}
    return ret;
}

long long classy_nums_from_zero(string S) {
    int l = S.length();
    int hdl = 0;
    long long nums = 0;

	cout << "shit" << endl;
    for (int i = 0; i < l; i++) {
		cout << "shit: " << i << endl;
        if (S[i] > '0') {
            hdl++;

            long long lead = S[i] - '0';

			int r = l - i - 1;
            int non_zero_cnt = 3 - hdl;
            int zero_cnt;

			/* case lead != 0 */
			if (r > non_zero_cnt) {
				zero_cnt = r - non_zero_cnt;
			}
			else {
				non_zero_cnt = r;
				zero_cnt = 0;
			}

			nums += (comb(r, zero_cnt) * pow(10, non_zero_cnt) * (lead - 1));
            /* case lead == 0 */
			non_zero_cnt = 3 - hdl + 1;
			if (r > non_zero_cnt) {
				zero_cnt = r - non_zero_cnt;
            }
			else {
                non_zero_cnt = r;
                zero_cnt = 0;
            }
            nums += (comb(r, zero_cnt) * pow(10, non_zero_cnt) - 1);

        }
        if (hdl == 3) {
            break;
        }
    }
	cout << "shit- nums: " << nums << endl;
    return nums;
}


long long classy_nums(string L, string R) {
    return classy_nums_from_zero(R) - classy_nums_from_zero(L) + classy_nums_s(R);
}

int main() {
    int T;

	cin >> T;
    for (int i = 0; i < T; i++) {
		char L[20], R[20];
        scanf("%s %s", L, R);
        cout << "qq" << endl;
        cout << classy_nums(L, R);
        cout << "gg" << endl;
    }

    return 0;
}
