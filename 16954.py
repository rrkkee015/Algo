import sys
from collections import deque


def move_map():
    for i in range(1, 9):
        for j in range(8, 0, -1):
            _map[j][i] = _map[j - 1][i]
    for i in range(1, 9):
        _map[1][i] = 0


_map = []
_map.append([1 for i in range(10)])
for _ in range(8):
    bod = sys.stdin.readline()
    tmp = []
    tmp.append(1)
    for __ in range(8):
        if bod[__] == '.':
            tmp.append(0)
        else:
            tmp.append(1)
    tmp.append(1)
    _map.append(tmp)
_map.append([1 for i in range(10)])

dq = deque()

visited = [[[0 for i in range(10)] for j in range(10)] for k in range(10000)]
dy = [-1, -1, -1, 0, 1, 1, 1, 0, 0]
dx = [-1, 0, 1, 1, 1, 0, -1, -1, 0]

dq.append((8, 1, 0))
now = 0
result = 0
visited[0][8][1] = 1

while dq:
    y, x, t = dq.popleft()
    if y == 1 and x == 8:
        result = 1
        print(t)
        break
    if now != t:
        now += 1
        move_map()
    if _map[y][x] == 1:
        continue
    for i in range(len(dy)):
        ny = y + dy[i]
        nx = x + dx[i]
        nt = t + 1
        if _map[ny][nx] == 0 and visited[nt][ny][nx] == 0:
            visited[nt][ny][nx] = 1
            dq.append((ny, nx, nt))

print(result)
