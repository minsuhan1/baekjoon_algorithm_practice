import sys
sys.setrecursionlimit(1000000)

from collections import deque

N = int(input())
graph = [list(map(int, input().split())) for _ in range(N)]
visited = [[False] * N for _ in range(N)]
# print(graph)

# 이동방향(시계방향으로 상 우 하 좌)
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

# BFS로 섬마다 id 부여
id = 1
def bfs2(x, y):
    global id
    queue = deque()
    visited[x][y] = True
    graph[x][y] = id
    queue.append([x, y])

    while queue:
        # 큐에서 빼낸 좌표의 상하좌우 방향 좌표들 중
        x, y = queue.popleft()
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            # 범위 이탈한 경우
            if nx < 0 or nx >= N or ny < 0 or ny >= N:
                continue
            # 방문하지 않은 섬인 경우 방문표시하고 id 부여 후 큐에 삽입
            if(visited[nx][ny] == False and graph[nx][ny] == 1):
                visited[nx][ny] = True
                graph[nx][ny] = id
                queue.append([nx, ny])

# 간척사업
dist = [[0] * N for _ in range(N)]
def widen(id, inc):
    global dist
    ret = 0
    for i in range(N):
        for j in range(N):
            # 섬에 id에 해당하는 좌표이고 가장 최근에 간척한 좌표(dist = inc - 1)에서 간척을 진행
            # 섬의 가장자리만 간척하는 효과
            if graph[i][j] == id and dist[i][j] == inc - 1:
                for d in range(4):
                    nx, ny = i + dx[d], j + dy[d]
                    # 범위 이탈한 경우
                    if nx < 0 or nx >= N or ny < 0 or ny >= N:
                        continue
                    # 간척되지 않은 바다인경우
                    if graph[nx][ny] == 0 and dist[nx][ny] == 0:
                        dist[nx][ny] = inc # inc: 현 위치가 몇 번째 간척인지
                        graph[nx][ny] = id  # 간척함
                    # 다른 섬 도착
                    if graph[nx][ny] and graph[nx][ny] != id:
                        # 만난 섬 좌표의 간척횟수와 현위치의 간척횟수를 더하면 곧 두 섬 사이 거리
                        ret = dist[nx][ny] + dist[i][j]
                        return ret
    return ret

# 각 섬끼리 id로 grouping
for i in range(N):
    for j in range(N):
        # 방문하지 않은 섬 좌표에 대해
        if visited[i][j] == False and graph[i][j] == 1:
            bfs2(i, j)
            id += 1


ans = sys.maxsize
inc = 0  # inc번째로 간척한 좌표임을 나타내기 위한 변수
idlist = []
for i in range(1, id):
    idlist.append(i)

# 각 섬의 가장자리를 1회씩 간척하는 것을 반복하다가
# 어느 두 섬이 연결되면 idlist에서 해당 id를 지우고
# 다른 섬들에서 더 짧은 거리의 다리가 완성될 수 있는지 마지막으로 확인 및 update한 후
# while문 탈출
flag = True
while(flag):
    inc += 1
    for id in idlist:
        ret = widen(id, inc)
        # 어느 두 섬이 연결되면
        # 남은 id 섬들에 대해 간척사업해보고 종료
        # 남은 id 섬에서 더 짧은 다리의 길이를 고름
        if ret > 0:
            ans = min(ans, ret)
            flag = False

print(ans)
