# URI - Componentes Conexos - 1082
from sys import stdin, stdout

class UnionFind:
    def __init__(self, n):
        self.parent = [i for i in range(n)]
        self.size = [1 for i in range(n)]

    def find(self, i):
        if self.parent[i] == i:
            return i

        self.parent[i] = self.find(self.parent[i])
        return self.parent[i]

    def union(self, i, j):
        i = self.find(i)
        j = self.find(j)

        if i == j:
            return

        if self.size[i] >= self.size[j]:
            self.parent[j] = i
            self.size[i] += self.size[j]
        else:
            self.parent[i] = j
            self.size[j] += self.size[i]


def main():
    n = int(stdin.readline())

    for ti in range(1, n+1):
        v, e = map(int, stdin.readline().split())
        uf = UnionFind(v)
        ans = [[] for i in range(v)]

        for i in range(e):
            a, b = stdin.readline().split()
            a = ord(a) - ord('a')
            b = ord(b) - ord('a')
            uf.union(a, b)

        printed = [False for i in range(v)]
        comp = [uf.find(i) for i in range(v)]

        size = 0
        stdout.write('Case #{}:\n'.format(ti))
        for i in range(v):
            if printed[i]:
                continue

            for j in range(v):
                if comp[j] == comp[i]:
                    stdout.write('{},'.format(chr(ord('a') + j)))
                    printed[j] = True
            stdout.write('\n')
            size += 1
        stdout.write('{} connected components\n\n'.format(size))


if __name__ == "__main__":
    main()
