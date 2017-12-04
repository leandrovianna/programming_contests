levels = list(map(int, input().split()))

levels.sort()

ans = abs((levels[3] + levels[0]) - (levels[1] + levels[2]))

print(ans)
