# UVA - Newspaper - 11340
# input has non-ascii characters
import sys

inp = sys.stdin
out = sys.stdout

n = int(inp.readline())

for ti in range(n):
    k = int(inp.readline())
    price = {}
    for i in range(k):
        ch, v = inp.readline().split()
        price[ch] = int(v)

    ans = 0
    m = int(inp.readline())
    for i in range(m):
        for ch in inp.readline():
            if ch in price:
                ans += price[ch]
    out.write('{:.2f}$\n'.format(ans / 100.0))
