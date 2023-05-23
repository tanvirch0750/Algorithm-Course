#include <iostream>
using namespace std;

const int N = 1e5;
int h[N];
long long dp[N];

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }

    // 1. handle base case
    dp[1] = h[1];

    // 2. loop through the states
    for (int i = 2; i <= n; i++) {
        // Calculate the maximum points for the current state
        long long ans1 = dp[i - 1];
        long long ans2 = (long long)h[i] + dp[i - 2];
        dp[i] = max(ans1, ans2);
    }

    long long ans = dp[n];
    cout << ans << endl;

    return 0;
}
