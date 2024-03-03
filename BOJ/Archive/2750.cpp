#include <stdio.h>

int arr[1010];
int d[1010];

void srt(int l, int r)
{
    if(l >= r) return;
    srt(l, (l+r)/2);
    srt((l+r)/2+1, r);
    int t = 0;
    int tl = l, tr = (l+r)/2+1;
    while(tl <= (l+r)/2 && tr <= r)
    {
        if(arr[tl] > arr[tr]) d[t++] = arr[tr++];
        else d[t++] = arr[tl++];
    }
    while(tl <= (l+r)/2)
    {
        d[t++] = arr[tl++];
    }
    while(tr <= r)
    {
        d[t++] = arr[tr++];
    }
    for(int i = 0; i < t; i++)
    {
        arr[i+l] = d[i];
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    srt(0, n-1);
    for(int i = 0; i < n; i++) printf("%d\n", arr[i]);
}
