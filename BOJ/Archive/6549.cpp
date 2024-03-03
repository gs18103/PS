#include <cstdio>
#include <stack>

using namespace std;

stack <int> stk;

int h[101010];

int main()
{
    int n;
    scanf("%d", &n);
    while(n != 0)
    {
        long long ans = 0;
        for(int i = 0; i < n; i++)
            scanf("%d", &h[i]);
        for(int i = 0; i < n; i++)
        {
            while(!stk.empty() && h[stk.top()] > h[i])
            {
                int width, height;
                height = h[stk.top()];
                stk.pop();
                width = i;
                if(!stk.empty()) width = i - stk.top() - 1;
                if((long long)width * height > ans) ans = (long long)width * height;
            }
            stk.push(i);
        }
        while(!stk.empty())
        {
            int width, height;
            height = h[stk.top()];
            stk.pop();
            width = n;
            if(!stk.empty()) width = n - stk.top() - 1;
            if((long long)width * height > ans) ans = (long long)width * height;
        }
        printf("%lld\n", ans);
        scanf("%d", &n);
    }
}
