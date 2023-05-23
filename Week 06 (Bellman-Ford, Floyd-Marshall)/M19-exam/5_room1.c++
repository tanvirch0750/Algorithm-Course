#include <bits/stdc++.h>
using namespace std;

const int maxN = 5000;

char grid[maxN][maxN];
bool visited[maxN][maxN];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int bfs(int x, int y, int n, int m) {
    queue<pair<int, int>> q;
    q.push({ x,y });
    visited[x][y] = true;
    int roomSize = 0;

    while (!q.empty()) {
        pair<int, int> u = q.front();
        q.pop();
        roomSize++;
        for (int i = 0; i < 4; i++) {
            int dx_ = u.first + dx[i];
            int dy_ = u.second + dy[i];

           
            if (dx_ >= 1 && dx_ <= n && dy_ >= 1 && dy_ <= m && !visited[dx_][dy_] && grid[dx_][dy_] == '.') {
                visited[dx_][dy_] = true;
                q.push({ dx_, dy_ });
            }
        }
    }

    return roomSize;
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
        }
    }

    int room = 0;
    int maxRoom = 0;

    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (grid[i][j] == '.' && !visited[i][j]) {
                room++;
                int roomSize = bfs(i, j, n, m);
                maxRoom = max(maxRoom, roomSize);
            }
        }
    }

    cout << "Rooms - " << room << "\n";
    cout << "Length of the longest room - " << maxRoom << "\n";

    return 0;
}

