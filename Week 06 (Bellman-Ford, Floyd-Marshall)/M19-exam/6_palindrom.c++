#include<bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;

    int fc[26] = {0};

    for (char chr : str) 
        fc[chr - 'a']++;

    int count = 0; 
    
    for (int i = 0; i < 26; i++) {
        if (fc[i] % 2 != 0) 
            count++;
    }
   
    if (count <= 1) 
        cout << "YES";
    else 
        cout << "NO";
    
    return 0;
}
