#include <bits/stdc++.h>
using namespace std;


const int maxN = 10;
int main() {
    // undirected adjacency List
    // node n = 9
    // edge e  = 9;
    // node value (u,v) will be between 1 to 9
    int n = 9;

    vector<int> adjList[maxN+1];
    int e;
    cin >> e;
    for(int i = 1; i <= e; i++){
        int u,v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    for(int i = 1; i <= n; i++){
        // here i means a node.
        cout << i << " --> ";
        // who is with i
        for(auto j:adjList[i]){
            cout << j << " ";
        }
        cout << "\n";
    }
}
