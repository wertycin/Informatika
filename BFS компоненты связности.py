from queue import Queue

if __name__ == "__main__":
    # Считывание графа
    n, m = map(int, input().split())
    adj_list = [set() for _ in range(n)]
    for _ in range(m):
        u, v = map(int, input().split())
        adj_list[u].add(v)
        adj_list[v].add(u)

    # BFS
    used = [False] * n
    count = 0
    for s in range(n):
        if used[s]:
            continue
        q = Queue()
        q.put(s)
        used[s] = True
        count += 1
        while not q.empty():
            u = q.get()
            for v in adj_list[u]:
                if not used[v]:
                    used[v] = True
                    q.put(v)
    print(count)
