def solve(n, k):
    ans = n
    butts = n
    while butts >= k:
        n = butts // k
        ans += n
        butts = butts % k + n
    return ans


def main():
    while True:
        try:
            n, k = map(int, input().split())
            print(solve(n, k))
        except EOFError:
            break


if __name__ == "__main__":
    main()
