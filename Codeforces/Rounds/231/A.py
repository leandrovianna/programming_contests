def main():
    n = int(input())
    answer = 0
    for _ in range(n):
        l = list(map(int, input().split()))
        if l.count(1) > 1:
            answer += 1

    print(answer)

if __name__ == "__main__":
    main()
