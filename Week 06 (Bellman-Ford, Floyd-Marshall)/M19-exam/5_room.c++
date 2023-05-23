#include <iostream>
#include <queue>
using namespace std;

const int maxN = 1000;

// Function to perform BFS traversal
int bfs(int startRow, int startCol, int n, int m, char grid[][maxN], bool visited[][maxN]) {
    // Arrays to define the possible movements (up, down, left, right)
    int rowMoves[] = {-1, 1, 0, 0};
    int colMoves[] = {0, 0, -1, 1};

    queue<pair<int, int>> q;
    q.push({startRow, startCol});
    visited[startRow][startCol] = true;
    int roomSize = 0;

    while (!q.empty()) {
        int currentRow = q.front().first;
        int currentCol = q.front().second;
        q.pop();
        roomSize++;

        // Check all possible movements from the current cell
        for (int i = 0; i < 4; i++) {
            int newRow = currentRow + rowMoves[i];
            int newCol = currentCol + colMoves[i];

            // Check if the new cell is valid (within map boundaries and not a wall)
            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && grid[newRow][newCol] == '.' && !visited[newRow][newCol]) {
                q.push({newRow, newCol});
                visited[newRow][newCol] = true;
            }
        }
    }

    return roomSize;
}

int main() {
    int n, m;
    cin >> n >> m;

    char grid[maxN][maxN];
    bool visited[maxN][maxN] = {false};

    // Read the grid
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int numRooms = 0;
    int maxRoomSize = 0;

    // Traverse the grid and find the rooms
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.' && !visited[i][j]) {
                numRooms++;
                int roomSize = bfs(i, j, n, m, grid, visited);
                maxRoomSize = max(maxRoomSize, roomSize);
            }
        }
    }

    cout << numRooms << endl;
    cout << maxRoomSize << endl;

    return 0;
}
