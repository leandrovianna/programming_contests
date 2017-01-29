#!/bin/python3
n = int(input())
p = [int(x) for x in input().split()]

for x in range(1, n+1):
    j = 0
    for i,v in enumerate(p):
        if v == x:
            j = i+1
            break

    for i,v in enumerate(p):
        if v == j:
            print (i+1)
            break

