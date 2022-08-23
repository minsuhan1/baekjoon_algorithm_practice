import sys
input = sys.stdin.readline
   
N = int(input())
T1, T2 = map(int, input().split())
M = int(input())

graph = [[] for _ in range(N+1)]
for _ in range(M):
    v1, v2 = map(int, input().split())
    graph[v1].append(v2)
    graph[v2].append(v1)
visit = [False]*(N+1)

# BFS
def bfs(t1, t2):
    q = [(t1, 0)]
    while q:
        v, chon = q.pop(0)
        if v == t2:
            return chon
        visit[v] = True
        
        chon += 1
        for v2 in graph[v]:
            if not visit[v2]:
                q.append((v2, chon))
        
    return -1
    

if __name__ == "__main__":
    print(bfs(T1, T2))
