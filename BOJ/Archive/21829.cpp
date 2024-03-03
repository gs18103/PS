#include <bits/stdc++.h>
#include "secret.h"
#define fi first
#define se second
#define eb emplace_back
#define em emplace
#define all(v) v.begin(), v.end()

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 1030;
const int INF = 1e9;
const ll LINF = 1e18;

int A[MAX], L[4*MAX][MAX], R[4*MAX][MAX];

void init(int node, int s, int e) {
    if(e - s + 1 == 4) return;
    int m = s + e >> 1;
    init(node<<1, s, m);
    init(node<<1|1, m+1, e);
    L[node][m] = A[m];
    for(int i = m - 1; i >= s; i--) {
        L[node][i] = Secret(A[i], L[node][i+1]);
    }
    R[node][m+1] = A[m+1];
    for(int i = m + 2; i <= e; i++) {
        R[node][i] = Secret(R[node][i-1], A[i]);
    }
}

void Init(int N, int a[]) {
    for(int i = 0; i < N; i++) {
        A[i+1] = a[i];
    }
    init(1, 0, 1023);
}

int cal(int node, int s, int e, int l, int r) {
    int m = s + e >> 1;
    if(r == m) return L[node][l];
    if(l == m + 1) return R[node][r];
    if(r < m) return cal(node<<1, s, m, l, r);
    if(l > m + 1) return cal(node<<1|1, m+1, e, l, r);
    return Secret(L[node][l], R[node][r]);
}

int Query(int l, int r) {
    l++, r++;
    if(l == r) return A[l];
    if(r - l == 1) return Secret(A[l], A[r]);
    return cal(1, 0, 1023, l, r);
}