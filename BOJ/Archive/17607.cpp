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
const ll LINF = 1e18;

class SplayTree {
public :
    struct Node{
        Node *l = nullptr, *r = nullptr, *p = nullptr;
        int c;
        int lmx = 0, rmx = 0, mx = 0, val = 0, idx;
        bool flip = false;
    } *tree;
    int n;
    void upd_lazy(Node *x) {
        if(!x->flip) return;
        swap(x->l, x->r);
        swap(x->lmx, x->rmx);
        if(x->l) x->l->flip = !x->l->flip;
        if(x->r) x->r->flip = !x->r->flip;
        x->flip = false;
    }

    void upd(Node *x) {
        x->c = 1;
        x->mx = x->lmx = x->rmx = 0;
        if(x->l && x->r) {
            upd_lazy(x->l);
            upd_lazy(x->r);
            x->c += x->l->c + x->r->c;
            x->mx = max(x->l->mx, x->r->mx);
            if(x->val) x->mx = max(x->mx, x->l->rmx + 1 + x->r->lmx);
            if(x->val && x->l->c == x->l->lmx) x->lmx = x->l->lmx + 1 + x->r->lmx;
            else x->lmx = x->l->lmx;
            if(x->val && x->r->c == x->r->rmx) x->rmx = x->r->rmx + 1 + x->l->rmx;
            else x->rmx = x->r->rmx;
        }
        else if(x->l) {
            upd_lazy(x->l);
            x->c += x->l->c;
            x->mx = x->l->mx;
            if(x->val) x->mx = max(x->mx, x->l->rmx + 1);
            if(x->val && x->l->c == x->l->rmx) x->lmx = x->l->rmx + 1;
            else x->lmx = x->l->lmx;
            if(x->val) x->rmx = x->l->rmx + 1;
        }
        else if(x->r) {
            upd_lazy(x->r);
            x->c += x->r->c;
            x->mx = x->r->mx;
            if(x->val) x->mx = max(x->mx, x->r->lmx + 1);
            if(x->val && x->r->c == x->r->rmx) x->rmx = x->r->rmx + 1;
            else x->rmx = x->r->rmx;
            if(x->val) x->lmx = x->r->lmx + 1;
        }
        else if(x->val) x->mx = x->lmx = x->rmx = 1;
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
            if(pp) upd_lazy(pp);
            upd_lazy(p);
            upd_lazy(x);
            if(pp) {
                if((pp->l == p) == (p->l == x)) rotate(p);
                else rotate(x);
            }
            rotate(x);
        }
    }

    void splay_k(int k) {
        Node *x = tree;
        upd_lazy(x);
        while(1) {
            while(x->l && x->l->c > k) {
                x = x->l;
                upd_lazy(x);
            }
            if(x->l) k -= x->l->c;
            if(!k) break;
            k--;
            x = x->r;
            upd_lazy(x);
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

    void init(int N, vector <int> &A) {
        n = N;
        A.eb(0);
        vector <int> L(n+1);
        for(int i = n - 1; i >= 0; i--) {
            if(A[i]) L[i] = L[i+1] + 1;
        }
        tree = new Node;
        Node *x = tree;
        x->c = n + 2;
        x->idx = 0;
        
        for(int i = 0; i <= n; i++) {
            x->r = new Node;
            x->r->p = x;
            x = x->r;
            x->c = n - i + 1;
            x->val = A[i];
            x->lmx = L[i];
            x->idx = i + 1;
        }
        while(x) {
            upd(x);
            x = x->p;
        }
    }

    void Flip(int s, int e) {
        splay_itv(s, e);
        Node *tmp = tree->r->l;
        tmp->flip = !tmp->flip;
        upd_lazy(tmp);
        upd(tree->r);
        upd(tree);
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n, q;
    cin >> n;
    vector <int> V(n);
    for(int i = 0; i < n; i++) {
        cin >> V[i];
    }
    SplayTree ST;
    ST.init(n, V);
    cin >> q;
    while(q--) {
        int t, l, r;
        cin >> t >> l >> r;
        if(t == 1) ST.Flip(l, r);
        if(t == 2) {
            ST.splay_itv(l, r);
            ST.upd_lazy(ST.tree);
            ST.upd_lazy(ST.tree->r);
            ST.upd_lazy(ST.tree->r->l);
            cout << ST.tree->r->l->mx << '\n';
        }
    }
}