def main():
    n = int(input())

    for i in range(n):
        x, y = map(int, input().split('x'))

        for j in range(5, 11):
            if x != y:
                print(x, "x", j, "=", x * j, "&&", y, "x", j, "=", y * j)
            else:
                print(x, "x", j, "=", x * j)

if __name__ == "__main__":
    main()
