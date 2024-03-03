#include <cstdio>
#include <algorithm>

#define INF 2000000000

using namespace std;

int tree[400001];
int arr[100001];

int init(int node, int s, int e)
{
    int M = (s + e) / 2;
    if(s == e) return tree[node] = arr[s];

    return tree[node] = min(init(node*2, s, M), init(node*2+1, M+1, e));
}

int change(int node, int s, int e, int val, int k)
{
    int M = (s + e) / 2;
    if(s == e) return tree[node] = val;

    if(k <= M) return tree[node] = tree[node*2+1] + change(node*2, s, M, val, k);
    else return tree[node] = tree[node*2] + change(node*2+1, M+1, e, val, k);
}

int sum(int node, int s, int e, int ts, int te)
{
    int M = (s + e) / 2;
    if(s > te || e < ts) return INF;

    else if(s >= ts && e <= te) return tree[node];
    else return min(sum(node*2, s, M, ts, te), sum(node*2+1, M+1, e, ts, te));
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%d", &arr[i]);

    init(1, 1, n);
    for(int i = 1; i <= m; i++)
    {
        int s, e;
        scanf("%d %d", &s, &e);
        printf("%d\n", sum(1, 1, n, s, e));
    }
}
