#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;

int visited[N];
int level[N]; // new line added

vector<int>adj_list[N];

void bfs(int src){
    queue<int>q;

    visited[src] = 1;
    level[src] = 0; // new line added
    q.push(src);

    while(!q.empty()){
        int head = q.front();
        q.pop();


        for(int adj_node: adj_list[head]){
            if(visited[adj_node] == 0){
                visited[adj_node] = 1;
                level[adj_node] = level[head] + 1; // new line added
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


    int src = 0;
    bfs(src);

    cout << "sssp\n";

    for(int i=0; i < nodes; i++){
        cout << "node " <<i<< " -> level: " << level[i] << endl;
    }
   
    return 0;

}