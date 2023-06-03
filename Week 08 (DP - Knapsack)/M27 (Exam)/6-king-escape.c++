#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool isValidPosition(int x, int y, int n) {
    return (x >= 0 && x < n && y >= 0 && y < n);
}

bool canKingEscape(int n, int ax, int ay, int bx, int by, int cx, int cy) {
    // Initialize grid with all cells marked as safe (0)
    vector<vector<int>> grid(n, vector<int>(n, 0));

    // Directions for the queen's movements
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    // Mark cells around the queen as unsafe (1)
    for (int i = 0; i < 8; i++) {
        int x = ax, y = ay;
        while (isValidPosition(x, y, n)) {
            grid[x][y] = 1;
            x += dx[i];
            y += dy[i];
        }
    }

    // Apply BFS
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    queue<pair<int, int>> q;

    q.push(make_pair(bx, by));
    visited[bx][by] = true;

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();

        if (curr.first == cx && curr.second == cy) {
            return true;
        }

        for (int i = 0; i < 8; i++) {
            int nx = curr.first + dx[i];
            int ny = curr.second + dy[i];

            if (isValidPosition(nx, ny, n) && !visited[nx][ny] && grid[nx][ny] == 0) {
                q.push(make_pair(nx, ny));
                visited[nx][ny] = true;
            }
        }
    }

    return false;
}

int main() {
    int n;
    cin >> n;

    int ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;

    if (canKingEscape(n, ax - 1, ay - 1, bx - 1, by - 1, cx - 1, cy - 1)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
