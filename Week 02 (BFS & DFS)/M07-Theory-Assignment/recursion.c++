#include <bits/stdc++.h>
using namespace std;

int recursionPow(int n, int m) {
  if (m == 0) 
    return 1;
  
  return n * recursionPow(n, m - 1);
}

int main() {
  int n, m;
  cin >> n >> m;
  
  cout << recursionPow(n, m) << endl;
  return 0;
}
