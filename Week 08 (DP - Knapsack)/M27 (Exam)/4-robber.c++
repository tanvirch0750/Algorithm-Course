#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int INF = 2e9;

int nums[N], dp[N];
int n;

int robberHouse(int n, int m) {
    // Base case
    if (n > m) {
        return 0;
    }

    // If answer is already calculated, return it
    if (dp[n] != -1) {
        return dp[n];
    }

    // 3. calculate answer from smaller sub-problems
    int ans1 = nums[n] + robberHouse(n + 2, m - 1);
    int ans2 = robberHouse(n + 1, m);

    
    int ans = max(ans1, ans2);
    dp[n] = ans;
    return ans;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Initialize dp array with -1
    memset(dp, -1, sizeof(dp));

  
    int ans = robberHouse(0, n - 1);
   
    cout << ans << endl;
}
