#include <bits/stdc++.h>
 
using namespace std;
#define x first
#define y second
 
pair <int, int> arr[202020];
int mst[20][202020];
long long ans = 0;
 
void update(vector <int> &tree, int i, int val) {
	while(i < tree.size()) {
		tree[i] = max(tree[i], val);
		i += (i & -i);
	}
}
 
int cal(vector <int> &tree, int i) {
	int re = 0;
	while(i > 0) {
		re = max(re, tree[i]);
		i -= (i & -i);
	}
	return re;
}
 
void merge(int s, int e, int dep) {
	if(s == e) {
		mst[dep][s] = s;
		return;
	}
	int m = (s + e) / 2;
	merge(s, m, dep+1); merge(m+1 ,e, dep+1);
 
	int d1 = s, d2 = m + 1, d = s;
	while(d1 <= m && d2 <= e) {
		if(arr[mst[dep+1][d1]].y < arr[mst[dep+1][d2]].y) mst[dep][d++] = mst[dep+1][d1++];
		else mst[dep][d++] = mst[dep+1][d2++];
	}
	while(d1 <= m) {
		mst[dep][d++] = mst[dep+1][d1++];
	}
	while(d2 <= e) {
		mst[dep][d++] = mst[dep+1][d2++];
	}
}
 
void dnc(int s, int e, int dep) {
	if(s == e) return;
	int m = (s + e) / 2;
	int d1 = s, d2 = m + 1;
	long long re = 0;
	vector <pair <int, int> > l, r;
	vector <int> tree;
	tree.resize(e - s + 5);
	for(; d2 <= e; d2++) {
		//cout << arr[mst[dep][d1]].y << " " << arr[mst[dep][d2]].y << endl;
		while(d1 <= m && arr[mst[dep][d1]].y < arr[mst[dep][d2]].y) {
			while(!l.empty()) {
				//cout << l[l.size()-1].x << " " << mst[dep][d1] << endl;
				if(l[l.size()-1].y > mst[dep][d1]) break;
				l.pop_back();
			}
			l.push_back(make_pair(arr[mst[dep][d1]].y, mst[dep][d1]));
			d1++;
		}
		//cout << l.size() << endl;
		re += (int)(l.end() - upper_bound(l.begin(), l.end(), make_pair(cal(tree, mst[dep][d2] - m), 0)));
		update(tree, mst[dep][d2] - m, arr[mst[dep][d2]].y);
	}
	//cout << s << " " << e << " " << re << endl;
	ans += re;
	dnc(s, m, dep+1);
	dnc(m+1, e, dep+1);
}
 
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> arr[i].x >> arr[i].y;
	}
	sort(arr+1, arr+n+1);
	merge(1, n, 0);
	/*for(int i = 0; i < 5; i++) {
		for(int j = 1; j <= n; j++) {
			cout << mst[i][j] << " ";
		}
		cout << endl;
	}*/
	dnc(1, n, 1);
	cout << ans;
}