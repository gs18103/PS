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

vector <int> mul(vector <int> s, vector <int> t) {
    vector <int> r(s.size() + t.size());
    for(int i = 0; i < s.size(); i++) {
        for(int j = 0; j < t.size(); j++) {
            r[i+j] += s[i] * t[j];
        }
    }
    for(int i = 0; i < r.size(); i++) {
        if(r[i] >= 10) {
            r[i+1] += r[i] / 10;
            r[i] %= 10;
        }
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    string temp;
    vector <int> num;
    int d, b;
    cin >> temp >> b;
    for(int i = temp.size() - 1; i >= 0; i--) {
        if(temp[i] == '.') d = temp.size() - i - 1;
        else num.eb(temp[i] - '0');
    }
    vector <int> t = num;
    for(int i = 1; i < b; i++) {
        t = mul(t, num);
    }
    bool flag = false;
    for(int i = t.size() - 1; i >= 0; i--) {
        if(t[i] > 0) flag = true;
        if(flag) cout << t[i];
        if(i == d * b) {
            if(!flag) flag = true, cout << 0;
            cout << '.';
        }
    }
}