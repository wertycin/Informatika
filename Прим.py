if __name__ == "__main__":
    # Считывание графа
    n, m = map(int, input().split())
    adj_list = [set() for _ in range(n)]
    for _ in range(m):
        u, v, w = map(int, input().split())
        adj_list[u].add((v, w))
        adj_list[v].add((u, w))
    S = {0}
    weight = 0
    tree = []
    for _ in range(n-1):
        min_weight = float('inf')
        e = None
        for u in S:
            for v, w in adj_list[u]:
                if v in S:
                    continue
                if w < min_weight:
                    min_weight = w
                    e = (u, v, w)
        S.add(e[1])
        weight += min_weight
        tree.append(e)

    print(weight)
    print(*tree, sep='\n')

