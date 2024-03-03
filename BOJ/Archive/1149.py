import sys
input = sys.stdin.readline

n = int(input())

dp = [[0 for _ in range(n+1)], [0 for _ in range(n+1)], [0 for _ in range(n+1)]]
C = [[0 for _ in range(n+1)], [0 for _ in range(n+1)], [0 for _ in range(n+1)]]


for i in range(1, n + 1) :
    C[0][i], C[1][i], C[2][i] = map(int, input().split())

for i in range(1, n + 1) :
    dp[0][i] = min(dp[1][i-1], dp[2][i-1]) + C[0][i]
    dp[1][i] = min(dp[0][i-1], dp[2][i-1]) + C[1][i]
    dp[2][i] = min(dp[0][i-1], dp[1][i-1]) + C[2][i]

sys.stdout.write(str(min([dp[0][n], dp[1][n], dp[2][n]])))