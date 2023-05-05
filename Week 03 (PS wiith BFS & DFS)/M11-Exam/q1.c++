// Write a c++  program to convert an Adjacency Matrix to an Adjacency List.

#include<bits/stdc++.h>
using namespace std;
const int N = 2002;

int grid[N][N];
int n;

int main() {

    cin >> n;
    vector<vector<int>> adjList(n);

    for (int i = 0;i < n;i++){
        for (int j = 0;j < n;j++){
            cin >> grid[i][j];
        }
    }

    for(int i =  0; i < n ; i++) {
        for(int j = 0; j < n ; j++) {
            if(grid[i][j] == 1) {
                adjList[i].push_back(j);
            }
        }
    }
    
    
    for(int i =0; i < n; i++){
        cout << i << ": ";
        for(int j = 0; j < adjList[i].size(); j++){
            cout << adjList[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}