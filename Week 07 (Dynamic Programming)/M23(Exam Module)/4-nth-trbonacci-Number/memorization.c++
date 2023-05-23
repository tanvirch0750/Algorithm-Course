#include<bits/stdc++.h>
using namespace std;
const int N = 101;


int dp[N]; // dp array

int fibonacci(int n) {
    // 1. base cases
    if (n == 0) return 0;
    if (n <= 2) return 1;

    // 2. check if current state is already solved
    if (dp[n] != -1) {
        return dp[n];
    }

    // 3. calculate from smaller sub-problems
    int ans = fibonacci(n - 1) + fibonacci(n - 2) + fibonacci(n - 3);
    dp[n] = ans;
    return ans;
}

int main() {
    int n;
    cin >> n;

   for(int i = 1 ; i <= n ; i++) {
        dp[i] = -1;  // mark all states as unvisited
    }

    cout << fibonacci(n) << endl;
    return 0;
}
