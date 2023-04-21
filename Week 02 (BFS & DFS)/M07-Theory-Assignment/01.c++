#include <bits/stdc++.h>
using namespace std;

int main() {
    int num_nodes, num_edges;
    cout << "Enter the number of nodes and edges: ";
    cin >> num_nodes >> num_edges;

    vector<vector<int>> adj_list(num_nodes);

    cout << "Enter the edges in the format 'u v':\n";
    for (int i = 0; i < num_edges; i++) {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    cout << "The adjacency list representation of the graph is:\n";
    for (int i = 0; i < num_nodes; i++) {
        cout << i << ": ";
        for (int j = 0; j < adj_list[i].size(); j++) {
            cout << adj_list[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}