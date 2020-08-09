# UVa - Sewing Buttons with Grandma - 12316
N = 51
fat = [1 for _ in range(N)]
n = [0 for _ in range(N)]
m, k = 0, 0
used = [[0 for j in range(N)] for i in range(N)]
test = 1
dp = [[0 for j in range(N)] for i in range(N)]

def solve(i, r):
    global m, used, test, dp

    if r == 0:
        return fat[m]

    if i == k:
        return fat[m] if r == 0 else 0

    if used[i][r] == test:
        return dp[i][r]
    used[i][r] = test

    dp[i][r] = 0
    for d in range(0, min(r, n[i]) + 1):
        dp[i][r] += solve(i+1, r - d) // fat[d]

    return dp[i][r]

def main():
    global test, m, k, fat

    for i in range(1, N):
        fat[i] = i * fat[i-1]

    while True:
        m, k = map(int, input().split())
        if m == 0 and k == 0:
            break
        for i in range(k):
            n[i] = int(input())
        print('{}'.format(solve(0, m)))
        test += 1


if __name__ == "__main__":
    main()
