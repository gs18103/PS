#include <cstdio>
#include <algorithm>

using namespace std;

int arr[505][505];
int dp[505][505];
int chk[505][505];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int n, m;

int f(int x, int y)
{
    if(x == n - 1 && y == m - 1) return dp[x][y] = 1;
    if(chk[x][y]) return dp[x][y];
    chk[x][y] = 1;
    for(int i = 0; i < 4; i++)
    {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if(tx < 0 || tx >= n || ty < 0 || ty >= m)
            continue;

        if(arr[tx][ty] < arr[x][y]) dp[x][y] += f(tx, ty);
    }
    return dp[x][y];
}

int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("%d", f(0, 0));

}
