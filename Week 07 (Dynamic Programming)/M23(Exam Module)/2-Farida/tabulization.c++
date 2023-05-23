#include <iostream>
using namespace std;
const int N = 1e5 + 5;

long long h[N];

int main() {
    int k;
    cin >> k;

    for (int j = 1; j <= k; j++) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> h[i];
        }

        long long dp[N];

        // 1. base case
        dp[0] = h[0];
        dp[1] = max(h[0], h[1]);
         
        // 2. loop through the states
        for (int i = 2; i < n; i++) {
            // 2.1. and calculate the answer from smaller sub-problems
            dp[i] = max(dp[i-1], dp[i-2] + h[i]);
        }

        cout << "Case " << j << ": " << dp[n-1] << endl;
    }

    return 0;
}
