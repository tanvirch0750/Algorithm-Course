#include <iostream>
using namespace std;
const int N = 101;

int dp[N];

int main() {
    int n;
    cin >> n;

    // 1. base cases
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;

    // 2. loop through the states
    for (int i = 3; i <= n; i++) {
        // 2.1. calculate the answer from smaller sub-problems
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    cout << dp[n] << endl;
    return 0;
}
