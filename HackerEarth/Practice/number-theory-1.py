#!/bin/python3
d, x, y = 0, 0, 0

def extendedEuclid(a, b):
	global d
	global x
	global y
	
	if b == 0:
		d = a
		x = 1
		y = 0
	else:
		extendedEuclid(b, a % b)
		x, y = y, x - (a // b) * y

def modInverse(n, m):
	global x
	extendedEuclid(n, m)
	return (x % m + m) % m

if __name__ == '__main__':
	a, b, c, m = list(map(int, input().strip().split()))
	invc = modInverse(c, m)
	res = ((a ** b) % m * invc % m) % m
	print (res)
