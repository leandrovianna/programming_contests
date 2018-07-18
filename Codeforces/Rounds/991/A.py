"""
Codeforces - If at first you don't succeed... - 991A Div2
"""


def main():
    a, b, c, n = map(int, input().split())
    r = (a - c) + (b - c) + c

    if c <= a and c <= b and r + 1 <= n:
        print(n-r)
    else:
        print(-1)


if __name__ == "__main__":
    main()
