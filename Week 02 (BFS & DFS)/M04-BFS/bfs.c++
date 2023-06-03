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

    int src = 2;
    bfs(src);

    return 0;

}

/**
  The bfs traversal will start from node 2

  step 1
  ======
  visited = []
  queue = [2]
  
  Step 2
  =====
  Explore node 2
  queue = [1, 3, 5]
  visited = [2]

  Step 3
  =====
  Explore node 1
  queue = [3, 5, 4]
  visited = [2, 1]

  Step 4
  =====
  Explore node 3
  queue = [5, 4]
  visited = [2, 1. 3]

  Step 5
  =====
  Explore node  5
  queue = [4, 6]
  visited = [2, 1, 3, 5]

  Step 6
  =====
  Explore node 4
  queue = [6]
  visited = [2, 1, 3, 5, 4]

  Step 7
  =====
  Explore node 6
  queue = []
  visited = [2, 1, 3, 5, 4, 6]
*/