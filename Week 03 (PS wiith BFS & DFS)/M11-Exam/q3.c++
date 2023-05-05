// Write a c++  program  to solve cycle detection in a directed graph using DFS.

/*
4 4
1 3
2 1
2 4
3 4
*/

#include<bits/stdc++.h>
using namespace std;
const int N = 2e5;

vector<int>adj_list[N];
int visited[N];

bool dfs(int node) {

    visited[node] = 1;

    for(int adj_node: adj_list[node]) {
        
        if(visited[adj_node] == 0) {
            bool ok = dfs(adj_node);
            if(ok)
                return true;
        }
        else if(visited[adj_node] == 1) {
            return true;
        }
    }
    visited[node] = 2;
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    for(int i = 0 ; i < m ; i++) {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
    }
    bool res = false;

    for(int i = 1 ; i <= n ; i++) {
        if(visited[i] == 0) {
            bool ok = dfs(i);
            if(ok) {
                res = true;
                break;
            }
        }
    }

    if(res) {
        cout<<"YES"<<endl;
    }
    else {
        cout<<"NO"<<endl;
    }

}