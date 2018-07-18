"""
Codeforces - Getting a A - 991B Div2
"""
def myround(x):
    if x % 10 >= 5:
        x += 10 - x % 10
    return x


def main():
    n = int(input())
    a = map(int, input().split())
    a = sorted(a)
    avg = (10 * sum(a)) // len(a)

    ans = 0
    for i in range(len(a)):
        if myround(avg) == 50:
            break

        a[i] = 5
        ans += 1
        avg = (10 * sum(a)) // len(a)

    print(ans)


if __name__ == "__main__":
    main()
