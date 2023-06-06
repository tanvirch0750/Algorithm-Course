#include<bits/stdc++.h>
using namespace std;

const int N = 101;
const int MAX = 100001;

int coins[N];
int dp[MAX];
int totalRes = 0;


int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    for (int i = 0; i < MAX; i++) {
      dp[i] = false;
    }
    
    // 1. Handle Base Case
    dp[0] = true;
    
    // 2. Loop Over the States
    for (int i = 0; i < n; i++) {
        // 2.1. Calculate Answer from Smaller Subproblems
        for (int j = MAX - 1; j >= coins[i]; j--) {
            if (dp[j - coins[i]]) dp[j] = true;
        }
    }

   
    for (int i = 1; i < MAX; i++) {
        if (dp[i]) totalRes++;
    }

    cout << totalRes << "\n";

    for (int i = 1; i < MAX; i++) {
        if (dp[i]) cout << i << " ";
    }

    return 0;
}
