#include <bits/stdc++.h>
using namespace std;
const int N = 1001;

int grid[N][N];

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool valid(int x, int y, int n) {
    return (x >= 0 && x < n && y >= 0 && y < n);
}

bool bfs(int n, int ax, int ay, int bx, int by, int cx, int cy) {

    // Make all the queen cell block with 1
    for (int i = 0; i < 8; i++) {
        int x = ax, y = ay;
       
        while (valid(x, y, n)) {
            grid[x][y] = 1;
            x = x + dx[i];
            y = y + dy[i];
        }
    }

    // Apply BFS
    bool visited[n][n] = {false};
    queue<pair<int, int>> q;

    q.push({bx, by});
    visited[bx][by] = true;

    while (!q.empty()) {
        pair<int, int> u = q.front();
        q.pop();

        int dx_, dy_;
        dx_ = u.first;
        dy_ = u.second;

        if (dx_ == cx && dy_ == cy) {
            return true;
        }

        for (int i = 0; i < 8; i++) {
            int nx = dx_ + dx[i];
            int ny = dy_ + dy[i];

            if (valid(nx, ny, n) && !visited[nx][ny] && grid[nx][ny] == 0) {
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }

    return false;
}

int main() {
    int n;
    cin >> n;

    // Initialize grid with  0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            grid[i][j] = 0;
        }
    }

    int ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;

    bool res = bfs(n, ax - 1, ay - 1, bx - 1, by - 1, cx - 1, cy - 1);

    if (res) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}
