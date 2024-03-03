#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;
typedef pair <int, int> pii;

int arr[101][101], cnt[101][101], t[101][101];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool chk[101][101];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}

	deque <pii> dq;
	dq.push_back({1, 1});
	int ans = 0;
	while(!dq.empty()) {
		int x = dq.front().fi, y = dq.front().se;
		dq.pop_front();
		ans = max(ans, t[x][y]);
		for(int i = 0; i < 4; i++) {
			int tx = x + dx[i], ty = y + dy[i];
			if(tx == 0 || tx > n || ty == 0 || ty > m) continue;
			if(chk[tx][ty]) continue;
			if(arr[tx][ty] == 1) {
				cnt[tx][ty]++;
				if(cnt[tx][ty] == 2) {
					t[tx][ty] = t[x][y] + 1;
					chk[tx][ty] = true;
					dq.push_back({tx, ty});
				}
			}
			else {
				t[tx][ty] = t[x][y];
				chk[tx][ty] = true;
				dq.push_front({tx, ty});
			}
		}
	}
	cout << ans;
}