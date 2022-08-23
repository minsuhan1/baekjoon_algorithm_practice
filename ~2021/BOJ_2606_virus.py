import sys
input = sys.stdin.readline
   
V = int(input())
E = int(input())

graph = [[] for _ in range(V+1)]
for _ in range(E):
    v1, v2 = map(int, input().split())
    graph[v1].append(v2)
    graph[v2].append(v1)
visit = [False]*(V+1)

# BFS
def bfs(s):
    ans = -1
    q = [s]
    while q:
        v = q.pop(0)
        if visit[v]: continue
        visit[v] = True
        ans += 1
        for v2 in graph[v]:
            if visit[v2] == False:
                q.append(v2)
    return ans

    

if __name__ == "__main__":
    print(bfs(1))

