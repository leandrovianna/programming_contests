def main():
    n = int(input())
    a = [x for x in map(int, input().split())]

    ans = 10**10
    ansi = n

    for i in range(len(a)):
        x = a[i]
        if a[i] % n <= i:
            x += i - a[i] % n
        else:
            x += n - (a[i] % n - i)

        if ans > x:
            ans = x
            ansi = i

    print(ansi+1)


if __name__ == "__main__":
    main()
