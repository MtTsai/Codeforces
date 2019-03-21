#include <iostream>
#include <vector>

using namespace std;

typedef struct {
    int x;
    int y;
} point_t;

int n, m;
point_t start_p, end_p;

typedef enum {
    U = 0,
    D,
    L,
    R,
    S /* start_p */
} dir_e;

bool dfs(int x, int y, dir_e d, int turn, vector<vector<bool>> &g) {
    if (turn > 3 || !g[x][y]) {
        return false;
    }
    if (x == end_p.x && y == end_p.y) {
        return true;
    }
    if (turn == 3) {
        switch (d) {
            case U:
                if (y < end_p.y || x != end_p.x) return false;
                break;
            case D:
                if (y > end_p.y || x != end_p.x) return false;
                break;
            case L:
                if (y != end_p.y || x < end_p.x) return false;
                break;
            case R:
                if (y != end_p.y || x > end_p.x) return false;
                break;
            defaut:
                break;
        }
    }

    bool ret = false;    
    if (x > 0) {
        g[x][y] = false;
        ret = dfs(x - 1, y, L, (d == L) ? turn : turn + 1, g);
        g[x][y] = true;
    }
    if (ret) return true;

    if (x < n - 1) {
        g[x][y] = false;
        ret = dfs(x + 1, y, R, (d == R) ? turn : turn + 1, g);
        g[x][y] = true;
    }
    if (ret) return true;

    if (y > 0) {
        g[x][y] = false;
        ret = dfs(x, y - 1, U, (d == U) ? turn : turn + 1, g);
        g[x][y] = true;
    }
    if (ret) return true;

    if (y < m - 1) {
        g[x][y] = false;
        ret = dfs(x, y + 1, D, (d == D) ? turn : turn + 1, g);
        g[x][y] = true;
    }
    return ret;
} 

int main() {
    cin >> n >> m;

    vector<vector<bool>> g(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            switch (c) {
                case 'S':
                    start_p.x = i;
                    start_p.y = j;
                    g[i][j] = true;
                    break;
                case 'T':
                    end_p.x = i;
                    end_p.y = j;
                    g[i][j] = true;
                    break;
                case '.':
                    g[i][j] = true;
                    break;
                case '*':
                default:
                    break;
            }
        }
    }

    if (dfs(start_p.x, start_p.y, S, 0, g)) {
    	cout << "YES";
	}
	else {
		cout << "NO";
    }

    return 0;
}

