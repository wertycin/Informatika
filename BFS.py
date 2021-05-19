from queue import Queue

if __name__ == "__main__":
    # Считывание графа
    n, m, s = map(int, input().split())
    adj_list = [set() for _ in range(n)]
    for _ in range(m):
        u, v = map(int, input().split())
        adj_list[u].add(v)
        adj_list[v].add(u)

    # BFS
    d = [float('inf')] * n
    d[s] = 0
    q = Queue()
    q.put(s)
    while not q.empty():
        u = q.get()
        for v in adj_list[u]:
            if d[v] == float('inf'):
                d[v] = d[u] + 1
                q.put(v)

    print(*d)
