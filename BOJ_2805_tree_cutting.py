import sys
input = sys.stdin.readline

# 나무의 수, 가져가려는 나무 길이
N, M = map(int, input().split())
# 나무의 높이
height = list(map(int, input().split()))

ans = 0
# 이진탐색으로 최적의 절단기 높이 찾기
start = 0
end = max(height)   # 최대 나무 길이를 넘지 않음
while(start <= end):
    # 중간값으로 절단기 높이를 설정하고 M 계산
    mid = (start + end) // 2
    tmp = 0
    tmp = sum([(h - mid) for h in height if h > mid])
    # 최소한 M만큼 가져갈 수 있다면 높이를 높여본다.
    # 그렇지 않다면 높이는 mid보다는 낮아야 한다는 것이므로 end = mid-1로 설정 
    if tmp >= M:
        ans = mid   # 현재 최적의 높이
        start = mid + 1
    else:
        end = mid - 1

print(ans)
