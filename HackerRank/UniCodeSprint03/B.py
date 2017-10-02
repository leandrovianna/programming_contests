from collections import deque

I = [-1, -1, -1, +0, +0, +1, +1, +1]
J = [-1, +0, +1, -1, +1, -1, +0, +1]

ans = 0

def bfs(grid, i, j, w):
    global ans
    q = deque([(i,j,w)])

    vis = [[False for j in l] for l in grid] 
    vis[i][j] = True

    while (len(q) > 0):
        ui, uj, uw = q.popleft()

        ans = max(ans, grid[ui][uj])

        # print ("({},{},{})".format(ui, uj, uw))

        if uw == 1:
            continue

        for x in zip(I, J):
            vi = ui + x[0]
            vj = uj + x[1]

            if (0 <= vi and vi < len(grid)
                    and 0 <= vj and vj < len(grid[i])
                    and not vis[vi][vj]):
                vis[vi][vj] = True
                grid[vi][vj] = grid[vi][vj] + uw - 1
                q.append( (vi, vj, uw-1) )
                # print (vi, vj, grid[vi][vj])

if __name__ == '__main__':
    n = int(input())
    m = int(input())
    v = [[int(x) for x in input().split()] for _ in range(m)]

    grid = [[0 for j in range(n)] for i in range(n)] 

    for vi in v:
        x = vi[0]
        y = vi[1]
        grid[x][y] = grid[x][y] + vi[2]

        bfs(grid, x, y, vi[2])

    # for i in range(len(grid)):
    #     print(grid[i])

    print (ans)

