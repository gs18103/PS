#include <cstdio>
#include <queue>

using namespace std;

queue <int> q;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
        q.push(i);
    int cnt = 0;
    printf("<");
    while(!q.empty())
    {
        cnt++;
        if(cnt % m == 0)
        {
            printf("%d", q.front());
            if(q.size() != 1) printf(", ");
        }
        else
        {
            q.push(q.front());
        }
        q.pop();
    }
    printf(">");
}
