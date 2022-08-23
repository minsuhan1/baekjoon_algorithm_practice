import sys
input = sys.stdin.readline

N = int(input())
board = [list(map(int, input().split())) for _ in range(N)]

# 플로이드 워셜 알고리즘
# 모든 노드에서 다른 모든 노드까지 가는 최소비용을 계산하는 데 사용
# i에서 j로 k를 거쳐 가는 모든 경로를 탐색하며 최소비용을 선택
# dp[i][j] = min(dp[i][k] +dp[k][j], dp[i][j])

# 이 문제에서는 k를 거쳐 갈 수 있는지만 확인하면 됨

for k in range(N):
    for i in range(N):
        for j in range(N):
            if board[i][j] == 1: continue
            if board[i][k] == 1 and board[k][j]:
                board[i][j] = 1

for i in board:
    for j in i:
        print(j, end=' ')
    print()

