#include <iostream>

using namespace std;

int a[3030][3030];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    int num = 1;
    int ansx, ansy;
    a[(n+1)/2][(n+1)/2] = 1;
    int x = n / 2, y = n / 2 + 1;
    for(int i = 1; i <= n / 2; i++) {
        for(int j = 0; j < 2 * i; j++) {
            a[x][y] = ++num;
            y++;
        }
        y--;
        x++;
        for(int j = 0; j < 2 * i; j++) {
            a[x][y] = ++num;
            x++;
        }
        x--;
        y--;
        for(int j = 0; j <2 *  i; j++) {
            a[x][y] = ++num;
            y--;
        }
        y++;
        x--;
        for(int j = 0; j <2 * i; j++) {
            a[x][y] = ++num;
            x--;
        }
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << a[i][j] << ' ';
            if(a[i][j] == m) ansx = i, ansy = j;
        }
        cout << '\n';
    }
    cout << ansx << ' ' << ansy;
}