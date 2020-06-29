# Codeforces Gym - Resistors in Parallel - 102028E
from math import gcd


def notprime(prime):
    i = 2
    while i*i <= prime:
        if prime % i == 0:
            return True
        i += 1
    return False


def main():
    t = int(input())
    for i in range(t):
        n = int(input())
        p, q = 1, 1
        prime = 2
        while p * prime <= n:
            q *= (prime+1)
            p *= prime
            prime += 1
            while notprime(prime):
                prime += 1

        gc = gcd(p, q)
        print('{}/{}'.format(p // gc, q // gc))


if __name__ == "__main__":
    main()
