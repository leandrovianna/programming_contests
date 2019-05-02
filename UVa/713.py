def rev(x):
    y = 0
    while x > 0:
        y *= 10
        y += x % 10
        x //= 10
    return y


def main():
    t = int(input())

    for _ in range(t):
        x, y = map(int, input().split())

        x = rev(x)
        y = rev(y)

        print(rev(x + y))


if __name__ == "__main__":
    main()

