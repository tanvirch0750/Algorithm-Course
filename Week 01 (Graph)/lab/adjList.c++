/*
  Adjacecny List (undirected and unweighted)
  Total nodes  = 3
  matrix[nodes][nodes]

  edges:
  0 --> 1
  1 --> 0, 2 3
  2 --> 1, 3
  3 --> 1, 2
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int nodes, edges;
    cin >> nodes >> edges;
    // vector<int> adj_list[nodes];
    // adj_list[1] = {2, 3};
    // adj_list[2] = {1, 4};
    // adj_list[3] = {1, 4};
    // adj_list[4] = {2, 3, 5, 6};
    // adj_list[5] = {4};
    // adj_list[6] = {4};
    

    vector<int> adj_list[nodes];

    for (int i = 0; i < edges; i++){
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    for(int i =0; i < nodes; i++){
        cout << i << " --> ";
        for(int j = 0; j < adj_list[i].size(); j++){
            cout << adj_list[i][j] << " ";
        }
        cout << endl;
    }
}