SQRT2 = 1.4142135623730951

def f(n):
    if n == 1:
        return 0.0

    a = 2.0 * (n - 1) + n
    for i in range(3, n):
        a += 2 * (i - 2) * SQRT2 + 1
    if n > 2:
        a += (n - 2) * SQRT2 + 1
    return a


def main():
    t = int(input())
    for ti in range(t):
        input()  # read blank line
        n = int(input())
        print('{:.3f}'.format(f(n)))
        if ti < t-1:
            print('')


if __name__ == "__main__":
    main()
