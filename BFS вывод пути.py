from queue import Queue

if __name__ == "__main__":
    # Считывание графа
    n, m, s, t = map(int, input().split())
    adj_list = [set() for _ in range(n)]
    for _ in range(m):
        u, v = map(int, input().split())
        adj_list[u].add(v)
        adj_list[v].add(u)

    # BFS
    d = [float('inf')] * n
    d[s] = 0
    p = [None] * n
    q = Queue()
    q.put(s)
    while not q.empty():
        u = q.get() # достаем вершину из очереди
        for v in adj_list[u]: # перебираем всех непосещенных соседей (расстояние до которых бесконечность)
            if d[v] == float('inf'):
                d[v] = d[u] + 1 # обновляем расстояние для соседа
                p[v] = u # добавляем u как предка вершины v
                q.put(v) # добавляем v в очередь
    path = []
    cur = t
    while cur is not None:
        path.append(cur)
        cur = p[cur]

    print(*path[::-1])
