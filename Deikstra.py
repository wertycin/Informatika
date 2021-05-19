# Дейстра - поиск наименьшего расстояния от заданной вершины до всех остальных
n, m, s = map(int, input().split())
adj_list=[set() for _ in range(n)]
for _ in range(m):
    u, v, w = map(int, input().split())
    adj_list[u].add((v, w))
    adj_list[v].add((u, w))

d = [float("inf")]*n
d[s] = 0
used = [False]*n
for _ in range(n):
    u = -1
    for i in range(n): # ищем непосещенную вершину с наименьшим до нее расстоянием
        if not used[i] and (u == -1 or d[u] > d[i]):
            u = i
    if d[u] == float("inf"): # если таких вершин не осталось, то заканчиваем алгоритм
        break
    for v, w in adj_list[u]: # выполняем релаксацию - пытаемся улучшить расстояние до найденной вершины
         d[v] = min(d[v], d[u] + w)
    used[u] = True # отмечаем найденную вершину как посещенную
print(*d)
