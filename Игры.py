if __name__ == "__main__":
    # Считывание графа
    n, k = map(int, input().split())
    d = [None] * (n+1)
    d[0] = 'L'
    for i in range(1, n+1):
        for j in range(1, k+1):
            if i - j > -1 and d[i-j] == 'L':
                d[i] = 'W'
                break
        if d[i] is None:
            d[i] = 'L'
    print(d)
