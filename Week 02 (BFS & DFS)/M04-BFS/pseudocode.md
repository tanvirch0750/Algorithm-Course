# Pseudocode of BFS

===================

### Time Complexity

Time Complexity = O(V+E)
If this is a complete graph = O(V+V^2)
Space Complexity = O(V)

=======================

Input -> Connected Graph and a "source"
Output -> Traverse all nodes and print the traversal order

BFS(graph, source):

- Initiate an array called "visited" and an empty queue "q"
- Mark visited[source] = 1 and q.push(source)
- While the queue is not empty :
  - head = q.front()
  - q.pop()
  - print the node "head"
  - for all adjacent nodes of "head":
    - if visited[adj_node] == 0:
      -visited[adj_node] = 1 and q.push(adj_node)
