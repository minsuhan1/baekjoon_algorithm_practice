import sys
input = sys.stdin.readline

N = int(input())
amount = []
for _ in range(N):
    amount.append(int(input()))

dp = [0]*N

if N < 3:
    print(sum(amount))
else:
    dp[0] = amount[0]
    dp[1] = amount[0] + amount[1]
    dp[2] = max(amount[0]+amount[1], amount[1]+amount[2], amount[0]+amount[2])

    for i in range(3, N):
        dp[i] = max(dp[i-1], amount[i-1] + amount[i] + dp[i-3], dp[i-2] + amount[i])

    print(dp[N-1])
