#include<bits/stdc++.h>
using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int n, x;
    cin >> n >> x;

    vector<pair<int, int>> nums;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        nums.push_back(make_pair(num, i + 1));
    }

    sort(nums.begin(), nums.end());

    int pointerLeft = 0, pointerRight = n - 1;
    
    while (pointerLeft < pointerRight) {
        int res = nums[pointerLeft].first + nums[pointerRight].first;
        if (res == x) {
            int res1 = nums[pointerLeft].second;
            int res2 = nums[pointerRight].second;

            if (res1 > res2) swap(res1, res2);
            
            cout << res1 << " " << res2;
            return 0;
        } else if (res < x) {
            pointerLeft++;
        } else {
            pointerRight--;
        }
    }

    cout << "IMPOSSIBLE";

    return 0;
}
