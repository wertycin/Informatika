def dfs(u):
    used[u] = True
    for v in range(n):
        if a[u][v] == 1 and not used[v]:
            dfs(v)
    order.append(u)
if __name__ == "__main__":
# Read graph:
# a - adj. matrix
# n - number of vertices
    used = [False] * n
    order = [] # Vertex order
    for i in range(n):
        if not used[i]:
            dfs(i)
    print(order[::-1]) # We need to reverse it