#include<bits/stdc++.h>
using namespace std;

const int maxN = 2e5;
vector<int> adj[maxN];
vector<bool> visited(maxN);



void dfs(int node){
    visited[node] = true;
     for (int child : adj[node]){
        if (!visited[child]){
            dfs(child); 
        }
    }
}

int main(){
    int n, m;
    cin>>n>>m;

    for(int i=0;i<m;i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int count = 0;
    
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(i);
            count++;
        }
    }

    cout<<count<<endl;

    return 0;
}

