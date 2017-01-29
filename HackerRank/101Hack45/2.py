#!/bin/python3

import sys

n,k = input().strip().split(' ')
n,k = int(n),int(k)
l = []

if k == 2 and n > 2:
    print (-1)
elif n >= k:
    for _ in range(k):
        l.append(1)
    
    if sum(l) < n:
        l[1] += n - sum(l)
    
    edges = 0
    for x in range(1, len(l)):
        edges += l[x-1] * l[x]
        
    print (edges)
else:
    print (-1)
