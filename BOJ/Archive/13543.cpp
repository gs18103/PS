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
typedef unsigned int uint;

const int MAX = 101010;
const int INF = 1e9;
const ll LINF = 1e18;

class SplayTree {
public :
    struct Node{
        Node *l = nullptr, *r = nullptr, *p = nullptr;
        uint c, val;
        uint s[11];
    } *tree;
    uint C[11][11];
    vector <uint> po[11];
    uint n;

    void upd(Node *x) {
        x->c = 1;
        if(x->l) {
            x->c += x->l->c;
            for(int i = 0; i <= 10; i++) {
                x->s[i] = x->l->s[i] + x->val * po[i][x->c];
            }
        }
        else {
            for(int i = 0; i <= 10; i++) {
                x->s[i] = x->val;
            }
        }
        if(x->r) {
            for(int i = 0; i <= 10; i++) {
                for(int j = 0; j <= i; j++) {
                    x->s[i] += x->r->s[j] * C[i][j] * po[i-j][x->c];
                }
            }
            x->c += x->r->c;
        }
    }

    void rotate(Node *x) {
        Node *p = x->p;
        Node *m;
        if(x == p->l) {
            p->l = m = x->r;
            x->r = p;
        }
        else {
            p->r = m = x->l;
            x->l = p;
        }
        if(m) m->p = p;
        x->p = p->p;
        p->p = x;
        if(x->p) {
            if(p == x->p->l) x->p->l = x;
            else x->p->r = x;
        }
        else tree = x;
        upd(p);
        upd(x);
    }

    void splay(Node *x) {
        while(x->p) {
            Node *p = x->p, *pp = p->p;
            if(pp) {
                if((pp->l == p) == (p->l == x)) rotate(p);
                else rotate(x);
            }
            rotate(x);
        }
    }

    void splay_k(int k) {
        Node *x = tree;
        while(1) {
            while(x->l && x->l->c > k) {
                x = x->l;
            }
            if(x->l) k -= x->l->c;
            if(!k) break;
            k--;
            x = x->r;
        }
        splay(x);
    }

    void splay_itv(int s, int e) {
        splay_k(s - 1);
        Node *tmp = tree;
        tree = tmp->r;
        tree->p = nullptr;
        splay_k(e - s + 1);
        tmp->r = tree;
        tree->p = tmp;
        tree = tmp;
    }

    void modify(int k, uint val) {
        splay_k(k);
        tree->val = val;
        upd(tree);
    }

    void insert(int k, uint val) {
        splay_k(k);
        Node *tmp = tree->l;
        Node *x = new Node;
        x->l = tmp;
        tmp->p = x;
        x->p = tree;
        tree->l = x;
        x->val = val;
        upd(x);
        upd(tree);
    }

    void erase(int k) {
        splay_k(k - 1);
        Node *x = tree->r;
        while(x->l) {
            x = x->l;
        }
        Node *tmp = tree;
        tree = tmp->r;
        tree->p = nullptr;
        splay(x);
        tmp->r = tree;
        tree->p = tmp;
        tree = tmp;
        x = tree->r;
        tree->r = x->r;
        tree->r->p = tree;
        delete x;
        upd(tree);
    }

    void init(uint N, uint q, vector <uint> &A) {
        n = N;
        A.eb(0);
        for(uint i = 0; i <= 10; i++) {
            po[i].resize(n + q + 1);
            for(uint j = 1; j <= n + q; j++) {
                if(i) po[i][j] = po[i-1][j] * j;
                else po[i][j] = 1;
            }
        }
        C[0][0] = 1;
        for(int i = 1; i <= 10; i++) {
            C[i][0] = 1;
            C[i][i] = 1;
            for(int j = 1; j < i; j++) {
                C[i][j] = C[i-1][j] + C[i-1][j-1];
            }
        }
        tree = new Node;
        Node *x = tree;
        tree->val = 0;
        tree->c = n + 2;
        for(int i = 0; i <= n; i++) {
            x->r = new Node;
            x->r->p = x;
            x = x->r;
            x->c = n - i + 1;
            x->val = A[i];
        }
        while(x->p) {
            upd(x);
            x = x->p;
        }
    }
} ST;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, q;
    cin >> n;
    vector <uint> V(n);
    for(int i = 0; i < n; i++) {
        cin >> V[i];
    }
    SplayTree ST;
    cin >> q;
    ST.init(n, q, V);
    while(q--) {
        int t;
        cin >> t;
        if(t == 1) {
            int p; uint v;
            cin >> p >> v;
            ST.insert(p + 1, v);
        } 
        if(t == 2) {
            int p;
            cin >> p;
            ST.erase(p + 1);
        }
        if(t == 3) {
            int p; uint v;
            cin >> p >> v;
            ST.modify(p + 1, v);
        }
        if(t == 4) {
            int l, r, k;
            cin >> l >> r >> k;
            ST.splay_itv(l + 1, r + 1);
            cout << ST.tree->r->l->s[k] << '\n';
        }
    }
}