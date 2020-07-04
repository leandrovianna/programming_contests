# URI - Espaço de projeto - 2638
# TLE because of large input (N <= 10^6)
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

def split(text):
    r = []
    curr = ''
    for ch in text:
        if ch == ' ':
            r.append(curr)
            curr = ''
        else:
            curr += ch
    if curr:
        r.append(curr)
    return r


def main():
    input_text = ' '.join(stdin.readlines())
    tokens = split(input_text)

    n = int(tokens[0])

    min_uf = UnionFind(n) # minimum st
    max_uf = UnionFind(n) # maximum st

    edges_by_size = [[] for i in range(201)]
    i, j = 0, 0
    while j+3 < len(tokens):
        u, v, w = int(tokens[j+1]), int(tokens[j+2]), int(tokens[j+3])

        edges_by_size[w].append((u-1, v-1))

        j += 3
        i += 1

    min_cost = 0
    for w in range(1, 201):
        for edge in edges_by_size[w]:
            u, v = edge

            if min_uf.find(u) != min_uf.find(v):
                min_uf.union(u, v)
                min_cost += w

    max_cost = 0
    for w in range(200, 0, -1):
        for edge in edges_by_size[w]:
            u, v = edge

            if max_uf.find(u) != max_uf.find(v):
                max_uf.union(u, v)
                max_cost += w

    stdout.write('{}\n{}\n'.format(max_cost, min_cost))


if __name__ == "__main__":
    main()
