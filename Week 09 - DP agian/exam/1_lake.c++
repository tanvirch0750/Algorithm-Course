#include<bits/stdc++.h>
using namespace std;
const int N = 1005;

int grid[N][N];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int dfs(int i, int j, int n, int m) {
    int res = 0;

    if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0) {
        return res;
    }

    int d = grid[i][j];
    grid[i][j] = 0;

    for (int k = 0; k < 4; k++) {
        int dx_ = i + dx[k];
        int dy_ = j + dy[k];
        res = res + dfs(dx_, dy_, n, m);
    }

    return res + d;
}

int main() {
    int t;
    cin >> t;
    vector<int> res;

    while (t--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        int largeVl = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] > 0) {
                    int lakev = dfs(i, j, n, m);
                    largeVl= max(largeVl, lakev);
                }
            }
        }

        res.push_back(largeVl);
    }

    for(int i = 0; i < res.size(); i++){
        cout << res[i] << endl;
    }

    return 0;
}
