
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
7 12
1 2 3
1 3 22
1 6 3
1 8 3
1 4 1
2 3 18
3 7 1
3 4 2
4 8 10
4 7 4
6 8 2
6 7 2
/*
   
    - first all the node with distance array will be infinity
       |      |      |      |      |      |      |      |      | 
      inf    inf    inf     0     inf    inf    inf    inf    inf    
       1      B      C      E      F      G      H      I      J
       |      |      |      |      |      |      |      |      |

    - distance[E] = 0

     priority queue = [{0, E}]
     Visited node = [A(0), B(0), C(0), E(0), F(0), G(0), H(0), I(0), J(0)]

     - Now pop the first element from q, and select the node (E), its not visited, so make it  visited.
       Visited node = [A(0), B(0), C(0), E(1), F(0), G(0), H(0), I(0), J(0)]
       Now explore this node and make relaxation
      
        |      |      |      |      |      |      |      |      | 
       inf    20      9      0     inf     5     inf    inf    inf    
        A      B      C      E      F      G      H      I      J
        |      |      |      |      |      |      |      |      |

       priority queue = [{5, G}, {9, C}, {20, B}]
       
    
      - Now pop the first element from q, and select the node (G), its not visited, so make it visited.
        Visited node = [A(0), B(0), C(0), E(1), F(0), G(1), H(0), I(0), J(0)]
       Now explore this node and make relaxation
      
        |      |      |      |      |      |      |      |      | 
       inf    20      9      0      6      5     inf    inf    inf    
        A      B      C      E      F      G      H      I      J
        |      |      |      |      |      |      |      |      |

       priority queue = [{6, F}, {9, C}, {20, B}]

      - Now pop the first element from q, and select the node (F), its not visited, so make it visited.
        Visited node = [A(0), B(0), C(0), E(1), F(1), G(1), H(0), I(0), J(0)]
       Now explore this node and make relaxation
      
        |      |      |      |      |      |      |      |      | 
       inf    19      9      0      6      5     27   inf    inf    
        A      B      C      E      F      G      H      I      J
        |      |      |      |      |      |      |      |      |

       priority queue = [{9, C}, {19, B} {20, B}, {27, H}]

    
     - Now pop the first element from q, and select the node (C), its not visited, so make it visited.
        Visited node = [A(0), B(0), C(1), E(1), F(1), G(1), H(0), I(0), J(0)]
       Now explore this node and make relaxation
      
        |      |      |      |      |      |      |      |      | 
       10     16      9      0      6      5     27   inf    inf    
        A      B      C      E      F      G      H      I      J
        |      |      |      |      |      |      |      |      |

       priority queue = [{10, A}, {16, B} {19, B} {20, B}, {27, H}]

    
    - Now pop the first element from q, and select the node (A), its not visited, so make it visited.
        Visited node = [A(1), B(0), C(1), E(1), F(1), G(1), H(0), I(0), J(0)]
       Now explore this node and make relaxation
      
        |      |      |      |      |      |      |      |      | 
       10     12      9      0      6      5     27     28      15   
        A      B      C      E      F      G      H      I      J
        |      |      |      |      |      |      |      |      |

       priority queue = [{12,B}, {15, J}, {16, B} {19, B} {20, B}, {27, H}, {28, I}]

    
    - Now pop the first element from q, and select the node (B), its not visited, so make it visited.
        Visited node = [A(1), B(1), C(1), E(1), F(1), G(1), H(0), I(0), J(0)]
       Now explore this node and make relaxation
      
        |      |      |      |      |      |      |      |      | 
       10     12      9      0      6      5     27     28      15   
        A      B      C      E      F      G      H      I      J
        |      |      |      |      |      |      |      |      |

       priority queue = [{15, J}, {16, B} {19, B} {20, B}, {27, H}, {28, I}]


     - Now pop the first element from q, and select the node (J), its not visited, so make it visited.
        Visited node = [A(1), B(1), C(1), E(1), F(1), G(1), H(0), I(0), J(1)]
       Now explore this node and make relaxation
      
        |      |      |      |      |      |      |      |      | 
       10     12      9      0      6      5     27     21      15   
        A      B      C      E      F      G      H      I      J
        |      |      |      |      |      |      |      |      |

       priority queue = [{16, B} {19, B} {20, B}, {21, I} {27, H}, {28, I}]


     - Now pop the first element from q, and select the node (B), its already visited so continue
      priority queue = [{19, B} {20, B}, {21, I} {27, H}, {28, I}]

    - Now pop the first element from q, and select the node (B), its already visited so continue
      priority queue = [{20, B}, {21, I} {27, H}, {28, I}]

    - Now pop the first element from q, and select the node (B), its already visited so continue
      priority queue = [{21, I} {27, H}, {28, I}]


    - Now pop the first element from q, and select the node (I), its not visited, so make it visited.
        Visited node = [A(1), B(1), C(1), E(1), F(1), G(1), H(0), I(1), J(1)]
       Now explore this node and make relaxation
      
        |      |      |      |      |      |      |      |      | 
       10     12      9      0      6      5     27     21      15   
        A      B      C      E      F      G      H      I      J
        |      |      |      |      |      |      |      |      |

       priority queue = [{27, H}, {28, I}]

    
    - Now pop the first element from q, and select the node (H), its not visited, so make it visited.
        Visited node = [A(1), B(1), C(1), E(1), F(1), G(1), H(1), I(1), J(1)]
       Now explore this node and make relaxation
      
        |      |      |      |      |      |      |      |      | 
       10     12      9      0      6      5     27     21      15   
        A      B      C      E      F      G      H      I      J
        |      |      |      |      |      |      |      |      |

       priority queue = [{28, I}]

     - Now pop the first element from q, and select the node (I), its already visited so continue
      priority queue = []


      So now priority queue is empty, now its finished

*/