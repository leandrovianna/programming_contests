# Codeforces - Boredom - 455A Div1

def main():
    N = 10**5+1
    n = int(input())

    cnt = {x:0 for x in range(N)}

    for x in map(int, input().split()):
        cnt[x] += 1

    memo = {
            0 : 0,
            1 : cnt[1]
            }

    for i in range(2,N):
        memo[i] = max(memo[i-1], memo[i-2] + cnt[i] * i)

    print(memo[N-1])

if __name__ == "__main__":
    main()
