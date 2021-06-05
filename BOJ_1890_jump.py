import sys
input = sys.stdin.readline

N = int(input())
board = [list(map(int, input().split())) for _ in range(N)]
dp = [[0]*N for _ in range(N)]
dp[0][0] = 1

for i in range(N):
    for j in range(N):
        # (i, j)를 거쳐가는 경로가 없거나
        # 도착지점(N-1, N-1)인 경우
        if (dp[i][j] == 0) or (i == N-1 and j == N-1):
            continue

        dist = board[i][j]
        # 오른쪽, 아래쪽으로 갈 수 있는 좌표에 경로 개수 update
        if (i + dist < N):
            dp[i+dist][j] += dp[i][j]

        if (j + dist < N):
            dp[i][j+dist] += dp[i][j]

print(dp[N-1][N-1])
