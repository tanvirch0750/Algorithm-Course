#include <iostream>
using namespace std;

const int N = 1e5;;
int dp[N];
const int INF = 2e9;

int calcOp(int n) {
     // 1. base cases
    if (n == 1){
        return 0;
    }
    
     // 2. check if current state is already solved
    if (dp[n] != -1){
      return dp[n];
    }
        
    // 3. calculate answer from smaller sub-problems
    int ans = INF;

    if (n % 3 == 0) {
        ans = min(ans, calcOp(n / 3));
    }
    if (n % 2 == 0) {
        ans = min(ans, calcOp(n / 2));
    }
    ans = min(ans, calcOp(n - 1));
   

    dp[n] = ans + 1;
    return dp[n];
}

int main() {
    int n;
    cin >> n;

   for(int i = 1 ; i <= n ; i++) {
        dp[i] = -1;  // mark all states as unvisited
    }

    cout << calcOp(n) << endl;

    return 0;
}
