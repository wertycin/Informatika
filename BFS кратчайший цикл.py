from queue import Queue

if __name__ == "__main__":

    def bfs(s):
        q = Queue()
        q.put(s)
        d = [float('inf')] * n
        d[s] = 0
        p = [None] * n
        while not q.empty():
            u = q.get()
            for v in adj_list[u]:
                if d[v] == float('inf'):
                    d[v] = d[u] + 1
                    p[v] = u
                    q.put(v)
                elif v == s:
                    cycle = []
                    cur = u
                    while cur is not None:
                        cycle.append(cur)
                        cur = p[cur]
                    return cycle[::-1]
        return []


    # Считывание графа
    n, m = map(int, input().split())
    adj_list = [set() for _ in range(n)]
    for _ in range(m):
        u, v = map(int, input().split())
        adj_list[u].add(v)

    # Shortest cycle
    shortest_cycle = []
    cycle_len = float('inf')
    for s in range(n):
        cycle = bfs(s)
        if cycle and len(cycle) < cycle_len:
            shortest_cycle = cycle
            cycle_len = len(cycle)

    if cycle_len == float('inf'):
        print('NO')
    else:
        print(*shortest_cycle)
