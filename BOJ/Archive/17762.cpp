#include <bits/stdc++.h>  
  
using namespace std;  
  
typedef pair <int, int> p;  
  
int in[201010], out[201010];  
p arr[101010];  
bool chk[101010];  
vector <int> g[101010];  
priority_queue <pair <int, int> > dpu[101010], dpl[101010];  
  
int update(vector <int> &tree, int node, int s, int e, int k, int val) {  
    if(s == e) return tree[node] = val;  
    int m = (s + e) / 2;  
    if(k <= m) return tree[node] = max(tree[node*2+1], update(tree, node*2, s, m, k, val));  
    else return tree[node] = max(tree[node*2], update(tree, node*2+1, m+1, e, k, val));  
}  
  
int cal(vector <int> &tree, int node, int s, int e, int l, int r) {  
    if(s > r || e < l) return 0;  
    if(s >= l && e <= r) return tree[node];  
    int m = (s + e) / 2;  
    return max(cal(tree, node*2, s, m, l, r), cal(tree, node*2+1, m+1, e, l, r));  
}  
  
int d = 0;  
void f(int k) {  
    d++;  
    chk[k] = true;  
    in[k] = d;  
    for(int i = 0; i < g[k].size(); i++) {  
        if(!chk[g[k][i]]) f(g[k][i]);  
    }  
    d++;  
    out[k] = d;  
    return;  
}  
  
int main() {  
    ios::sync_with_stdio(false); cin.tie(NULL);  
  
    int n;  
    cin >> n;  
    for(int i = 1; i <= n; i++) {  
        int t;  
        cin >> t;  
        arr[i] = (make_pair(t, i));  
    }  
    sort(arr+1, arr+n+1);  
  
    for(int i = 1; i < n; i++) {  
        int u, v;  
        cin >> u >> v;  
        g[u].push_back(v);  
        g[v].push_back(u);  
    }  
    f(1);  
  
    vector <int> treel, treeu;  
    vector <p> ql, qu;  
    treel.resize(8*n);  
    treeu.resize(8*n);  
  
    int prex = -1;  
    for(int i = 1; i <= n; i++) {  
        int x = arr[i].second;  
        if(arr[i].first != prex) {  
            for(auto j : ql) {  
                update(treel, 1, 1, 2 * n, j.first, j.second);  
            }  
            ql.clear();  
        }  
        prex = arr[i].first;  
        for(int j : g[x]) {  
            if(in[j] < in[x]) continue;  
            dpl[x].push(make_pair(cal(treel, 1, 1, 2 * n, in[j], out[j]) + 1, j));  
        }  
        if(dpl[x].empty()) {  
            dpl[x].push(make_pair(1, 0));  
        }  
        ql.push_back(make_pair(in[x], dpl[x].top().first));  
    }  
    prex = -1;  
    for(int i = n; i >= 1; i--) {  
        int x = arr[i].second;  
        if(arr[i].first != prex) {  
            for(auto j : qu) {  
                update(treeu, 1, 1, 2 * n, j.first, j.second);  
            }  
            qu.clear();  
        }  
        prex = arr[i].first;  
        for(int j : g[x]) {  
            if(in[j] < in[x]) continue;  
            dpu[x].push(make_pair(cal(treeu, 1, 1, 2 * n, in[j], out[j]) + 1, j));  
        }  
        if(dpu[x].empty()) {  
            dpu[x].push(make_pair(1, 0));  
        }  
        qu.push_back(make_pair(in[x], dpu[x].top().first));  
    }  
    qu.clear();  
    ql.clear();  
  
    int ans = 1;  
    for(int i = 1; i <= 8 * n; i++) {  
        treeu[i] = 0, treel[i] = 0;  
    }  
    prex = -1;  
    for(int i = 1; i <= n; i++) {  
        int x = arr[i].second;  
        if(arr[i].first != prex) {  
            for(auto j : ql) {  
                update(treel, 1, 1, 2 * n, j.first, j.second);  
            }  
            ql.clear();  
        }  
        prex = arr[i].first;  
        ans = max(ans, cal(treel, 1, 1, 2 * n, out[x] + 1, 2 * n) + dpu[x].top().first);  
        ql.push_back(make_pair(in[x], dpl[x].top().first));  
    }  
    prex = -1;  
    for(int i = n; i >= 1; i--) {  
        int x = arr[i].second;  
        if(arr[i].first != prex) {  
            for(auto j : qu) {  
                update(treeu, 1, 1, 2 * n, j.first, j.second);  
            }  
            qu.clear();  
        }  
        prex = arr[i].first;  
        ans = max(ans, cal(treeu, 1, 1, 2 * n, out[x] + 1, 2 * n) + dpl[x].top().first);  
        qu.push_back(make_pair(in[x], dpu[x].top().first));  
    }  
  
    for(int i = 1; i <= n; i++) {  
        if(dpl[i].top().second != dpu[i].top().second) {  
            ans = max(ans, dpl[i].top().first + dpu[i].top().first - 1);  
        }  
        else if(dpl[i].size() == 1) {  
            ans = max(ans, dpl[i].top().first);  
            ans = max(ans, dpu[i].top().first);  
        }  
        else {  
            p templ = dpl[i].top(), tempu = dpu[i].top();  
            dpl[i].pop();  
            dpu[i].pop();  
            ans = max(ans, dpl[i].top().first + tempu.first - 1);  
            ans = max(ans, templ.first + dpu[i].top().first - 1);  
        }  
    }  
  
    cout << ans;  
}  