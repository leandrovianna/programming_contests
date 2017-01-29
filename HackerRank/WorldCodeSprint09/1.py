#!/bin/python3
#Accepted - 10 Points

n = int(input())

for _ in range(n):
    g = int(input())
    
    r = (g + 2) % 5

    if g < 38:
        print (g)
    elif r < 3:
        print (g + 2 - r)
    else:
        print (g)
