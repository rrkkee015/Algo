import sys

r = 0
ry = 0
rx = 0

for i in range(9):
    li = list(map(int, sys.stdin.readline().split(' ')))
    for j in range(9):
        if li[j] > r:
            r = li[j]
            ry = i
            rx = j

print(r)
print(ry, rx)
