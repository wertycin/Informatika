if __name__ == '__main__':
    n, m = map(int, input().split())
    a = [[float('inf')]*n for _ in range(n)]
    for _ in range(m):
        u, v, w = map(int, input().split())
        a[u][v] = min(a[u][v], w)
        a[v][u] = min(a[v][u], w)
    for i in range(n): # расстояния от вершины до самой себя считаем нулевым
        a[i][i] = 0

    for k in range(n):
        for u in range(n):
            for v in range(n):
                a[u][v] = min(a[u][v], a[u][k] + a[k][v]) # улучшаем расстояние от вершины u до вершины v, используя (обходя) не более k первых вершин
    for line in a:
        print(*line)

