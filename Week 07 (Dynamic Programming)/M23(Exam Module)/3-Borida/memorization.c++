#include <iostream>
using namespace std;

const int N = 1e5;
int h[N];
long long dp[N];

long long boredom(int n) {
    // 1. base case
    if (n == 1) {
        return h[1];
    }

    // 2. check if answer already exists
    if (dp[n] != -1) {
        return dp[n];
    }

    // 3. calculate answer from subproblems
    long long ans1 = boredom(n - 1);
    long long ans2 = boredom(n - 2) + h[n];

    long long ans = max(ans1, ans2);
    dp[n] = ans;

    return ans;
}

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }

    // Initialize dp array with -1
    for (int i = 1; i <= n; i++) {
        dp[i] = -1;
    }

    long long ans = boredom(n);
    cout << ans << endl;

    return 0;
}
