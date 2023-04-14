# Pseudocode of BFS (Graph)

===================

### Time Complexity

Time Complexity = O(V+E)
Space Complexity = O(V)

=======================

- Define a visited array
  DFS(int node){
  cout << node << endl;
  visited[node] = 1;

      for (all adjacent_node of node){
          if visited[adjacent_node] == 0:
              DFS(adjacent_node)
      }

  }
