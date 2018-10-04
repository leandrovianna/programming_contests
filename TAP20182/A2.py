import itertools


def main():
    n = int(input())
    a, op, b, op2, c = input().split()

    for p in itertools.permutations(range(10)):
        j, k, l = 0, 0, 0

        for ch in a:
            j = 10 * j + p[ord(ch) - ord('A')]

        for ch in b:
            k = 10 * k + p[ord(ch) - ord('A')]

        for ch in c:
            l = 10 * l + p[ord(ch) - ord('A')]

        if j + k == l:
            print("{} + {} = {}".format(j, k, l))
            return

    print('No solution possible.')


if __name__ == "__main__":
    main()
