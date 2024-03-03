#include <bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0)->sync_with_stdio(false);
  string s;
  cin >> s;
  int num = 0, mx = 0, mn = 0;
  for(int i = 0; i < s.size(); i++) {
    if(s[i] == 'K') num++;
    else num--;
    mx = max(mx, num);
    mn = min(mn, num);
  }
  cout << mx - mn;
  return 0;
}
