#include<bits/stdc++.h>
using namespace std;
const int N = 1001;

long long dp[N][N];
char grid[N][N];

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
         for (int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }       

    // Initializing the dp array with -1
    memset(dp, 0, sizeof(dp));

    // 1. base case
    dp[0][0] = 1;

    for (int i = 1; i < n; i++) {

        if (grid[0][i] != '*') {
             dp[0][i] = dp[0][i - 1];
        }
           
        if (grid[i][0] != '*') {
             dp[i][0] = dp[i - 1][0];
        }
           
    }

    // 2. loop over the states
    for (int i = 1; i < n; i++) {

        for (int j = 1; j < n; j++) {

            if (grid[i][j] != '*') {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            } else {
                dp[i][j] = 0;
            }

        }
    }

    cout << dp[n - 1][n - 1] << endl;

    return 0;
}
