# Codeforces - Chtholly's request  - 897B
def palgen():
    i = 1
    while True:
        ii = 10 * i
        r = range(i, ii)
        for j in r:
            s = str(j)
            yield s + s[-2::-1]
        for j in r:
            s = str(j)
            yield s + s[::-1]
        i = ii

def main():
    k, p = map(int, input().split())

    ans = 0
    cnt = 0
    
    for num in palgen():
        if len(num) % 2 == 0:
            for j in range(len(num)):
                if num[j] != num[-j-1]:
                    break
            else:
                ans = (ans + int(num) % p) % p
                cnt += 1

                if cnt == k:
                    break

    print(ans)


if __name__ == "__main__":
    main()
