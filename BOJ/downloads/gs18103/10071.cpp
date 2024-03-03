#include "game.h"
#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define em emplace
#define all(v) v.begin(), v.end()
#define report(x, l, s) stype[x] = s, location[x] = l, chk[x] = true
 
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
 
const int MAX = 2020;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;
 
int cnt[MAX];
 
void initialize(int n) {
    for(int i = 0; i < n; i++) cnt[i] = i;
}
 
int hasEdge(int u, int v) {
    cnt[max(u, v)]--;
    if(cnt[max(u,v)] == 0) return 1;
    return 0;
}
