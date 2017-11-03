# Codeforces - Cubes for Masha - 887B
import itertools

def main():
    n = int(input())

    # cubes = [[int(x) for x in input().split()] for _ in range(n)]

    # c1 = [int(x) for x in input().split()]
    # c2 = [int(x) for x in input().split()] if n > 1 else []
    # c3 = [int(x) for x in input().split()] if n > 2 else []

    l7 = [(int(x), i) for i in range(1, n+1) for x in input().split()]

    l7ily = set()
    for p in range(1, n+1):
        for x in itertools.permutations(l7, p):
            count = set()
            s = ""
            for xi in x:
                s += str(xi[0])
                count.add(xi[1])

            if len(count) == p:
                l7ily.add(int(s))
    
    for lah in range(1, 1000):
        if not lah in l7ily:
            print(lah-1)
            return
    else:
        print(999)

if __name__ == "__main__":
    main()
