def main():
    t = int(input())
    for ti in range(t):
        n, *a = map(int, input().split())
        middle = len(a) // 2
        print("Case {}: {}".format(ti+1, a[middle]))


if __name__ == "__main__":
    main()
