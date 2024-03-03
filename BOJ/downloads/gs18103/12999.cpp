#include <bits/stdc++.h>
#define eb emplace_back
#define em emplace
#define all(v) v.begin(), v.end()
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 101010;
const int INF = (int)1e9;
const ll LINF = (ll)1e18;

struct Query {
    int s, e, idx;
};

int A[MAX], cnt[2*MAX], rcnt[2*MAX], bucket[606];
int ans[MAX];
Query Q[MAX];
vector <int> num;

void add(int x) {
    rcnt[cnt[x]]--;
    bucket[cnt[x]/400]--;
    cnt[x]++;
    rcnt[cnt[x]]++;
    bucket[cnt[x]/400]++;
}

void erase(int x) {
    rcnt[cnt[x]]--;
    bucket[cnt[x]/400]--;
    cnt[x]--;
    rcnt[cnt[x]]++;
    bucket[cnt[x]/400]++;
}

void get_ans(int x) {
    for(int i = 300; i >= 0; i--) {
        if(bucket[i] > 0) {
            for(int j = 400 * (i + 1) - 1; j >= 400 * i; j--) {
                if(rcnt[j] != 0) {
                    ans[Q[x].idx] = j;
                    break;
                }
            }
            break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        cin >> A[i];
        A[i] += 100000;
    }
    for(int i = 1; i <= q; i++) {
        cin >> Q[i].s >> Q[i].e;
        Q[i].idx = i;
    }
    sort(Q + 1, Q + q + 1, [](Query a, Query b) {
        if(a.s / 400 != b.s / 400) return a.s / 400 < b.s / 400;
        return a.e < b.e;
    });

    int s = Q[1].s, e = Q[1].e;
    rcnt[0] = n;
    bucket[0] = n;
    for(int i = s; i <= e; i++) {
        add(A[i]);
    }
    get_ans(1);
    for(int i = 2; i <= q; i++) {
        while(Q[i].s < s) {s--; add(A[s]);}
        while(Q[i].e > e) {e++; add(A[e]);}
        while(Q[i].s > s) {erase(A[s]), s++;}
        while(Q[i].e < e) {erase(A[e]), e--;};
        get_ans(i);
    }

    for(int i = 1; i <= q; i++) {
        cout << ans[i] << '\n';
    }
}