#include "shoes.h"
#include <bits/stdc++.h>
#define eb emplace_back
#define em emplace
#define fi first
#define se second
#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 101010;
const int INF = 1e9;
const ll LINF = 1e18;

class BinaryIndexedTree {
	vector <int> tree;
	int sz;
public:
	void Init(int n) {
		sz = n;
		tree.resize(n+1);
	}
	void update(int i, int val) {
		while(i <= sz) {
			tree[i] += val;
			i += (i & -i);
		}
	}
	int cal(int l, int r) {
		int ret = 0;
		while(r > 0) {
			ret += tree[r];
			r -= (r & -r);
		}
		l--;
		while(l > 0) {
			ret -= tree[l];
			l -= (l & -l);
		}
		return ret;
	}
};

ll count_swaps(vector<int> s) {
	int n = s.size() / 2;
	vector <int> pre(2*n);
	vector <queue <int> > pos(n+1), neg(n+1);
	
	for(int i = 0; i < 2 * n; i++) {
		if(s[i] > 0) {
			if(neg[s[i]].empty()) {
				pre[i] = -1;
				pos[s[i]].push(i);
			}
			else {
				pre[i] = neg[s[i]].front();
				neg[s[i]].pop();
			}
		}
		else {
			if(pos[-s[i]].empty()) {
				pre[i] = -1;
				neg[-s[i]].push(i);
			}
			else {
				pre[i] = pos[-s[i]].front();
				pos[-s[i]].pop();
			}
		}
	}
	BinaryIndexedTree BIT;
	BIT.Init(2*n);
	ll ans = 0;
	for(int i = 2 * n - 1; i >= 0; i--) {
		if(pre[i] == -1) continue;
		ans += i - pre[i] - BIT.cal(pre[i] + 1, i + 1);
		if(s[i] > 0) ans--;
		BIT.update(pre[i] + 1, 1);
	}
	return ans;
}
