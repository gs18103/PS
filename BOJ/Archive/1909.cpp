#include <iostream>
#include <algorithm>
#include <queue>
#include <memory.h>
using namespace std;
 
typedef pair<int, int> pii;
 
int h, w, sx, sy, tx, ty;
int n, dx[] = { 0,0,1,-1,-1,-1,1,1 }, dy[] = { 1,-1,0,0,-1,1,-1,1 };
int a[1000011], b[1000011];
int d[1001][1001], d2[1001][1001];
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    memset(d, 0x3f, sizeof(d));
    cin >> w >> h;
    // h : x, w : y
    cin >> sy >> sx >> ty >> tx >> n;
    queue<pair<pii, int>> q;
    int minv = 1e9, mx = 0, my = 0, mi = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        q.push({ { b[i],a[i] },i });
        d[b[i]][a[i]] = 0;
    }
    while (q.size()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int st = q.front().second;
        q.pop();
        for (int i = 0; i < 8; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nc = ((b[st] - nx)*(b[st] - nx) + (a[st] - ny)*(a[st] - ny));
            if (nx < 1 || ny < 1 || nx > h || ny > w || d[nx][ny] <= nc) continue;
            q.push({ { nx,ny },st });
            d[nx][ny] = nc;
        }
    }
    memset(d2, -1, sizeof(d2));
    priority_queue<pair<int, pii>> q2;
    q2.push({ d[sx][sy],{ sx,sy } });
    while (q2.size()) {
        int c = q2.top().first;
        int x = q2.top().second.first;
        int y = q2.top().second.second;
        q2.pop();
        if (d2[x][y] != -1) continue;
        d2[x][y] = c;
        if (x == tx && y == ty) break;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 1 || ny < 1 || nx > h || ny > w || d2[nx][ny] != -1) continue;
            q2.push({ min(c,d[nx][ny]),{ nx,ny } });
        }
    }
    cout << d2[tx][ty];
    return 0;
}
