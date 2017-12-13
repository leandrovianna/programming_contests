def main():
    n, h = map(int, input().split())
    a = list(map(int, input().split()))

    answer = 0
    for x in a:
        if x > h:
            answer += 2
        else:
            answer += 1

    print(answer)

if __name__ == "__main__":
    main()
