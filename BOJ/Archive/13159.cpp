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
        Node *l, *r, *p;
        int c;
        int mn = INF, mx = 0, val;
        ll sum = 0;
        bool flip = false;
    } *tree;
    int n;
    vector <Node*> ptr;
    void upd_lazy(Node *x) {
        if(!x->flip) return;
        swap(x->l, x->r);
        if(x->l) x->l->flip = !x->l->flip;
        if(x->r) x->r->flip = !x->r->flip;
        x->flip = false;
    }

    void upd(Node *x) {
        x->c = 1;
        x->sum = x->val;
        x->mx = x->val;
        if(x->val) x->mn = x->val;
        else x->mn = INF;
        if(x->l) {
            x->c += x->l->c;
            x->sum += x->l->sum;
            x->mx = max(x->mx, x->l->mx);
            x->mn = min(x->mn, x->l->mn);
        }
        if(x->r) {
            x->c += x->r->c;
            x->sum += x->r->sum;
            x->mx = max(x->mx, x->r->mx);
            x->mn = min(x->mn, x->r->mn);
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

    void init(int N) {
        n = N;
        ptr.resize(n+1);
        Node *x = new Node;
        tree = x;
        x->l = x->r = x->p = nullptr;
        x->val = 0;
        for(int i = 1; i <= n; i++) {
            x->r = new Node;
            x->r->p = x;
            x = x->r;
            ptr[i] = x;
            x->l = x->r = nullptr;
            x->val = i;
        }
        x->r = new Node;
        x->r->p = x;
        x = x->r;
        x->l = x->r = nullptr;
        x->val = 0;
        for(int i = n; i > 0; i--) {
            upd(ptr[i]);
        }
    }

    void Flip(int s, int e) {
        splay_itv(s, e);
        Node *tmp = tree->r->l;
        tmp->flip = !tmp->flip;
    }

    int top() {
        return tree->val;
    }

    void traverse(Node *x) {
        upd_lazy(x);
        if(x->l) traverse(x->l);
        if(x->val) cout << x->val << ' ';
        if(x->r) traverse(x->r);
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    vector <int> V(n);
    SplayTree ST;
    ST.init(n);

    while(q--) {
        int t, l, r, x;
        cin >> t;
        if(t == 1) {
            cin >> l >> r;
            ST.splay_itv(l, r);
            cout << ST.tree->r->l->mn << ' ' << ST.tree->r->l->mx << ' ' << ST.tree->r->l->sum << '\n';
            ST.Flip(l, r);
        }
        if(t == 2) {
            cin >> l >> r >> x;
            ST.splay_itv(l, r);
            cout << ST.tree->r->l->mn << ' ' << ST.tree->r->l->mx << ' ' << ST.tree->r->l->sum << '\n';
            int sz = r - l + 1;
            x = ((x % sz) + sz) % sz;
            if(x != 0) {
                ST.Flip(l, r);
                ST.Flip(l, l + x - 1);
                ST.Flip(l + x, r);
            }
        }
        if(t == 3) {
            cin >> x;
            ST.splay_k(x);
            cout << ST.top() << '\n';
        }
        if(t == 4) {
            cin >> x;
            ST.splay(ST.ptr[x]);
            cout << ST.tree->l->c << '\n';
        }
    //ST.traverse(ST.tree);
    //cout << '\n';
    }
    ST.traverse(ST.tree);
}