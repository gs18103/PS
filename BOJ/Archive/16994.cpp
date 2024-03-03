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

template <
    class T, 
    class Container = vector <T>,
    class Compare = less <T>
> class SplayTree {
    struct Node{
        Node *l, *r, *p;
        int c;
        T val;
    } *tree;
    int n;

public :
    void upd(Node *x) {
        x->c = 1;
        if(x->l) x->c += x->l->c;
        if(x->r) x->c += x->r->c;
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
            while(x->l && x->l->c > k) x = x->l;
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

    void init(Container V) {
        n = V.size();
        V.push_back((T)0);
        Node *x = new Node;
        tree = x;
        x->l = x->r = x->p = nullptr;
        x->c = n + 2;
        x->val = (T)0;
        for(int i = 0; i <= n; i++) {
            x->r = new Node;
            x->r->p = x;
            x = x->r;
            x->l = x->r = nullptr;
            x->c = n + 1 - i;
            x->val = V[i];
        }
    }

    void move_front(int s, int e) {
        splay_itv(s, e);
        Node *x = tree->r->l;
        x->p->l = nullptr;
        upd(tree->r);
        upd(tree);
        splay_k(1);
        tree->l->r = x;
        x->p = tree->l;
        upd(tree->l);
        upd(tree);
    }

    void move_back(int s, int e) {
        splay_itv(s, e);
        Node *x = tree->r->l;
        x->p->l = nullptr;
        upd(tree->r);
        upd(tree);
        splay_k(tree->c - 2);
        tree->r->l = x;
        x->p = tree->r;
        upd(tree->r);
        upd(tree);
    }

    T top() {
        return tree->val;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    string s;
    cin >> s;
    SplayTree <char, string> ST;
    ST.init(s);
    int n, q;
    n = s.size();
    cin >> q;
    while(q--) {
        int t, x, y;
        cin >> t;
        if(t == 1) {
            cin >> x >> y;
            ST.move_front(x + 1, y + 1);
        }
        if(t == 2) {
            cin >> x >> y;
            ST.move_back(x + 1, y + 1);
        }
        if(t == 3) {
            cin >> x;
            ST.splay_k(x + 1);
            cout << ST.top() << '\n';
        }
    }
}