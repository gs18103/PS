#include <cstdio>
#include <algorithm>

int num[10101];

int main()
{
    int n, cnt = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
        if(num[i] == 0) cnt = 1;
    }

    std::sort(num, num + n);

    int ans = 0;
    int i;
    for(i = 0; i < n - 1 && num[i] < 0 && num[i+1] < 0; i += 2)
        ans += num[i] * num[i+1];
    for(; i < n && num[i] <= 1; i++)
    {
        if(num[i] < 0 && cnt == 1)
        {
            cnt = 0;
            continue;
        }
        ans += num[i];
    }
    if((n - i) % 2 == 1)
    {
        ans += num[i];
        i++;
    }
    for(; i < n; i += 2)
        ans += num[i] * num[i+1];

    printf("%d", ans);
}
