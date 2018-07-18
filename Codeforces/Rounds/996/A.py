def main():
    n = int(input())
    ans = 0

    for bill in [100, 20, 10, 5, 1]:
        if n >= bill:
            count = n // bill
            ans += count
            n -= bill * count

    print(ans)


if __name__ == "__main__":
    main()
