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

int idx[101];

void print(int x) {

  if(x < 0) return;

  print(x - 1);

  cout << idx[x] + 1 << '\n';

  print(x - 1);

}

int main() {

	  ios::sync_with_stdio(false); 	  cin.tie(0);

	    

  int n;

  cin >> n;

  vector <int> a(n);

  for(int i = 0; i < n; i++) {

    cin >> a[i];

    idx[i] = i;

  }

    

  int bit = 19, cnt = 0;

  for(int i = 0; i < n; i++) {

    bool flag = false;

    while(!flag && bit >= 0) {

      for(int j = i; j < n; j++) {

        if(a[j] >> bit & 1) {

          if(!(a[i] >> bit & 1)){

            swap(a[i], a[j]);

            swap(idx[i], idx[j]);

          }

          else if(idx[i] > idx[j]) {

            swap(a[i], a[j]);

            swap(idx[i], idx[j]);

          }

          flag = true;

        }

      }

      bit--;

    }

    if(!flag) break;

    cnt++;

    

    bit++;

    for(int j = i + 1; j < n; j++) {

      if(a[j] >> bit & 1) {

        a[j] ^= a[i];

      }

    }

    bit--;

  }

  

  cout << (1 << cnt) - 1 << '\n';

  sort(idx, idx + cnt);

  print(cnt - 1);

}       

	    