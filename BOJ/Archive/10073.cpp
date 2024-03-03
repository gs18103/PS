#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define em emplace
#define all(v) v.begin(), v.end()
 
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
 
const int MAX = 101010;
const int INF = INT_MAX >> 1;
const ll LINF = LLONG_MAX >> 1;
const ll mod = 1e9+9;
 
int valid(int n, int arr[]) {
	vector <bool> chk(250050);
	int idx = -1;
	for(int i = 0; i < n; i++) {
		if(arr[i] <= n && idx == -1) {
			idx = i;
		}
		else if(arr[i] <= n) {
			int temp = arr[idx] + i - idx;
			temp %= n;
			if(temp == 0) temp = n;
			if(temp != arr[i]) return 0;
		}
	}
	sort(arr, arr+n);
	for(int i = 1; i < n; i++) {
		if(arr[i] == arr[i-1]) return 0;
	}
	return 1;
}
 
int replacement(int n, int gondolaSeq[], int replacementSeq[]) {
	int l = 0;
	vector <int> ori(n, -1);
	for(int i = 0; i < n; i++) {
		l = max(gondolaSeq[i] - n, l);
		if(gondolaSeq[i] <= n && ori[0] == -1) {
			ori[i] = gondolaSeq[i];
			for(int j = 1; j < n; j++) {
				ori[(i+j)%n] = (ori[i] + j) % n;
				if(ori[(i+j)%n] == 0) ori[(i+j)%n] = n;
			}
		}
	}
	if(ori[0] == -1) {
		for(int i = 0; i < n; i++) ori[i] = i + 1;
	}
	vector <pii> temp;
	for(int i = 0; i < n; i++) {
		temp.eb(gondolaSeq[i], i);
	}
	sort(all(temp));
	int idx = 0, last = n + 1;
	for(int i = 0; i < n; i++) {
		if(temp[i].fi > n) {
			replacementSeq[idx++] = ori[temp[i].se];
			while(last < temp[i].fi) {
				replacementSeq[idx++] = last++;
			}
			last++;
		}
	}
	return l;
}
 
ll mypow(ll a, ll b) {
	ll ret = 1;
	while(b) {
		if(b & 1) ret = (ret * a) % mod;
		b >>= 1;
		a = (a * a) % mod;
	}
	return ret;
}
 
int countReplacement(int n, int inputSeq[]) {
	if(!valid(n, inputSeq)) return 0;
	ll ans = n;
	for(int i = 0; i < n; i++) {
		if(inputSeq[i] <= n) ans = 1;
	}
	sort(inputSeq, inputSeq+n);
	int last = n;
	for(int i = 0; i < n; i++) {
		if(inputSeq[i] > n) {
			ans = (ans * mypow(n - i, inputSeq[i] - last - 1)) % mod;
			last = inputSeq[i];
		}
	}
	return ans;
}

int rep[303030];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n;
    cin >> n;
    int v[n];
    memset(v, 0, n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int l = replacement(n, v, rep);
    cout << l << ' ';
    for(int i = 0; i < l; i++) {
        cout << rep[i] << ' ';
    }
}