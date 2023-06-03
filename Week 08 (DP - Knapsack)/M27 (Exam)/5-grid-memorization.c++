#include<bits/stdc++.h>
using namespace std;
const int N = 1001;

long long dp[N][N];
char grid[N][N];

long long gridPaths(int n, int m) {
    // Base cases
    if (grid[0][0] == '*' || grid[n - 1][m - 1] == '*'){
        return 0;
    }

    // If result is already calculated, return it
    if (dp[n][m] != -1){
         return dp[n][m];
    }  

    // Calculate result from smaller subproblems
    if (n == 1 && m == 1) {
         return dp[n][m] = 1;
    }
       
    long long ans = 0;

    if (n > 1 && grid[n - 2][m - 1] != '*') {
        ans = ans + gridPaths(n - 1, m);
    }
        
    if (m > 1 && grid[n - 1][m - 2] != '*') {
        ans = ans + gridPaths(n, m - 1);
    }
        

    return dp[n][m] = ans;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
             cin >> grid[i][j];
        }
    }    

    memset(dp, -1, sizeof(dp));

    long long ans = gridPaths(n, n);
    cout << ans << endl;

    return 0;
}
