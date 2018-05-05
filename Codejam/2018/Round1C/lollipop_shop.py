# Codejam 2018 - Round 1C - Lollipop Shop
from random import uniform
from random import seed
from time import time


def solve(n):
    lolli = set(range(n))
    prob = [0 for i in range(n)]

    for i in range(n):
        d, *a = map(int, input().split())
        if d == -1:
            return False  # deu merda

        a.sort(key=lambda x: prob[x])

        sold = False
        for x in a:
            if not sold and x in lolli:
                lolli.remove(x)
                print(x, flush=True)
                sold = True

            prob[x] += 1

        if not sold:
            print(-1, flush=True)

    return True


def main():
    seed(time())

    t = int(input())
    for ti in range(t):
        n = int(input())
        if not solve(n):
            return None


if __name__ == "__main__":
    main()
