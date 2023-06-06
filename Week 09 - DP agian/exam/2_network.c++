#include <bits/stdc++.h>
using namespace std;

const int N = 105;
const long long INF = 1e18;

vector<pair<int, int>> adj_list[N];

int nodes, edges;

long long d[N];

void dijkstra(int src) {
    for (int i = 1; i <= nodes; i++) {
        d[i] = INF;
    }
    d[src] = 0;

    priority_queue<pair<long long, int>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        pair<long long, int> head = pq.top();
        pq.pop();
        int selected_node = head.second;

        if (d[selected_node] < -head.first) {
            continue;
        }

        for (auto adj_entry : adj_list[selected_node]) {
            int adj_node = adj_entry.first;
            int edge_cst = adj_entry.second;

            if (d[selected_node] + edge_cst < d[adj_node]) {
                d[adj_node] = d[selected_node] + edge_cst;
                pq.push({-d[adj_node], adj_node});
            }
        }
    }
}


int main() {
    int n = 4, k = 2;
    vector<vector<int>> times = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};


     nodes = n;
     edges = times.size();

    for (int i = 0; i < edges; i++) {
        int u = times[i][0], v = times[i][1], w = times[i][2];
        adj_list[u].push_back({v, w});
    }

    dijkstra(k);

    long long res = 0;
    for (int i = 1; i <= nodes; i++) {
        if (i != k && d[i] == INF) {
            return -1;
        }
        res = max(res, d[i]);
    }

   
    cout << res;

    return 0;
}
