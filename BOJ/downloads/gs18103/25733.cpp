#include <bits/stdc++.h>

using namespace std;

int a[202020];

bool chk[202020];

int main(){

  ios::sync_with_stdio(false); cin.tie(0);

  

  int n;

  cin >> n;

  for(int i = 1; i <= n; i++) {

    cin >> a[i];

    chk[a[i]] = true;

  }

  

  set <int> st;

  for(int i = 1; i <= n; i++) {

    if(!chk[i]) st.insert(i);

  }

  a[n+1] = a[0] = -1;

  

  for(int i = 1; i <= n && st.size() > 10; i++) {

    if(a[i] > 0) continue;

    auto it = st.begin();

    while(it != st.end() && abs(*it - a[i-1]) == 1) it = next(it);

    while(it != st.end() && abs(*it - a[i+1]) == 1) it = next(it);

    a[i] = *it;

    st.erase(*it);

  }

  

  vector <int> idx, v;

  

  for(int i = 1; i <= n; i++) {

    if(a[i]<0) idx.push_back(i);

  }

  

  for(auto i : st) v.push_back(i);

  

  for(int i = 0; i < 3628800; i++) {

    bool flag = false;

    for(int j = 0; j < idx.size(); j++) {

      if(abs(a[idx[j]-1] - v[j]) == 1 || abs(a[idx[j]+1] - v[j]) == 1) flag = true;

      if(j && idx[j] == idx[j-1] + 1 && abs(v[j] - v[j-1]) == 1) flag = true;

    }

    if(!flag) {

      for(int j = 0; j < idx.size(); j++) {

        a[idx[j]] = v[j];

      }

      break;

    }

    next_permutation(v.begin(), v.end());

  }

  

  for(int i = 1; i <= n; i++) {

    if(a[i] == -1 || abs(a[i] - a[i-1]) == 1) {

      cout << -1;

      return 0;

    }

  }

  

  for(int i = 1; i <=n; i++) {

    cout << a[i] << ' ';

  }

  return 0;

}

