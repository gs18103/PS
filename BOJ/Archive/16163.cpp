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
const int INF = 1e9;
const ll LINF = 9e18;

string manipulate(string s) {
    string changed="#";
    for(int i = 0; i < s.size(); i++){
        changed += s[i];
        changed += "#";
    }
    return changed;
}

vector<int> Manacher(string s) {
    s = manipulate(s);
    int r = 0, p = 0, n = s.size();
    vector<int> A(n);
    for(int i = 0; i < n; i++) {
        if(i <= r) A[i] = min(A[2*p-i], r - i);
        else A[i] = 0;
        
        while(i - A[i] - 1 >= 0 && i + A[i] + 1 < n && s[i+A[i]+1] == s[i-A[i]-1]) A[i]++;
        
        if(r < A[i] + i) {
            r = A[i] + i;
            p = i;
        }
    }
    return A;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    vector <int> A = Manacher(s);
    ll ans = 0;
    for(int i = 0; i < A.size(); i++) {
        ans += (A[i] + 1) / 2;
    }
    cout << ans << endl;
}