/*
  Adjacecny Matrix (undirected and unweighted)
  Total nodes and edgr = 4
  matrix[nodes][nodes]

  edges:
  0 --> 1    1 --> 2   2 --> 3   3 --> 1
  1 --> 0    2 --> 1   3 --> 2   1 --> 3
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int nodes = 4;
    int matrix[nodes][nodes] = {};

    matrix[0][1] = 1;
    matrix[1][0] = 1;
    matrix[1][2] = 1;
    matrix[2][1] = 1;
    matrix[2][3] = 1;
    matrix[3][2] = 1;
    matrix[3][1] = 1;
    matrix[1][3] = 1;

    // if there is a edge with every node
    // for(int i = 0; i < nodes; i++){
    //     for(int j = 0; j < nodes; j++){
    //         matrix[i][j] = 1;
    //     }
    // }



    for(int i = 0; i < nodes; i++){
        for(int j = 0; j < nodes; j++){
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    } 

}