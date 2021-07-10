primes = []
def sieve(n):
    global primes

    notprime = [False for _ in range(n+1)]
    notprime[0] = notprime[1] = True

    for i in range(2, n+1):
        if not notprime[i]:
            primes.append(i)
            for j in range(i+i, n+1, i):
                notprime[j] = True


N = 1010
dp = [[-1 for _ in range(N)] for __ in range(N)]
def solve(d, p):
    global dp

    if d == 1:
        return 1

    if dp[d][p] != -1:
        return dp[d][p]

    for e in range(2, d+1):
        if d % e == 0:
            x = primes[p]**(e-1) * solve(d // e, p + 1)
            if dp[d][p] == -1:
                dp[d][p] = x
            else:
                dp[d][p] = min(dp[d][p], x)

    return dp[d][p]


def main():
    k = int(input())
    sieve(k)

    ans = solve(k, 0)

    print(ans)


if __name__ == '__main__':
    main()
