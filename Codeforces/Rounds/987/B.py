mod = 10**9 + 7
def exp(a, b):
    ans = 1
    while b > 0:
        if b & 1 == 1:
            ans = (ans * a) % mod 

        a = (a * a) % mod
        b >>= 1

    return ans


def main():
    n, m = map(int, input().split())
    
    x = exp(n, m)
    y = exp(m, n)

    if x < y:
        print('<')
    elif x > y:
        print('>')
    else:
        print('=')


if __name__ == "__main__":
    main()
