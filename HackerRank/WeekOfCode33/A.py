n = int(input())

v1 = [(int(x), i) for x, i in zip(input().strip().split(' '), range(n))]
v2 = [(int(x), i) for x, i in zip(input().strip().split(' '), range(n))]

v1.sort()
v2.sort()

if v1[0][1] == v2[0][1]:
    print (min(v1[0][0] + v2[1][0], v1[1][0] + v2[0][0]))
else:
    print (v1[0][0] + v2[0][0])

