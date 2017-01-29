#!/bin/python3
#Accepted - 20 points

if __name__ == "__main__":
    s = input()
    n = int(input())

    u = set()

    seq = 0
    for i in range(len(s)):
        c = ord(s[i]) - ord('a') + 1

        u.add(c)

        if i != 0 and s[i-1] == s[i]:
            seq += c
            u.add(seq)
        else:
            seq = c

    for _ in range(n):
        x = int(input())

        if (x in u):
            print ('Yes')
        else:
            print ('No')
