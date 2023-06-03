
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const long long INF = 1e18;

vector< pair<int, int> >adj_list[N];

int visited[N];
int nodes, edges;

long long d[N];


void dijkstra(int src) {
    for(int i = 1 ; i <= nodes ; i++) {
        d[i] = INF;
    }
    d[src] = 0;

    priority_queue< pair<long long, int> > pq;
    pq.push( { 0, src} );

    while( !pq.empty() ) {

        pair<long long, int> head = pq.top();
        pq.pop();
        int selected_node = head.second;

        if(visited[selected_node]) {
            continue;
        }

        visited[selected_node] = 1;

        for(auto adj_entry: adj_list[selected_node]) {
            int adj_node = adj_entry.first;
            int edge_cst = adj_entry.second;

            if(d[selected_node] + edge_cst < d[adj_node]) {
                d[adj_node] = d[selected_node] + edge_cst;
                pq.push( { -d[adj_node], adj_node } );
            }
        }

    }
}

int main() {

    cin >> nodes >> edges;

    for(int i = 0 ; i < edges ; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj_list[u].push_back({ v, w });
        adj_list[v].push_back({ u, w });
    }

    int src = 2;
    dijkstra(src);


    for(int i = 1 ; i <= nodes ; i++) {
        if(i == 5) continue;
        cout << i << " " << d[i] << " ";
         cout<<endl;
    }
   
    cout<<endl;
}
/*

   Let: Node 1 = A, Node 2 = B, Node 3 = C, Node 4 = D, Node 6 = E, Node 7 = F, 
   Node 8 = G

   
    - first all the node with distance array will be infinity
       |      |      |      |      |      |      |      
      inf     0    inf    ing     inf    inf    inf      
       A      B      C      D      E      F      G     
       |      |      |      |      |      |      |   

    - distance[B] = 0

     priority queue = [{0, B}]
     Visited node = [A(0), B(0), C(0), D(0), E(0), F(0), G(0)]

     - Now pop the first element from q, and select the node (B), its not visited, so make it  visited.
       Visited node = [A(0), B(1), C(0), D(0), E(0), F(0), G(0)]
       Now explore this node and make relaxation
      
        |      |      |      |      |      |      |      
        3      0      18    inf    inf    inf    inf    
        A      B      C      D      E      F      G      
        |      |      |      |      |      |      |     

       priority queue = [{3, A}, {18, C}]
       
    
      - Now pop the first element from q, and select the node (A), its not visited, so make it visited.
        Visited node = [A(1), B(1), C(0), D(0), E(0), F(0), G(0)]
       Now explore this node and make relaxation
      
        |      |      |      |      |      |      |      
        3      0      18     4      6     inf     6    
        A      B      C      D      E      F      G      
        |      |      |      |      |      |      |    

       priority queue = [{4, D}, {6, E}, {6, G} {18, C}]

      - Now pop the first element from q, and select the node (D), its not visited, so make it visited.
        Visited node = [A(1), B(1), C(0), D(1) E(0), F(0), G(0)]
       Now explore this node and make relaxation
      
        |      |      |      |      |      |      |      
        3      0      6      4      6      8     6    
        A      B      C      D      E      F      G      
        |      |      |      |      |      |      |    

       priority queue = [{6, C},{6, E}, {6, G}, {8, F} {18, C}]

    
     - Now pop the first element from q, and select the node (C), its not visited, so make it visited.
         Visited node = [A(1), B(1), C(1), D(1) E(0), F(0), G(0)]
       Now explore this node and make relaxation
      
        |      |      |      |      |      |      |      
        3      0      6      4      6      7     6    
        A      B      C      D      E      F      G      
        |      |      |      |      |      |      |    

       priority queue = [{6, E}, {6, G}, {7, F} {8, F} {18, C}]

    
    - Now pop the first element from q, and select the node (E), its not visited, so make it visited.
       Visited node = [A(1), B(1), C(1), D(1) E(1), F(0), G(0)]
       Now explore this node and make relaxation
      
        |      |      |      |      |      |      |      
        3      0      6      4      6      7      6    
        A      B      C      D      E      F      G      
        |      |      |      |      |      |      |    

       priority queue = [{6, G}, {7, F} {8, F} {18, C}]

    
    - Now pop the first element from q, and select the node (G), its not visited, so make it visited.
        Visited node = [A(1), B(1), C(1), D(1) E(1), F(0), G(1)]
       Now explore this node and make relaxation

        |      |      |      |      |      |      |      
        3      0      6      4      6      7      6    
        A      B      C      D      E      F      G      
        |      |      |      |      |      |      |    

       priority queue = [{7, F} {8, F} {18, C}]


     - Now pop the first element from q, and select the node (F), its not visited, so make it visited.
       Visited node = [A(1), B(1), C(1), D(1) E(1), F(1), G(1)]
       Now explore this node and make relaxation
      
        |      |      |      |      |      |      |      
        3      0      6      4      6      7      6    
        A      B      C      D      E      F      G      
        |      |      |      |      |      |      |    

       priority queue = [{8, F} {18, C}]


     - Now pop the first element from q, and select the node (F), its already visited so continue
      priority queue = [{18, C}]

    - Now pop the first element from q, and select the node (C), its already visited so continue
      priority queue = []


      So now priority queue is empty, now its finished

*/