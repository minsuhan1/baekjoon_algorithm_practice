import sys
input = sys.stdin.readline

N = int(input())
cost = [[]]
for _ in range(N):
    cost.append(list(map(int, input().split())))

dp = [[0, 0, 0] for _ in range(N+1)]

dp[1][0] = cost[1][0]
dp[1][1] = cost[1][1]
dp[1][2] = cost[1][2]

# 현재 집을 RGB 각각의 색으로 칠할 때 지금까지의 비용을 dp에 저장
# 단, 이전 집과 같은 색을 칠할 수 없다.
for i in range(2, N+1):
    dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + cost[i][0]
    dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + cost[i][1]
    dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + cost[i][2]

print(min(dp[N]))
