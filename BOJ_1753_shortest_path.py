import heapq
import sys
input = sys.stdin.readline
INF = int(1e9)

V, E = map(int, input().split())
S = int(input())
# 인접 리스트 정보
graph = [[] for _ in range(V+1)]
# 정점 V까지의 최단거리
dist = [INF] * (V+1)

# 간선 정보 입력
for i in range(E):
    src, dst, weight = map(int, input().split())
    # src 정점에서 dst 정점으로 가는 비용이 weight
    graph[src].append((dst, weight))

def dijkstra(start):
    dist[start] = 0
    # 우선순위 큐(최소힙)
    q = []
    # 시작 정점까지 가는 데 필요한 비용이 0
    heapq.heappush(q, (0, start))
    while q:    # 큐가 비어있지 않다면
        # 현재 방문하지 않은 정점 중 최단거리가 가장 짧은 정점을 처리
        d, now = heapq.heappop(q)
        # 이미 방문한 정점이면 무시
        if dist[now] < d:
            continue
        # 현재 정점과 인접한 정점들을 확인
        for adj in graph[now]:
            # 현재 정점의 최단거리 + 현재정점~인접정점 weight
            cost = d + adj[1]
            # 현재 정점을 거쳐서 인접정점으로 가는 거리가 더 짧은 경우
            if cost < dist[adj[0]]:
                dist[adj[0]] = cost
                heapq.heappush(q, (cost, adj[0]))

# dijkstra 알고리즘 수행
dijkstra(S)

# 시작정점으로부터 모든 정점까지의 최단경로 출력
for i in range(1, V+1):
    if dist[i] == INF:
        print("INF")
    else:
        print(dist[i])
