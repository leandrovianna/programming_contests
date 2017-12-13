while True:
    n = int(input())

    if n == 0:
        break

    l = list(range(1, n+1))
    l = map(str, l)

    out = " ".join(l)

    print(out)
