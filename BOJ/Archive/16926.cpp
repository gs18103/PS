#include <bits/stdc++.h>

using namespace std;

int a[303][303];
int tmp[2020];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n, m, r;
    cin >> n >> m >> r;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    for(int i = 1; i <= min(n, m) / 2; i++) {
        int x = i, y = i, idx = 0;
        for(int j = 1; j < m - 2 * (i - 1); j++) {
            tmp[idx++] = a[x][y++];
        }
        for(int j = 1; j < n - 2 * (i - 1); j++) {
            tmp[idx++] = a[x++][y];
        }
        for(int j = 1; j < m - 2 * (i - 1); j++) {
            tmp[idx++] = a[x][y--];
        }
        for(int j = 1; j < n - 2 * (i - 1); j++) {
            tmp[idx++] = a[x--][y];
        }
        
        int len = idx;
        idx = 0;
        for(int j = 1; j < m - 2 * (i - 1); j++) {
            a[x][y++] = tmp[(idx+r)%len]; idx++;
        }
        for(int j = 1; j < n - 2 * (i - 1); j++) {
            a[x++][y] = tmp[(idx+r)%len]; idx++;
        }
        for(int j = 1; j < m - 2 * (i - 1); j++) {
            a[x][y--] = tmp[(idx+r)%len]; idx++;
        }
        for(int j = 1; j < n - 2 * (i - 1); j++) {
            a[x--][y] = tmp[(idx+r)%len]; idx++;
        }
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
}