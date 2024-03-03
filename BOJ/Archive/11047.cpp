#include <iostream>

using namespace std;

int main()
{
    int n, k;
    int cost[10];
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> cost[i];

    int cnt = 0;
    for(int i = n - 1; i >= 0; i--)
    {
        cnt += k / cost[i];
        k = k % cost[i];
    }

    cout << cnt;

    return 0;
}
