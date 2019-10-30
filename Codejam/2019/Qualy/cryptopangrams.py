from string import ascii_uppercase


def solve(n, l):
    a = [int(x) for x in input().split()]
    b = [(0, 0)] * l
    primes = set()

    for i in range(2, n+1):
        if a[0] % i == 0:
            b[0] = (i, a[0] // i)
            primes.add(i)
            primes.add(a[0] // i)
            break

    for j in range(1, l):
        for p in b[j-1]:
            if a[j] % p == 0:
                b[j] = (p, a[j] // p)
                primes.add(p)
                primes.add(a[j] // p)
                break

    letter = {}
    primes = sorted(list(primes))

    for p, le in zip(primes, ascii_uppercase):
        letter[p] = le

    output = ''
    if b[0][0] != b[1][0]:
        output += letter[b[0][0]]
    else:
        output += letter[b[0][1]]

    for j in range(1, l):
        output += letter[b[j][0]]

    output += letter[b[l-1][1]]

    return output


if __name__ == "__main__":
    t = int(input())
    for ti in range(1, t+1):
        n, l = map(int, input().split())
        print('Case #{}: {}'.format(ti, solve(n, l)))
