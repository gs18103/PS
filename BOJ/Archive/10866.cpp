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

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int q;
    cin >> q;
    list <int> dq;
    while(q--) {
        string s;
        cin >> s;
        if(s == "push_back") {
            int x;
            cin >> x;
            dq.push_back(x);
        }
        if(s == "push_front") {
            int x;
            cin >> x;
            dq.push_front(x);
        }
        if(s == "pop_back") {
            if(dq.empty()) cout << "-1\n";
            else {
                cout << dq.back() << '\n';
                dq.pop_back();
            }
        }
        if(s == "pop_front") {
            if(dq.empty()) cout << "-1\n";
            else {
                cout << dq.front() << '\n';
                dq.pop_front();
            }
        }
        if(s == "size") cout << dq.size() << '\n';
        if(s == "empty") cout << dq.empty() << '\n';
        if(s == "back") cout << (dq.empty() ? -1 : dq.back()) << '\n';
        if(s == "front") cout << (dq.empty() ? -1 : dq.front()) << '\n';
    }
}