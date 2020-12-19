import sys
sys.setrecursionlimit(100000)


def calCount(cur):
    tmp = 0
    for num in arr[cur]:
        if visited[num]:
            continue
        visited[num] = 1
        tmp += calCount(num)
    count[cur] += tmp
    return count[cur]


N, R, Q = list(map(int, input().split()))

arr = [[] for n in range(N + 1)]

for _ in range(N - 1):
    a, b = map(int, sys.stdin.readline().split())
    arr[a].append(b)
    arr[b].append(a)

visited = [0 for n in range(N + 1)]
count = [1 for n in range(N + 1)]

visited[R] = 1
calCount(R)

for q in range(Q):
    node = int(sys.stdin.readline())
    print(count[node])
