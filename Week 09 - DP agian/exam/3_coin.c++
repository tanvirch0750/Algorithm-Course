#include<bits/stdc++.h>
using namespace std;

const int N = 101;

int nums[N];
int dp[N];

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) 
        cin >> nums[i];
    
    // 1. Handle Base Case
    dp[0] = 1; 
    
    // 2. Loop Over the States
    for (int i = 1; i <= m; i++) {
        dp[i] = 0;
        // 2.1. Calculate Answer from Smaller Subproblems
        for (int j = 0; j < n; j++) {
            if (i >= nums[j]) {
                dp[i] = (dp[i] + dp[i - nums[j]]);
            }
        }
    }

    cout << dp[m] << endl;

    return 0;
}
