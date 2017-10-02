import sys

# up - right - down - left
I = [-1, +0, +1, +0]
J = [+0, +1, +0, -1]

Z = [ (-1,0), (0,1), (0, -1), (1, 0) ]

sys.setrecursionlimit(10000)

def dfs(i, j, d, time):

    vis[i][j] = True
    grid[i][j] = time

    for x in Z:
        vi = i + x[0]
        vj = j + x[1]

        if (0 <= vi and vi < len(grid)
                and 0 <= vj and vj < len(grid[i])
                and not vis[vi][vj]):
            vis[vi][vj] = True
            dfs(vi, vj, d, time+1)

if __name__ == "__main__":
    global grid, vis

    n = int(input())
    d = input()
    x, y = input().split()
    x = int(x)
    y = int(y)

    if d == 'e':
        Z[0], Z[1] = Z[1], Z[0]
        Z[2], Z[3] = Z[3], Z[2]

    if d == 'w':
        Z[0], Z[2] = Z[2], Z[0]
        Z[1], Z[3] = Z[3], Z[1]

    if d == 's':
        Z[0], Z[3] = Z[3], Z[0]

    grid = [[0 for _ in range(n)] for _ in range(n)]
    vis = [[False for _ in range(n)] for _ in range(n)]

    dfs(x, y, d, 1)

    for l in grid:
        print (' '.join(map(str, l)))


