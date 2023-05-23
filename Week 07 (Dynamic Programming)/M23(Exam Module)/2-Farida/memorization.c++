#include <iostream>
using namespace std;
const int N = 1e5 + 5;

int h[N];
int dp[N];

int farida(int n) {
    // 1. base case
    if (n == 0) {
        return h[0];
    }

    // 2. check if answer already exists
    if (dp[n] != -1) {
        return dp[n];
    }

    // 3. calculate answer from subproblems
    int ans1 = farida(n - 1);

    // corner case
    if (n == 1) {
        dp[n] = max(h[0], h[1]);
        return dp[n];
    }

    int ans2 = farida(n - 2) + h[n];
    int ans = max(ans1, ans2);

    dp[n] = ans;
    return ans;
}

int main() {
    int k;
    cin >> k;

    for (int j = 1; j <= k; j++) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> h[i];
        }

        for (int i = 0; i <= n; i++) {
            dp[i] = -1;
        }
        cout << "Case " << j << ": " << farida(n - 1) << endl;
    }

    return 0;
}
