#include<bits/stdc++.h>
using namespace std;
const int N = 3003;

string dp[N][N];
int n, m;
string s, t;

string LCS(int i, int j) {
    // 1. base case
    if (i == n || j == m) {
        return "";
    }

    // 2. if result is already calculated, return it
    if (!dp[i][j].empty()) {
        return dp[i][j];
    }

    // 3. calculate result from smaller sub-problems
    if (s[i] == t[j]) {
        string ans = LCS(i + 1, j + 1);
        dp[i][j] = s[i] + ans;
        return dp[i][j];
    }

    string res1 = LCS(i + 1, j);
    string res2 = LCS(i, j + 1);

    if (res1.length() > res2.length()) {
        dp[i][j] = res1;
        return res1;
    } else {
        dp[i][j] = res2;
        return res2;
    }
}


int main() {
    cin >> s >> t;

    n = s.size();
    m = t.size();

    for (int i = 0 ; i <= n ; i++) {
        for (int j = 0 ; j <= m ; j++) {
            dp[i][j] = "";
        }
    }

    cout << LCS(0, 0) << endl;
    return 0;
}
