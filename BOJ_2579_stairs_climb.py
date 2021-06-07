import sys
input = sys.stdin.readline

N = int(input())
scores = []
for _ in range(N):
    scores.append(int(input()))

# 반드시 마지막 계단에 도착
# 마지막 계단 전 계단을 밟거나 밟지 않거나 둘 중 하나
# 연속해서 한칸씩 오를 수 없으므로
# 마지막 계단 전 계단을 밟았다면 전전 계단 대신 전전전계단을 밟아야 함
# 점화식 : dp[n] = max(dp[n-2] + scores[n], dp[n-3] + scores[n-1] + scores[n])

# 1~3번째 계단까지는 직접 경우에 따라 지정해줘야함(인덱스때문에)
dp = [0]*N

dp[0] = scores[0]
if N > 1:
    dp[1] = max(scores[0]+scores[1], scores[1])
if N > 2:
    dp[2] = max(scores[0]+scores[2], scores[1]+scores[2])

    for i in range(3, N):
        dp[i] = max(dp[i-2] + scores[i], dp[i-3] + scores[i-1] + scores[i])
    
print(dp[N-1])
