#include <bits/stdc++.h>

using namespace std;

int A[110][110], B[110][110];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> A[i][j];
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> B[i][j];
        }
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cout << A[i][j] + B[i][j] << ' ';
        }
        cout << endl;
    }
}