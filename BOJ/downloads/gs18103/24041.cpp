#include <bits/stdc++.h>

#define fi first

#define se second

#define all(v) v.begin(), v.end()

#define eb emplace_back

#define em emplace

using namespace std;

typedef long long ll;

typedef pair <int, int> pii;

typedef pair <ll, ll> pll;

const int MAX = 201010;

int n, k;

ll g, S[MAX], L[MAX];

int O[MAX];

bool chk(ll x) {

  ll sum = 0;

  vector <ll> temp;

  for(int i = 1; i <= n; i++) {

    sum += max(1LL, x - L[i]) * S[i];

    if(O[i]) temp.eb(max(1LL, x - L[i]) * S[i]);

  }

  sort(all(temp));

  for(int i = 0; i < k && !temp.empty(); i++) {

    sum -= temp.back();

    temp.pop_back();

  }

  if(sum <= g) return true;

  else return false;

}

int main() {

	  ios::sync_with_stdio(false);          	  cin.tie(0);

	  

	  cin >> n >> g >> k;

	  

	  for(int i = 1; i <= n; i++) {

	    cin >> S[i] >> L[i] >> O[i];

	  }

	  

	  ll lb = 0, ub = 2020202020;

	  while(lb < ub) {

	    ll m = lb + ub + 1 >> 1;

	    if(chk(m)) lb = m;

	    else ub = m - 1;

	  }

	  cout << lb;

}