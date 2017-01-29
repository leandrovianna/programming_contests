#!/bin/python3
#Accepted!

t1 = 0
t2 = 0
dp = {}

def fib(n):
    if n in dp:
        return dp[n]

    if n == 1:
        return t1
    elif n == 2:
        return t2
    else:
        dp[n] = fib(n-2) + fib(n-1)**2
        return dp[n]

if __name__ == '__main__':
    t1, t2, n = input().split()
    t1 = int(t1)
    t2 = int(t2)
    n = int(n)

    print (fib(n))
