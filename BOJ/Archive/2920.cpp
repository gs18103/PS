#include <bits/stdc++.h>

using namespace std;

int a[10];

int main() {
    ios::sync_with_stdio(false);

    for(int i = 1; i <= 8; i++) {
        cin >> a[i];
    }
    bool flag = false;
    for(int i = 1; i <= 8; i++) {
        if(a[i] != i) flag = true;
    }
    if(!flag) {
        cout << "ascending" << endl;
        return 0;
    }
    flag = false;
    for(int i = 1; i <= 8; i++) {
        if(a[i] != 9 - i) flag = true;
    }
    if(!flag) {
        cout << "descending" << endl;
        return 0;
    }
    cout << "mixed" << endl;
}