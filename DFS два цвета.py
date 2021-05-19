def dfs(u):
    colours[u] = 1 # при входе в вершину u красим ее в серый цвет
    for v in adj_list[u]:
        if colours[v] == 0: # запускаем dfs для всех белых соседей u
            dfs(v)
        elif colours[v] == 1: # если мы наткнулись на серую вершину (хотя бы 1 раз) - цикл найден
            print('YES')
            exit()
    colours[u] = 2 # при выходе из вершины u красим ее в черный цвет

if __name__ == "__main__":
    # Считывание графа
    n, m = map(int, input().split())
    adj_list = [set() for _ in range(n)]
    for _ in range(m):
        u, v = map(int, input().split())
        adj_list[u].add(v)
    # Сам обход (Проверка на цикл)
    colours = [0] * n
    for u in range(n):
        if colours[u] == 0:
            dfs(u)
    print('NO')