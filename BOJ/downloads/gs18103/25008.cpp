#include <bits/stdc++.h>

using namespace std;

vector <int> get_fail(vector <int> v, int n) {
	vector <int> F(n);
	int p = 0;
	for(int i = 1; i < n; i++) {
		while(p > 0 && v[i] != v[p] && (v[i] < p || v[p] <= p)) {
			p = F[p-1];
		}
		if(v[i] >= p && v[p] > p) p++;
		else if(v[i] == v[p]) p++;
		F[i] = p;
	}
	return F;
}

int findP(char T[], char P[], int n, int m) {

	vector <int> t(n), s(m);
	vector <int> pre(26, -1);

	for(int i = 0; i < n; i++) {
		t[i] = i - pre[T[i]-'a'];
		pre[T[i]-'a'] = i;
	}
	for(int i = 0; i < 26; i++) pre[i] = -1;
	for(int i = 0; i < m; i++) {
		s[i] = i - pre[P[i]-'a'];
		pre[P[i]-'a'] = i;
	}

	vector <int> F = get_fail(s, m);

	int p = 0, ans = 0;
	for(int i = 0; i < n; i++) {
		while(p > 0 && t[i] != s[p] && (t[i] < p || s[p] <= p)) {
			p = F[p-1];
		}
		if(t[i] >= p && s[p] > p) p++;
		else if(t[i] == s[p]) p++;
		if(p == m) {
			ans++;
			p = F[p-1];
		}
	}

	return ans;
}
