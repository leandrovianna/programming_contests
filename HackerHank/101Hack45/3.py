#!/bin/python3
#Accepted - 36 points

n = int(input().strip())
a = list(map(int, input().strip().split(' ')))

if n == 1:
    print (a[0] + 1)

a = sorted(a)

for d in range(2, a[1] + 1):
    n = 0
    for i in a:
        if i % d == 0:
            n += 1

    if n == len(a) - 1:
        print (d)
        break

