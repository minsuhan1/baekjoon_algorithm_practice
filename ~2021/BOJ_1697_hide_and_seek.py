from collections import deque
import sys
input = sys.stdin.readline

visit = [False]*100001
def bfs():
    q = deque()
    q.append([N, 0])
    while q:
        v = q.popleft()
        cur = v[0]
        sec = v[1]
        visit[cur] = True

        if cur == K:
            return sec
        
        sec += 1

        if cur+1 <= 100000:
            if not visit[cur+1]:
                q.append([cur+1, sec])
        if 0 <= cur-1:
            if not visit[cur-1]:
                q.append([cur-1, sec])
        if 0 <= 2*cur <= 100000:
            if not visit[2*cur]:
                q.append([2*cur, sec])

if __name__ == '__main__':
    N, K = map(int, input().split())
    print(bfs())
