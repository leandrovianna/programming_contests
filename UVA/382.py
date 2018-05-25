def divisors(n):
    i = 1
    while i * i <= n:
        if n % i == 0:
            yield i
            if n // i != i:
                yield n // i
        i += 1


def sum_divisors(n):
    return sum(divisors(n)) - n


def main():
    FORMAT = '{:5}  {}'
    print('PERFECTION OUTPUT')

    while True:
        try:
            a = map(int, input().split())
            for i in a:
                if i == 0:
                    break
                sum_div = sum_divisors(i)
                if sum_div == i:
                    print(FORMAT.format(i, 'PERFECT'))
                elif sum_div < i:
                    print(FORMAT.format(i, 'DEFICIENT'))
                else:
                    print(FORMAT.format(i, 'ABUNDANT'))
        except EOFError:
            break
    print('END OF OUTPUT')


if __name__ == "__main__":
    main()
