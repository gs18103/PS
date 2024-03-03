#include <bits/stdc++.h>  
#define fi first  
#define se second  
  
using namespace std;  
typedef pair <int, int> pii;  
  
pii v[5050505];  
  
int main() {  
    ios::sync_with_stdio(false); cin.tie(0);  
    int n, d;  
    cin >> n >> d;  
    int l = 1, r = 1;  
    for(int i = 1; i <= n; i++) {  
        int u;  
        cin >> u;  
        while(l < r && v[r-1].fi > u) r--;  
        while(l < r && i - d + 1 > v[l].se) l++;  
        v[r] = {u, i};  
        r++;  
        cout << v[l].fi << ' ';  
    }  
}  