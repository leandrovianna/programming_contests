def zfunc(s):
    z = [0 for i in range(len(s))]
    l, r = 0, 0
    for i in range(1, len(s)):
        if i <= r:
            z[i] = min(r - i + 1, z[i - l])

        while i + z[i] < len(s) and s[z[i]] == s[i + z[i]]:
            z[i] += 1

        if i + z[i] - 1 > r:
            l, r = i, i + z[i] - 1

    return z


def gen_strings(n, k, s):
    if n == 0:
        yield s
    else:
        for i in range(k):
            ch = chr(ord('A') + i)
            yield from gen_strings(n-1, k, s + ch)


def solver(n, k):
    T = 10**5
    MOD = 10**9 + 7
    count = {}

    ans = 0
    i = 0
    for s in gen_strings(n, k, ''):
        x = max(zfunc(s))
        ans += x % MOD

        if x not in count:
            count[x] = 0
        count[x] += 1

        i += 1
        if i == T:
            break

    print(ans)
    return count


if __name__ == "__main__":
    n, k = map(int, input().split())
    solver(n, k)
