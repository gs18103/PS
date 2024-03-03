#include <cstdio>

int arr[101];
int next[101];
int multi[101];
int siz;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < k; i++)
        scanf("%d", &arr[i]);

    for(int i = 0; i < k; i++)
    {
        int j;
        for(j = i + 1; j < k; j++)
        {
            if(arr[i] == arr[j])
            {
                next[i] = j - i;
                break;
            }
        }
        if(j == k) next[i] = 101010;
    }

    int ans = 0;
    for(int i = 0; i < k; i++)
    {
        bool flag = false;
        for(int j = 0; j < n; j++)
            if(multi[j] == arr[i])
            {
                flag = true;
            }
        if(flag) continue;

        if(siz < n)
        {
            multi[siz++] = arr[i];
        }
        else
        {
            int maxi = -1;
            int d = 0;
            for(int j = 0; j < n; j++)
            {
                int next = 0;
                for(int l = i + 1; l < k && multi[j] != arr[l]; l++)
                {
                    next++;
                }
                if(next > maxi)
                {
                    maxi = next;
                    d = j;
                }
            }
            ans++;
            multi[d] = arr[i];
        }
    }
    printf("%d", ans);
}
