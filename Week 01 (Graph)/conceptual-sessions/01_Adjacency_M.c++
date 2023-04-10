#include <bits/stdc++.h>
using namespace std;


const int maxN = 100;
int main() {
    // undirected adjacency matrix
    // node n = 9
    // edge m = 9;
    int n=9, m;
    cin >> m;
    int adjMatrix[n + 1][n + 1];

    for(int i = 0; i <= n; i++){
        for (int j = 0; j <= n; j++)
            adjMatrix[i][j] = 0;
    }

    // loop will run edge (m) times
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; 
    }

    // print graph
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++)
            cout << adjMatrix[i][j] << " ";
        cout << "\n";
    }
}
