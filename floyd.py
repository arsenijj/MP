from math import inf


def get_data():
    n = int(input())
    g = [[inf if weight == '0' else int(weight) for weight in input().split()] for _ in range(n)]
    return n, g


n, graph = get_data()

for k in range(n):
    for i in range(n):
        for j in range(n):
            d = graph[i][k] + graph[k][j]
            if d < graph[i][j]:
                graph[i][j] = d

graph = [[0 if path_length == inf else path_length for path_length in row] for row in graph]

for i in range(n):
    print(*graph[i])