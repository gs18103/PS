#include <bits/stdc++.h>
#define eb emplace_back

using namespace std;

int fail[1010101];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int n;
	string s;
	cin >> n >> s;
	int p = 0;
	for(int i = 1; i < n; i++) {
		while(p > 0 && s[i] != s[p]) {
			p = fail[p];
		}
		if(s[i] == s[p]) p++;
		fail[i+1] = p;
	}
	cout << n - fail[n];
}