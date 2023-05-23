#include <iostream>
using namespace std;

const int N = 1e5;

int main() {
    int n;
    cin >> n;

    int dp[N];

    // 1. Handle base cases
    dp[1] = 0;

    // 2. Loop through the states
    for (int i = 2; i <= n; i++) {
        // 2.1 Calculate the maximum points for the current state
        dp[i] = dp[i - 1]; 
        if (i % 2 == 0) {
            dp[i] = min(dp[i], dp[i / 2]);
        }
        if (i % 3 == 0) {
            dp[i] = min(dp[i], dp[i / 3]);
        }
             
        dp[i] = dp[i] + 1; 
    }

    cout << dp[n] << endl;

    return 0;
}
