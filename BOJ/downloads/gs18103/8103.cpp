#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define em emplace
#define all(v) v.begin(), v.end()
#define reset(x) memset(x, 0, sizeof(x))

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 101010;
const int INF = 1e9;
const ll LINF = 1e18;

struct Rectangle {
    int sx, ex, sy, ey, idx;
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;
    vector <Rectangle> R(n);
    vector <int> x(n), y(n);
    for(int i = 0; i < n; i++) {
        cin >> R[i].sx >> R[i].sy >> R[i].ex >> R[i].ey;
        R[i].idx = i;
    }
    sort(all(R), [](Rectangle A, Rectangle B) {
        if(A.sx == B.sx) return A.ex < B.ex;
        return A.sx < B.sx;
    });

    priority_queue <pii, vector <pii>, greater <pii> > pq;
    int idx = 0;
    for(int i = 0; i < n; i++) {
        int l = R[i].sx, r = R[i].ex;
        while(!pq.empty() && (pq.top().fi == idx + 1 || idx + 1 < l)) {
            if(pq.top().fi <= idx) {
                cout << "NIE";
                return 0;
            }
            idx++;
            x[pq.top().se] = idx;
            pq.pop();
        }
        if(idx < l && pq.empty()) {
            if(idx + 1 < l) {
                cout << "NIE";
                return 0;
            }
            idx++;
            x[R[i].idx] = idx;
        }
        else pq.em(r, R[i].idx);
    }
    while(!pq.empty()) {
        if(pq.top().fi <= idx) {
            cout << "NIE";
            return 0;
        }
        idx++;
        x[pq.top().se] = idx;
        pq.pop();
    }

    sort(all(R), [](Rectangle A, Rectangle B) {
        if(A.sy == B.sy) return A.ey < B.ey;
        return A.sy < B.sy;
    });

    idx = 0;
    for(int i = 0; i < n; i++) {
        int l = R[i].sy, r = R[i].ey;
        while(!pq.empty() && (pq.top().fi == idx + 1 || idx + 1 < l)) {
            if(pq.top().fi <= idx) {
                cout << "NIE";
                return 0;
            }
            idx++;
            y[pq.top().se] = idx;
            pq.pop();
        }
        if(idx < l && pq.empty()) {
            if(idx + 1 < l) {
                cout << "NIE";
                return 0;
            }
            idx++;
            y[R[i].idx] = idx;
        }
        else pq.em(r, R[i].idx);
    }
    while(!pq.empty()) {
        if(pq.top().fi <= idx) {
            cout << "NIE";
            return 0;
        }
        idx++;
        y[pq.top().se] = idx;
        pq.pop();
    }

    for(int i = 0; i < n; i++) {
        cout << x[i] << ' ' << y[i] << '\n';
    }
}