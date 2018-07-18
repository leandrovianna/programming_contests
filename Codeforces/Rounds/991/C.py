"""
Codeforces - Candies - 991C Div2
"""
def main():
    n = int(input())

    low = 1
    high = n
    ans = n

    while low <= high:
        k = (low + high) // 2

        count = 0
        m = n
        while m >= k:
            m -= k
            count += k

            if m > 0:
                m -= m // 10

        count += m

        if count * 2 >= n:
            ans = k
            high = k-1
        else:
            low = k+1

    print(ans)

if __name__ == "__main__":
    main()
