n = int(input())
g = [[] for i in range(n)]
used = [False] * n

for i in range(n):
    temp = input().split()
    for j in range(n):
        if int(temp[j]) == 1:
            g[i].insert(0, j)
ans = []


def dfs(v):
    used[v] = True
    for i in range(len(g[v])):
        to = g[v][i]
        if not used[to]:
            dfs(to)
    ans.insert(0, v + 1)


for i in range(n):
    if not used[i]:
        dfs(i)

print(*ans)