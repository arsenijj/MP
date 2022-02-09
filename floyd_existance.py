from math import inf


def get_data():
    n = int(input())
    g = [[inf if weight == '0' else int(weight) for weight in input().split()] for _ in range(n)]
    g = [[0 if j == i else g[i][j] for j in range(n)] for i in range(n)]
    return n, g


n, graph = get_data()

for k in range(n):
    for i in range(n):
        for j in range(n):
            d = graph[i][k] + graph[k][j]
            if graph[i][k] < inf and graph[k][j] < inf:
                if d < graph[i][j]:
                    graph[i][j] = d
                if graph[i][j] < -inf:
                    graph[i][j] = -inf


# graph = [[0 if path_length == inf else 1 for path_length in row] for row in graph]
result = [[0 for _ in range(n)] for _ in range(n)]

for i in range(n):
    for j in range(n):
        if graph[i][j] == inf:
            result[i][j] = 0
        else:
            result[i][j] = 1
        for k in range(n):
            if graph[k][k] < 0 and graph[i][k] < inf and graph[k][j] < inf:
                result[i][k] = 2
                result[k][j] = 2
                result[i][j] = 2

for i in range(n):
    print(*result[i])

