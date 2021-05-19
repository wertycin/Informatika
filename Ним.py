def solve(n, k):
    d = [None] * (n+1)
    d[0] = 0
    for i in range(1, n+1):
        mex = [False] * (n+1)
        for j in range(1, k+1):
            if i - j > -1:
                mex[d[i-j]] = True
        for j in range(n+1):
             if not mex[j]:
                 d[i] = j
                 break
    return d


if __name__ == "__main__":
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    d = solve(max(a), k)
    s = 0
    for e in a:
        s ^= d[e]
    print(s)
