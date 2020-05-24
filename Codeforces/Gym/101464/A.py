"""
Codeforces - Time Table
"""

with open('a.in', 'r') as f:
    while True:
        try:
            line = f.readline()
            if line == '':
                break

            m, n = map(int, line.split())

            p = [0 for i in range(m)]

            a = []
            for i in range(n):
                q = list(map(int, f.readline().split()))
                a.append(q)

            for j in range(m):
                p[j] = a[0][j]
                for i in range(1, n):
                    p[j] *= a[i][j]

            answer = p[0]
            idx = 0
            for j in range(m):
                if p[j] >= answer:
                    answer = p[j]
                    idx = j

            print(idx+1)
        except EOFError:
            break
