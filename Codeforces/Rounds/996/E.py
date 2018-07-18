"""
Codeforces - Leaving the Bar - 996E Div2
"""

import math
from random import shuffle
from random import seed
from time import time


def sumv(v, u):
    return (v[0] + u[0], v[1] + u[1])


def norm(v):
    return math.sqrt(v[0]*v[0] + v[1]*v[1])


def main():
    seed(time())
    n = int(input())
    points = []
    for i in range(n):
        x, y = map(int, input().split())
        points.append(((x, y), i))

    LIM = 1.5 * 10**6
    v = (0, 0)

    c = []

    for i in range(3):
        shuffle(points)

        for p in points:
            n1 = norm(sumv(v, p[0]))

            # q = -p
            q = (-p[0][0], -p[0][1])
            n2 = norm(sumv(v, q))

            if n1 < n2:
                c.append(1)
            else:
                p = (q, p[1])
                c.append(-1)

            v = sumv(v, p[0])

        if not norm(v) > LIM:
            break
    
    points.sort(key=lambda x: x[1])
    print(' '.join(map(str, c)))


if __name__ == "__main__":
    main()
