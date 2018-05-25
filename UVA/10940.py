def f(n):
    if n % 2 == 0:
        return n


def main():
    while True:
        n = int(input())
        if n == 0:
            break

        print(f(n))


if __name__ == "__main__":
    main()
