def dfs(u):
    used[u] = True # отмечаем вершину u как посещенную
    component.append(u)
    for v in adj_list[u]: # перебираем все ребра u
        if not used[v]: # если сосед u не посещен - запускам dfs из него
            dfs(v) # когда все ребра u обработаны - выходим из u

if __name__ == "__main__":
    # Считывание графа
    n, m = map(int, input().split())
    adj_list = [set() for _ in range(n)]
    for _ in range(m):
        u, v = map(int, input().split())
        adj_list[u].add(v)
        adj_list[v].add(u)

    # Сам обход (нахождение компонент связности)
    used = [False] * n
    for u in range(n):
        if not used[u]:
            component = []
            dfs(u)
            print(*component)