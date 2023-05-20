#include<bits/stdc++.h>
using namespace std;

int digitOfSumsCalculation(int n) {
    if (n == 0) {
        return 0;
    } else {
        return n % 10 + digitOfSumsCalculation(n / 10);
    }
}

int main() {
    int n;
    cin >> n;

    cout << digitOfSumsCalculation(n);

    return 0;
}
