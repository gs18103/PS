#include <bits/stdc++.h>
#define eb emplace_back
#define fi first
#define se second

using namespace std;
typedef pair <int, int> pii;

bool chk[1010101];
int pre[1010101];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		if(n == 1) {
			cout << "1\n";
			continue;
		}
        memset(chk, false, sizeof(bool)*n);
        memset(pre, -1, sizeof(int)*n);
		queue <int> q;
		q.push(1);
		chk[1] = true;
		while(!q.empty()) {
			int x = q.front();
			q.pop();
			if(x == 0) break;
			if(!chk[(x*10)%n]) {
				q.push((x*10)%n);
				pre[(x*10)%n] = x;
				chk[(x*10)%n] = true;
			}
			if(!chk[(x*10+1)%n])  {
				q.push((x*10+1)%n);
				pre[(x*10+1)%n] = x;
				chk[(x*10+1)%n] = true;
			}
		}
		if(pre[0] == -1) {
			cout << "BRAK\n";
			continue;
		}
		int num = 0;
		string ans = "";
		while(num != 1) {
			if((pre[num] * 10) % n == num) ans = "0" + ans;
			else ans = "1" + ans;
			num = pre[num];
		}
		ans = "1" + ans;
		cout << ans << '\n';
	}
}