#include <bits/stdc++.h>
#define eb emplace_back
#define em emplace
#define fi first
#define se second
#define all(v) v.begin(), v.end()

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int INF = 1 << 30;
const ll LINF = 1LL << 62;
const int MAX = 101010;

string dp[10][10][10][10][10][10];

bool cmp(string s1, string s2) {
    if(s1.size() == s2.size()) return s1 < s2;
    return s1.size() < s2.size();
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;
    string s[6];
    for(int i = 0; i < 6; i++) {
        if(i < n) cin >> s[i];
        s[i] = " " + s[i];
    }
    for(int i1 = 0; i1 < s[0].size(); i1++) {
        for(int i2 = 0; i2 < s[1].size(); i2++) {
            for(int i3 = 0; i3 < s[2].size(); i3++) {
                for(int i4 = 0; i4 < s[3].size(); i4++) {
                    for(int i5 = 0; i5 < s[4].size(); i5++) {
                        for(int i6 = 0; i6 < s[5].size(); i6++) {
                            if(i1 + i2 + i3 + i4 + i5 + i6 == 0) continue;
                            for(int j = 0; j < 70; j++) {
                                dp[i1][i2][i3][i4][i5][i6] += "Z";
                            }
                            dp[i1][i2][i3][i4][i5][i6] = min({
                                dp[i1-(s[0][i1]=='A')][i2-(s[1][i2]=='A')][i3-(s[2][i3]=='A')][i4-(s[3][i4]=='A')][i5-(s[4][i5]=='A')][i6-(s[5][i6]=='A')] + "A", 
                                dp[i1-(s[0][i1]=='B')][i2-(s[1][i2]=='B')][i3-(s[2][i3]=='B')][i4-(s[3][i4]=='B')][i5-(s[4][i5]=='B')][i6-(s[5][i6]=='B')] + "B", 
                                dp[i1-(s[0][i1]=='C')][i2-(s[1][i2]=='C')][i3-(s[2][i3]=='C')][i4-(s[3][i4]=='C')][i5-(s[4][i5]=='C')][i6-(s[5][i6]=='C')] + "C", 
                                dp[i1-(s[0][i1]=='D')][i2-(s[1][i2]=='D')][i3-(s[2][i3]=='D')][i4-(s[3][i4]=='D')][i5-(s[4][i5]=='D')][i6-(s[5][i6]=='D')] + "D" 
                            }, cmp);
                        }
                    }
                }
            }
        }
    }
    cout << dp[s[0].size()-1][s[1].size()-1][s[2].size()-1][s[3].size()-1][s[4].size()-1][s[5].size()-1];
}