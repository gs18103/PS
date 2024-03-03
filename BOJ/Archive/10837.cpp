#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int k, c;
	cin >> k >> c;

	while(c--) {
		int n, m;
		cin >> n >> m;
		if(n == m) cout << "1\n";
		else if(n > m) {
			if(k - n + m + 1 < n - 1) {
				cout << "0\n";
			}
			else cout << "1\n";
		}
		else {
			if(k - m + n + 1 < m) {
				cout << "0\n";
			}
			else cout << "1\n";
		}
	}
}