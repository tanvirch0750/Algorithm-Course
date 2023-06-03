#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int INF = 2e9;

int dp[N];


int squares(int n) {
     // 1. base case
    if (n == 0){
         return 0;
    }
       
    // 2. check if current state is already solved
    if (dp[n] != -1) {
       return dp[n];
    }
        
    int minres = INF;

    // 3. calculate answer from smaller sub-problems
    for (int i = 1; i * i <= n; i++) {
        int sq = squares(n - i * i) + 1;
        minres = min(minres, sq);
    }
    
    dp[n] = minres;
    return minres;
}



int main() {
    int n;
    cin >> n;
    
    // mark all states as unvisited
    for(int i = 1 ; i <= n ; i++) {
        dp[i] = -1;  
    }


    int ans = squares(n);
    cout << ans << endl;

    return 0;
}
