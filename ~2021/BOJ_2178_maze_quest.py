import sys
input = sys.stdin.readline

dx = [-1, 1, 0, 0]
dy = [0, 0, 1, -1]
   
N, M = map(int, input().split())
grid = [list(input().rstrip()) for _ in range(N)]
for i in range(N):
    for j in range(M):
        grid[i][j] = int(grid[i][j])
visit = [[False]*M for _ in range(N)]

# BFS
def bfs(x, y):
    q = [(x, y, 1)]
    # 큐에서 빼내고 인접 노드들을 큐에 삽입
    # 큐가 빌 때까지 반복
    while q:    
        qx, qy, move = q.pop(0)
        if qx == M-1 and qy == N-1:
            return move
        if visit[qy][qx]: continue
        # 방문처리
        visit[qy][qx] = True
        # 인접 좌표들을 큐에 삽입, move 증가
        move += 1
        for i in range(4):
            nx, ny = qx + dx[i], qy + dy[i]
            if not (nx < 0 or nx >= M or ny < 0 or ny >= N):
                if grid[ny][nx] == 1:
                    q.append((nx, ny, move))
    

if __name__ == "__main__":
    print(bfs(0, 0))

