def main():
    n = int(input())
    columns = [int(x) for x in input().split()]

    done = False
    while not done:
        done = True
        for i in range(n-1):
            if columns[i] > columns[i+1]:
                done = False
                x = columns[i] - columns[i+1]
                columns[i] -= x
                columns[i+1] += x

    print(" ".join(map(str, columns)))

if __name__ == "__main__":
    main()
