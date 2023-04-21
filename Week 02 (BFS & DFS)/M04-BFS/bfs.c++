#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;

int visited[N];

vector<int>adj_list[N];

void bfs(int src){
    queue<int>q;

    visited[src] = 1;
    q.push(src);

    while(!q.empty()){
        int head = q.front();
        q.pop();

        cout << head << endl;

        for(int adj_node: adj_list[head]){
            if(visited[adj_node] == 0){
                visited[adj_node] = 1;
                q.push(adj_node);
            }
        }
    }
}

/*
   example graph:
   
   0 ---- 1 ---- 2 ---- 3 
          |      |
          |      |
          5 ---- 4
    
   output: 0 1 5 2 3 4

   # of node => 6
   # of node => 6

   6 6
   list of adjacent nodes ->
   0 1
   2 3
   2 3
   1 5
   2 4
   1 2
*/

int main() {
    int nodes, edges;
    cin >> nodes >> edges;

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

    cout << "bfs\n";

    int src = 0;
    bfs(src);

    return 0;

}