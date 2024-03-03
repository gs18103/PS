#include <bits/stdc++.h>

#define fi first

#define se second

#define eb emplace_back

#define em emplace

#define all(v) v.begin(), v.end()

#define reset(x) memset(x, 0, sizeof(x))

using namespace std;

typedef long long ll;

typedef long double ld;

typedef complex <double> cpx;

typedef pair <int, int> pii;

typedef pair <ll, ll> pll;

const int MAX = 101010;

const int INF = 1e9;

const ll LINF = 1e18;

int main() {

  ios::sync_with_stdio(false); cin.tie(nullptr);

  int n, m;

  cin >> n >> m;

  vector <int> v(n);

  int mx = 0;

  for(int i = 0; i < n; i++) {

    cin >> v[i];

    mx = max(mx, v[i]);

  }

  

  int lb = mx, ub = 1e9;

  while(lb < ub) {

    int mi = lb + ub >> 1;

    int cnt = 1, sum = 0;

    for(int i = 0; i < n; i++) {

      if(sum + v[i] > mi) cnt++, sum = 0;

      sum += v[i];

    }

    if(cnt <= m) ub = mi;

    else lb = mi + 1;

  }

  cout << lb;

}

