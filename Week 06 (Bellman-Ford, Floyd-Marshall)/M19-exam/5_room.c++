#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int maxN = 1010;

char grid[maxN][maxN];
bool visited[maxN][maxN];
pair<int, int> parent[maxN][maxN];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


void bfs(int x, int y, int n, int m)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    parent[x][y] = {-1, -1};

    while (!q.empty())
    {
        pair<int, int> u = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int dx_, dy_;
            dx_ = u.first + dx[i];
            dy_ = u.second + dy[i];

            if (dx_ >= 1 && dx_ <= n && dy_ >= 1 && dy_ <= m && !visited[dx_][dy_] && grid[dx_][dy_] != '#')
            {
                visited[dx_][dy_] = true;
                q.push({dx_, dy_});
                parent[dx_][dy_] = u;
            }
        }
    }
}

int countRoomsAndLongestRoom(int n, int m)
{
    int numRooms = 0;
    int longestRoom = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (!visited[i][j] && grid[i][j] != '#')
            {
                int roomSize = 0;
                bfs(i, j, n, m);
                numRooms++;
                
                // Traverse the visited cells to count the size of the room
                for (int x = 1; x <= n; x++)
                {
                    for (int y = 1; y <= m; y++)
                    {
                        if (visited[x][y])
                        {
                            roomSize++;
                            longestRoom = max(longestRoom, roomSize);
                        }
                    }
                }
            }
        }
    }

    return longestRoom;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int start_x, start_y, end_x, end_y;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
            {
                start_x = i;
                start_y = j;
            }
            if (grid[i][j] == '.')
            {
                end_x = i;
                end_y = j;
            }
        }
    }

    bfs(start_x, start_y, n, m);

    if (visited[end_x][end_y])
    {
        cout << "YES" << '\n';
        cout << countRoomsAndLongestRoom(n, m) << '\n';

    }
    else
        cout << "NO" << '\n';

    return 0;
}
