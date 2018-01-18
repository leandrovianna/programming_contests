def main():
    first, second = input().split()

    foo = set()

    for i in range(len(first)):
        for j in range(len(second)):
            foo.add(first[:i+1] + second[:j+1])

    print(min(foo))

if __name__ == "__main__":
    main()
