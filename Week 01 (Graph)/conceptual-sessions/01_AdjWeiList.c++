#include <bits/stdc++.h>
using namespace std;


const int maxN = 100;
int main() {
    // undirected weighted adjacency List
    // node n = 5
    // edge e  = 7;
    // node value (u,v) will be between 1 to 9
    int n = 9;

    vector<pair<int, int>> adjList[maxN];
    int e;
    cin >> e;
    for(int i = 1; i <= e; i++){ 
        int u,v, w;
        cin >> u >> v >> w;
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }

    for(int i = 0; i <= n; i++){
        // here i means a node.
        cout << i << " --> ";
        // who is with i
        for(auto j:adjList[i]){
            cout << "{" << j.first << " , " << j.second << "}" << " ";
        }
        cout << "\n";
    }
}
