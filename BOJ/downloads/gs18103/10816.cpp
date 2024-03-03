#include <cstdio>
#include <algorithm>

using namespace std;

typedef pair <int, int> p;

int t[505050];
p arr[505050];

void src(int k, int s, int e)
{
    int m = (s + e) / 2;
    if(k == arr[m].first)
    {
        printf("%d ", arr[m].second);
        return;
    }
    else if(s == e)
    {
        printf("0 ");
        return;
    }
    else if(k > arr[m].first) src(k, m + 1, e);
    else if(k < arr[m].first) src(k, s, m);
}

int main()
{
    int n, m;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &t[i]);

    sort(t, t + n);

    int d = 0;
    arr[0] = p(t[0], 1);
    for(int i = 1; i < n; i++)
    {
        if(t[i] == arr[d].first) arr[d].second++;
        else
        {
            d++;
            arr[d] = p(t[i], 1);
        }
    }

    scanf("%d", &m);
    for(int i = 0; i < m; i++)
    {
        int temp;
        scanf("%d", &temp);
        src(temp, 0, d);
    }
}
