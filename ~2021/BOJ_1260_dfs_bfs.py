import sys
input = sys.stdin.readline

# DFS
def dfs(v):
    # 현재 노드 방문처리
    visit[v] = True
    print(v, end=' ')
    # 현재 노드와 연결된 다른 노드 재귀적 방문
    for i in adj[v]:
        if not visit[i]:
            dfs(i)

# BFS
def bfs(v):
    # 시작 정점을 큐에 넣기
    q = [v]
    # 큐에서 빼내고 인접 노드들을 큐에 삽입
    # 큐가 빌 때까지 반복
    while q:    
        cur_v = q.pop(0)  
        if visit[cur_v]: continue    
        # 현재 노드 방문처리
        visit[cur_v] = True
        print(cur_v, end=' ')
        # 인접 노드들을 큐에 삽입
        for i in adj[cur_v]:
            if not visit[i]:
                q.append(i)
    

if __name__ == "__main__":   
    # 정점, 간선 개수, 시작정점
    N, M, S = map(int, input().split())
    adj = [[]*i for i in range(N+1)]
    visit = [False]*(N+1)

    # 그래프 입력받기(인접 노드 추가)
    for _ in range(M):
        v1, v2 = map(int, input().split())
        adj[v1].append(v2)
        adj[v2].append(v1)

    # 인접노드 정렬
    for i in range(N+1):
        adj[i] = sorted(adj[i])
    
    dfs(S)
    visit = [False]*(N+1)
    print()
    bfs(S)

