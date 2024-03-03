#include <cstdio>
#include <queue>

using namespace std;

queue <int> q;
queue <int> order;
priority_queue <int> pq;

int main()
{
    int T;
    scanf("%d", &T);
    for(int t = 0; t < T; t++)
    {
        int n, m, cnt = 0, ans;
        scanf("%d %d", &n, &m);
        for(int i = 0; i < n; i++)
        {
            int temp;
            scanf("%d", &temp);
            q.push(temp);
            order.push(i);
            pq.push(temp);
        }
        while(!q.empty())
        {
            if(q.front() == pq.top())
            {
                q.pop();
                pq.pop();
                cnt++;
                if(order.front() == m) ans = cnt;
                order.pop();
            }
            else
            {
                q.push(q.front());
                q.pop();
                order.push(order.front());
                order.pop();
            }
        }
        printf("%d\n", ans);
    }
}
