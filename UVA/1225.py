def count(n):
    cnt = [0 for i in range(10)]
    for i in range(n+1):
        while i > 0:
            cnt[i % 10] += 1
            i //= 10
    return cnt


def main():
    t = int(input())
    for ti in range(t):
        n = int(input())
        cnt = count(n)
        print(' '.join(map(str, cnt)))


if __name__ == "__main__":
    main()
